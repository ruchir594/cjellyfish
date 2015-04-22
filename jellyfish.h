#ifndef _JELLYFISH_H_
#define _JELLYFISH_H_

#include <stdbool.h>
#include <stdlib.h>

#if CJELLYFISH_PYTHON
#include <Python.h>
#define JFISH_UNICODE Py_UNICODE
#endif

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

double jaro_winkler(const char *str1, const char *str2, bool long_tolerance);
double jaro_distance(const char *str1, const char *str2);

size_t hamming_distance(const char *str1, const char *str2);

int levenshtein_distance(const char *str1, const char *str2);

int damerau_levenshtein_distance(
        JFISH_UNICODE *str1, JFISH_UNICODE *str2, size_t len1, size_t len2);

char* soundex(const char *str);

char* metaphone(const char *str);

JFISH_UNICODE *nysiis(const JFISH_UNICODE *str, int len);

JFISH_UNICODE* match_rating_codex(const JFISH_UNICODE *str, size_t len);
int match_rating_comparison(const JFISH_UNICODE *str1, size_t len1, const JFISH_UNICODE *str2, size_t len2);

struct stemmer;
extern struct stemmer * create_stemmer(void);
extern void free_stemmer(struct stemmer * z);
extern int stem(struct stemmer * z, char * b, int k);

#endif
