#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "userNameGen.h"

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 50
#define MAX_USERNAMES 1000

void generateUsernames(char names[MAX_NAMES][MAX_NAME_LENGTH], int name_count, char usernames[MAX_USERNAMES][MAX_NAME_LENGTH], long *username_count) {
    *username_count = 0;
    
    // Get the current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char date[9];
    sprintf(date, "%04d%02d%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    for (int i = 0; i < name_count; i++) {
        char first[MAX_NAME_LENGTH], last[MAX_NAME_LENGTH];
        sscanf(names[i], "%s %s", first, last);

        if (first == NULL || last == NULL) {
            continue;
        }

        char first_upper[MAX_NAME_LENGTH], last_upper[MAX_NAME_LENGTH];
        char first_lower[MAX_NAME_LENGTH], last_lower[MAX_NAME_LENGTH];

        // Convert to uppercase
        for (int j = 0; j < strlen(first); j++) {
            first_upper[j] = toupper(first[j]);
            first_lower[j] = tolower(first[j]);
        }
        first_upper[strlen(first)] = '\0';
        first_lower[strlen(first)] = '\0';

        for (int j = 0; j < strlen(last); j++) {
            last_upper[j] = toupper(last[j]);
            last_lower[j] = tolower(last[j]);
        }
        last_upper[strlen(last)] = '\0';
        last_lower[strlen(last)] = '\0';

        // Generate usernames
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

        sprintf(usernames[(*username_count)++], "%s%s", first, date);
        sprintf(usernames[(*username_count)++], "%s%s", last, date);
        sprintf(usernames[(*username_count)++], "%s%s%s", first, last, date);
        sprintf(usernames[(*username_count)++], "%s.%s%s", first, last, date);
        sprintf(usernames[(*username_count)++], "%c%s%s", first[0], last, date);
        sprintf(usernames[(*username_count)++], "%s%c%s", first, last[0], date);
        sprintf(usernames[(*username_count)++], "%c.%s%s", first[0], last, date);
        sprintf(usernames[(*username_count)++], "%s.%c%s", first, last[0], date);
        sprintf(usernames[(*username_count)++], "%s_%s%s", first, last, date);
        sprintf(usernames[(*username_count)++], "%c_%s%s", first[0], last, date);
        sprintf(usernames[(*username_count)++], "%s_%c%s", first, last[0], date);

        sprintf(usernames[(*username_count)++], "%s", first_upper);
        sprintf(usernames[(*username_count)++], "%s", last_upper);
        sprintf(usernames[(*username_count)++], "%s%s", first_upper, last_upper);
        sprintf(usernames[(*username_count)++], "%s.%s", first_upper, last_upper);
        sprintf(usernames[(*username_count)++], "%c%s", first_upper[0], last_upper);
        sprintf(usernames[(*username_count)++], "%s%c", first_upper, last_upper[0]);
        sprintf(usernames[(*username_count)++], "%c.%s", first_upper[0], last_upper);
        sprintf(usernames[(*username_count)++], "%s.%c", first_upper, last_upper[0]);
        sprintf(usernames[(*username_count)++], "%s_%s", first_upper, last_upper);
        sprintf(usernames[(*username_count)++], "%c_%s", first_upper[0], last_upper);
        sprintf(usernames[(*username_count)++], "%s_%c", first_upper, last_upper[0]);

        sprintf(usernames[(*username_count)++], "%s%s", first_upper, date);
        sprintf(usernames[(*username_count)++], "%s%s", last_upper, date);
        sprintf(usernames[(*username_count)++], "%s%s%s", first_upper, last_upper, date);
        sprintf(usernames[(*username_count)++], "%s.%s%s", first_upper, last_upper, date);
        sprintf(usernames[(*username_count)++], "%c%s%s", first_upper[0], last_upper, date);
        sprintf(usernames[(*username_count)++], "%s%c%s", first_upper, last_upper[0], date);
        sprintf(usernames[(*username_count)++], "%c.%s%s", first_upper[0], last_upper, date);
        sprintf(usernames[(*username_count)++], "%s.%c%s", first_upper, last_upper[0], date);
        sprintf(usernames[(*username_count)++], "%s_%s%s", first_upper, last_upper, date);
        sprintf(usernames[(*username_count)++], "%c_%s%s", first_upper[0], last_upper, date);
        sprintf(usernames[(*username_count)++], "%s_%c%s", first_upper, last_upper[0], date);

        sprintf(usernames[(*username_count)++], "%s", first_lower);
        sprintf(usernames[(*username_count)++], "%s", last_lower);
        sprintf(usernames[(*username_count)++], "%s%s", first_lower, last_lower);
        sprintf(usernames[(*username_count)++], "%s.%s", first_lower, last_lower);
        sprintf(usernames[(*username_count)++], "%c%s", first_lower[0], last_lower);
        sprintf(usernames[(*username_count)++], "%s%c", first_lower, last_lower[0]);
        sprintf(usernames[(*username_count)++], "%c.%s", first_lower[0], last_lower);
        sprintf(usernames[(*username_count)++], "%s.%c", first_lower, last_lower[0]);
        sprintf(usernames[(*username_count)++], "%s_%s", first_lower, last_lower);
        sprintf(usernames[(*username_count)++], "%c_%s", first_lower[0], last_lower);
        sprintf(usernames[(*username_count)++], "%s_%c", first_lower, last_lower[0]);

        sprintf(usernames[(*username_count)++], "%s%s", first_lower, date);
        sprintf(usernames[(*username_count)++], "%s%s", last_lower, date);
        sprintf(usernames[(*username_count)++], "%s%s%s", first_lower, last_lower, date);
        sprintf(usernames[(*username_count)++], "%s.%s%s", first_lower, last_lower, date);
        sprintf(usernames[(*username_count)++], "%c%s%s", first_lower[0], last_lower, date);
        sprintf(usernames[(*username_count)++], "%s%c%s", first_lower, last_lower[0], date);
        sprintf(usernames[(*username_count)++], "%c.%s%s", first_lower[0], last_lower, date);
        sprintf(usernames[(*username_count)++], "%s.%c%s", first_lower, last_lower[0], date);
        sprintf(usernames[(*username_count)++], "%s_%s%s", first_lower, last_lower, date);
        sprintf(usernames[(*username_count)++], "%c_%s%s", first_lower[0], last_lower, date);
        sprintf(usernames[(*username_count)++], "%s_%c%s", first_lower, last_lower[0], date);
    }
}

