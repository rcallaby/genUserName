#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 50

void readNamesFromFile(char *filename, char names[MAX_NAMES][MAX_NAME_LENGTH], int *name_count);
void createUsernamesFromCommonNames(char *first_names_file, char *last_names_file, char names[MAX_NAMES][MAX_NAME_LENGTH], int *name_count);

#endif
