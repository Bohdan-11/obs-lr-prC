#include "htmlutils.h"
#include <string.h>
int extract_title(const char *html, char *out, size_t out_size) {
    const char *tag_start = "<title>";
    const char *tag_end = "</title>";
    char *pos1 = strstr(html, tag_start);
    if (!pos1) return -1;
    pos1 += strlen(tag_start);
    char *pos2 = strstr(pos1, tag_end);
    if (!pos2) return -1;
    size_t title_len = pos2 - pos1;
    if (title_len >= out_size) title_len = out_size - 1;
    memcpy(out, pos1, title_len);
    out[title_len] = '\0';
    return 0;
}
