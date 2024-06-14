#include <stdio.h>
#include <stdlib.h>
#include "fileOps.h"
#include "userNameGen.h"

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 50
#define MAX_USERNAMES 1000

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
