#ifndef USERNAME_GENERATOR_H
#define USERNAME_GENERATOR_H

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 50
#define MAX_USERNAMES 1000

void generateUsernames(char names[MAX_NAMES][MAX_NAME_LENGTH], int name_count, char usernames[MAX_USERNAMES][MAX_NAME_LENGTH], int *username_count);

#endif
