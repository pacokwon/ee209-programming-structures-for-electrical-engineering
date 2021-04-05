#include <assert.h> /* to use assert() */
#include <stdio.h>
#include "str.h"

/* Your task is:
   1. Rewrite the body of "Part 1" functions - remove the current
   body that simply calls the corresponding C standard library
   function.
   2. Write appropriate comment per each function
   */

/* Part 1 */
/*------------------------------------------------------------------------*/
size_t StrGetLength(const char *pcSrc) {
    const char *pcEnd;
    assert(pcSrc); /* NULL address, 0, and FALSE are identical. */
    pcEnd = pcSrc;

    while (*pcEnd) /* null character and FALSE are identical. */
        pcEnd++;

    return (size_t)(pcEnd - pcSrc);
}

/*------------------------------------------------------------------------*/
char *StrCopy(char *pcDest, const char *pcSrc) {
    const char *srcCursor;
    char *destCursor;

    srcCursor = pcSrc;
    destCursor = pcDest;

    while (*srcCursor)
        *destCursor = *srcCursor;
    *destCursor = '\0';

    return pcDest;
}

/*------------------------------------------------------------------------*/
int StrCompare(const char *s1, const char *s2) {
    const char *s1Cursor, *s2Cursor;

    s1Cursor = s1;
    s2Cursor = s2;

    while (*s1Cursor != '\0' && *s2Cursor != '\0') {
        if (*s1Cursor > *s2Cursor)
            return 1;
        else if (*s1Cursor < *s2Cursor)
            return -1;

        s1Cursor++;
        s2Cursor++;
    }

    if (*s1Cursor == *s2Cursor)
        return 0;
    else if (*s1Cursor > *s2Cursor)
        return 1;
    else
        return -1;
}
/*------------------------------------------------------------------------*/
char *StrFindChr(const char *pcHaystack, int c) {
    char *cursor = (char *) pcHaystack;
    while (*cursor) {
        if (*cursor == c)
            return cursor;
        cursor++;
    }

    return *cursor == c ? cursor : NULL;
}
/*------------------------------------------------------------------------*/
char *StrFindStr(const char *pcHaystack, const char *pcNeedle) {
    const char *cursor, *haystackCursor, *needleCursor;
    int isEqual;

    cursor = pcHaystack;
    while (*cursor) {
        // equal by default
        isEqual = 1;

        haystackCursor = cursor;
        needleCursor = pcNeedle;
        while (*needleCursor) {
            if (*haystackCursor != *needleCursor) {
                isEqual = 0;
                break;
            }

            needleCursor++;
            haystackCursor++;
        }

        if (isEqual)
            return (char *) cursor;

        cursor++;
    }

    return NULL;
}

/*------------------------------------------------------------------------*/
char *StrConcat(char *pcDest, const char *pcSrc) {
    char *cursor;
    const char *srcCursor;

    cursor = pcDest;

    // move to NULL character
    while (*cursor)
        cursor++;

    // from here, cursor points to NULL
    srcCursor = pcSrc;
    while (*srcCursor) {
        *cursor = *srcCursor;
        srcCursor++;
    }
    *cursor = '\0';

    return pcDest;
}

/*------------------------------------------------------------------------*/
long int StrToLong(const char *nptr, char **endptr, int base) {
    long sum;
    const char *cursor;

    /* handle only when base is 10 */
    if (base != 10) return 0;

    sum = 0L;
    cursor = nptr;

    while (*cursor) {
        if (!('0' <= *cursor && *cursor <= '9'))
            break;

        sum = base * sum + (*cursor - '0');
        cursor++;
    }

    *endptr = (char *) cursor;
    return sum;
}
