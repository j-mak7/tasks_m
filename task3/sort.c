#include <string.h>
#include <stdlib.h>

int plain(const void* a, const void* b) {
        const char* sa = *(const char**)a;
        const char* sb = *(const char**)b;
        return strcmp(sa, sb);
}