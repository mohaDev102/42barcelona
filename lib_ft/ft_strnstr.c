#include <stddef.h>

char *strnstr(const char *haystack, const char *needle, size_t len) {
    if (*needle == '\0') {
        return (char *)haystack;
    }

    while (*haystack != '\0' && len > 0) {
        if (*haystack == *needle) {
            const char *h = haystack;
            const char *n = needle;

            while (*n != '\0' && *h == *n && len > 0) {
                h++;
                n++;
                len--;
            }

            if (*n == '\0') {
                return (char *)haystack;
            }
        }

        haystack++;
        len--;
    }

    return NULL;
}
