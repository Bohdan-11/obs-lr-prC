#ifndef HTMLUTILS_H
#define HTMLUTILS_H
#include <stddef.h>
int extract_title(const char *html, char *out, size_t out_size);
// возможно, другие функции: extract_links, и т.д.
#endif