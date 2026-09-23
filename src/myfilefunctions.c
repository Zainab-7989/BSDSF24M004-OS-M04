#define _GNU_SOURCE
#include "../include/myfilefunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (file == NULL || lines == NULL || words == NULL || chars == NULL) {
        return 1; 
    }

    *lines = 0;
    *words = 0;
    *chars = 0;

    int ch;
    int in_word = 0;

    while ((ch = fgetc(file)) != EOF) {
        (*chars)++;
        if (ch == '\n') {
            (*lines)++;
        }
        if (isspace(ch)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            (*words)++;
        }
    }
    return 0; 
}

int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (fp == NULL || search_str == NULL || matches == NULL) {
        return 1; 
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;
    char** match_list = NULL;

    rewind(fp);

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, search_str) != NULL) {
            match_list = realloc(match_list, sizeof(char*) * (count + 1));
            match_list[count] = strdup(line);
            count++;
        }
    }

    free(line);
    *matches = match_list;
    return count; 
}