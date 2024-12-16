// Code vulnerable to a use-after-free attack
// Written for the F24 CPSC 525 final project

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*funcpoint)();

const char* secret = "Alas, poor Yorick!";
int running = 1;

void getsecret() {
    printf("%s\n",secret);
    exit(1);
}

void telljoke() {
    printf("What's the worst part about UDP jokes?\n");
    printf("Nobody cares if you get them or not!\n");
}

void dead() {
    printf("beef\n");
}

int main() {

    funcpoint* funcs[3];

    while (running) {
        int user;
        printf("Please pick an option!\n");
        printf("1. Register a function\n");
        printf("2. Delete a function\n");
        printf("3. Use a function\n");
        printf("4. Exit\n");
        printf("Input: ");

        scanf("%d", &user);

        if (user == 1) {
            int reguser;
            printf("Pick a function to register:\n");
            printf("1. dead()\n");
            printf("2. telljoke()\n");
            printf("3. getsecret()\n");
            printf("Input: ");
            scanf("%d", &reguser);
             if (reguser == 1) {
                funcs[0] = malloc(sizeof(funcpoint));
                *funcs[0] = dead;
             }
             if (reguser == 2) {
                funcs[1] = malloc(sizeof(funcpoint));
                *funcs[1] = telljoke;
             }
             if (reguser == 3) {
                funcs[2] = malloc(sizeof(funcpoint));
                *funcs[2] = getsecret;
             }
        }
        else if (user == 2) {
            int deluser;
            printf("Pick function 1, 2, or 3 to delete.\n");
            printf("Input: ");
            scanf("%d", &deluser);
            if (deluser == 1) {
                free(funcs[0]);
            }
            if (deluser == 2) {
                free(funcs[1]);
            }
            if (deluser == 3) {
                free(funcs[2]);
            }
        }
        else if (user == 3) {
            int useuser;
            printf("Pick function 1, 2, or 3 to use.\n");
            printf("Input: ");
            scanf("%d", &useuser);
            if (useuser == 1) {
                (*funcs[0])();
            }
            if (useuser == 2) {
                (*funcs[1])();
            }
            if (useuser == 3) {
                printf("You're not allowed to see the secret, sorry!\n");
            }
        }
        else if (user == 4) {
            exit(1);
        }
        else {
            printf("That's not an option!\n");
        }
    }


}