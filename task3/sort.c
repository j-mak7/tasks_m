#include <string.h>
#include <stdlib.h>

int plain(const void* a, const void* b) {
	const char* sa = *(const char**)a;
	const char* sb = *(const char**)b;
	return strcmp(sa, sb);
}

int lex(const void* a, const void* b) {
	return strcasecmp(*(const char**)a, *(const char**)b);
}

int rplain(const void* a, const void* b) {
	return -strcmp(*(const char**)a, *(const char**)b);
}

int rlex(const void* a, const void* b) {
	return -strcasecmp(*(const char**)a, *(const char**)b);
}