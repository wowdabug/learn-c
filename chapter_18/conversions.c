#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>

bool string_to_int(char *str, int *result) {
    char *str_end;
    int value = strtol(str, &str_end, 10);

    if (str_end == str ||
        *str_end != '\0' ||
        errno == ERANGE ||
        value < INT_MIN ||
        value > INT_MAX
    ) {
        return false;
    }

    *result = (int)value;
    return true;
}
