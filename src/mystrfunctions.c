#include "../include/mystrfunctions.h"
#include <stddef.h>


int mystrlen(const char* s) {
    if (s == NULL) return 0;
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int mystrcpy(char* dest, const char* src) {
    if (dest == NULL || src == NULL) return -1;
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return 0;
}

int mystrncpy(char* dest, const char* src, int n) {
    if (dest == NULL || src == NULL) return -1;
    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return 0;
}

int mystrcat(char* dest, const char* src) {
    if (dest == NULL || src == NULL) return -1;
    int i = 0;
    while (dest[i] != '\0') {
        i++;
    }
    int j = 0;
    while (src[j] != '\0') {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return 0;
}