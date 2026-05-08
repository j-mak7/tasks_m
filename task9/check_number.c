#include <stdlib.h>
#include "check_number.h"

bool is_number(char *s) {
	if (s == NULL || *s == '\0') {
		return false;
	}
	if (*s == '-') {
		s++;
	}
    	if (*s == '\0') {
		return false;
	}
    	while (*s) {
        	if (*s < '0' || *s > '9') {
			return false;
		}
        	s++;
    	}
	return true;
}

