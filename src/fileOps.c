#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileOps.h"

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 50

void readNamesFromFile(char *filename, char names[MAX_NAMES][MAX_NAME_LENGTH], int *name_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *name_count = 0;
    while (fgets(names[*name_count], MAX_NAME_LENGTH, file) && *name_count < MAX_NAMES) {
        names[*name_count][strcspn(names[*name_count], "\n")] = '\0';  // Remove newline character
        (*name_count)++;
    }

    fclose(file);
}

void createUsernamesFromCommonNames(char *first_names_file, char *last_names_file, char names[MAX_NAMES][MAX_NAME_LENGTH], int *name_count) {
    char first_names[MAX_NAMES][MAX_NAME_LENGTH];
    char last_names[MAX_NAMES][MAX_NAME_LENGTH];
    int first_name_count, last_name_count;

    readNamesFromFile(first_names_file, first_names, &first_name_count);
    readNamesFromFile(last_names_file, last_names, &last_name_count);

    *name_count = 0;
    for (int i = 0; i < first_name_count && *name_count < MAX_NAMES; i++) {
        for (int j = 0; j < last_name_count && *name_count < MAX_NAMES; j++) {
            sprintf(names[(*name_count)++], "%s %s", first_names[i], last_names[j]);
        }
    }
}
