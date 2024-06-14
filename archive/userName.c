#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 50
#define MAX_USERNAMES 1000

void generateUsernames(char names[MAX_NAMES][MAX_NAME_LENGTH], int name_count, char usernames[MAX_USERNAMES][MAX_NAME_LENGTH], int *username_count) {
    *username_count = 0;

    for (int i = 0; i < name_count; i++) {
        char first[MAX_NAME_LENGTH], last[MAX_NAME_LENGTH];
        sscanf(names[i], "%s %s", first, last);

        if (first == NULL || last == NULL) {
            continue;
        }

        sprintf(usernames[(*username_count)++], "%s", first);
        sprintf(usernames[(*username_count)++], "%s", last);
        sprintf(usernames[(*username_count)++], "%s%s", first, last);
        sprintf(usernames[(*username_count)++], "%s.%s", first, last);
        sprintf(usernames[(*username_count)++], "%c%s", first[0], last);
        sprintf(usernames[(*username_count)++], "%s%c", first, last[0]);
        sprintf(usernames[(*username_count)++], "%c.%s", first[0], last);
        sprintf(usernames[(*username_count)++], "%s.%c", first, last[0]);
        sprintf(usernames[(*username_count)++], "%s_%s", first, last);
        sprintf(usernames[(*username_count)++], "%c_%s", first[0], last);
        sprintf(usernames[(*username_count)++], "%s_%c", first, last[0]);
    }
}

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

int main(int argc, char *argv[]) {
    char names[MAX_NAMES][MAX_NAME_LENGTH];
    char usernames[MAX_USERNAMES][MAX_NAME_LENGTH];
    int name_count, username_count;

    if (argc > 1) {
        if (argc == 2) {
            // Read names from provided file with both first and last names
            readNamesFromFile(argv[1], names, &name_count);
        } else if (argc == 3) {
            // Read names from separate first and last name files
            createUsernamesFromCommonNames(argv[1], argv[2], names, &name_count);
        } else {
            printf("Usage: %s <name_file> or %s <first_name_file> <last_name_file>\n", argv[0], argv[0]);
            return 1;
        }
    } else {
        // Menu option to create names
        printf("No file provided. Do you want to create usernames based on common names? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            char first_names_file[MAX_NAME_LENGTH], last_names_file[MAX_NAME_LENGTH];
            printf("Enter the file name for common first names: ");
            scanf("%s", first_names_file);
            printf("Enter the file name for common last names: ");
            scanf("%s", last_names_file);
            createUsernamesFromCommonNames(first_names_file, last_names_file, names, &name_count);
        } else {
            printf("No names to process. Exiting.\n");
            return 0;
        }
    }

    generateUsernames(names, name_count, usernames, &username_count);

    for (int i = 0; i < username_count; i++) {
        printf("%s\n", usernames[i]);
    }

    return 0;
}
