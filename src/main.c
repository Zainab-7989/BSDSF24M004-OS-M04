#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");
    
    char dest[50] = "Hello";
    char src[] = " World!";
    
    printf("1. mystrlen(\"Hello\"): %d\n", mystrlen(dest));
    
    mystrcat(dest, src);
    printf("2. After mystrcat: %s\n", dest);
    
    char copied[50];
    mystrcpy(copied, dest);
    printf("3. After mystrcpy: %s\n", copied);

    char ncpied[20] = "Initial";
    mystrncpy(ncpied, "Systems", 4);
    ncpied[4] = '\0'; 
    printf("4. After mystrncpy (copying 4 chars): %s\n", ncpied);


    printf("\n--- Testing File Functions ---\n");
    
    FILE* f = fopen("test.txt", "w");
    if (f != NULL) {
        fprintf(f, "Operating Systems Assignment\n");
        fprintf(f, "Testing file functions like wordCount and mygrep.\n");
        fclose(f);
    }

    f = fopen("test.txt", "r");
    int lines = 0, words = 0, chars = 0;
    if (f != NULL) {
        if (wordCount(f, &lines, &words, &chars) == 0) {
            printf("wordCount -> Lines: %d, Words: %d, Chars: %d\n", lines, words, chars);
        }
        fclose(f);
    }

    f = fopen("test.txt", "r");
    char** matches = NULL;
    if (f != NULL) {
        int match_count = mygrep(f, "test", &matches);
        printf("mygrep matches found: %d\n", match_count);
        for (int i = 0; i < match_count; i++) {
            printf("  -> %s", matches[i]);
            free(matches[i]); 
        }
        free(matches); 
        fclose(f);
    }

    return 0;
}