#include "htmlutils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Если определено USE_CURL, будем использовать libcurl для скачивания
#ifdef USE_CURL
#include <curl/curl.h>

struct Buffer { char *data; size_t size; };
size_t write_cb(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total = size * nmemb;
    struct Buffer *buf = (struct Buffer*) userp;
    char *ptr = realloc(buf->data, buf->size + total + 1);
    if(!ptr) return 0;
    buf->data = ptr;
    memcpy(&(buf->data[buf->size]), contents, total);
    buf->size += total;
    buf->data[buf->size] = '\0';
    return total;
}
char *download_page(const char *url) {
    CURL *curl = curl_easy_init();
    if(!curl) return NULL;
    struct Buffer buf = { .data = malloc(1), .size = 0 };
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buf);
    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    if(res != CURLE_OK) {
        free(buf.data);
        return NULL;
    }
    return buf.data;
}
#endif
int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <file_or_url>\n", argv[0]);
        return 1;
    }
    char *html_content = NULL;
    // Проверим, начинается ли аргумент с "http://"
    if(strncmp(argv[1], "http://", 7) == 0 || strncmp(argv[1], "https://", 8) == 0) {
        #ifdef USE_CURL
        html_content = download_page(argv[1]);
        if(!html_content) {
            fprintf(stderr, "Failed to download %s\n", argv[1]);
            return 1;
        }
        #else
        fprintf(stderr, "This program was built without libcurl support.\n");
        return 1;
        #endif
    } 
    else {
        // читаем локальный файл
        FILE *f = fopen(argv[1], "r");
        if(!f) { perror("fopen"); return 1; }
        fseek(f, 0, SEEK_END);
        long size = ftell(f);
        fseek(f, 0, SEEK_SET);
        html_content = malloc(size + 1);
        if(html_content) {
            fread(html_content, 1, size, f);
            html_content[size] = '\0';
        }
        fclose(f);
    }
    if(!html_content) {
        fprintf(stderr, "Could not load content.\n");
        return 1;
    }
    char title[256];
    if(extract_title(html_content, title, sizeof(title)) == 0) {
        printf("Title: %s\n", title);
    } else {
        printf("Title tag not found.\n");
    }
    free(html_content);
    return 0;
}
