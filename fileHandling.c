#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void addContact();

struct contact {
    char name[50];
    char phone[20];
    char email[50];
};

int main(int argc, char *argv[]){
    //Contact Manager project
    int decision;

    do{
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n\n");

        printf("Pick [1-4]: ");
        scanf("%d", &decision);

        system("clear");
    }
    while(decision<1 || decision>4);

    switch(decision){
        case 1:
            addContact();
            break;
    }

    return 0;
}

void addContact(){
    struct contact person;
    int decisionContact = false;

    FILE *fp = fopen("data.txt", "a");

    printf("Add your name: ");
    scanf("%s", person.name);
    printf("\n");

    printf("Add your phone number: ");
    scanf("%s", person.phone);
    printf("\n");

    printf("Add your email: ");
    scanf("%s", person.email);

    system("clear");

    printf("---CONTACT DETAILS---\n");
    printf("Name: %s\n", person.name);
    printf("Phone number: %s\n", person.phone);
    printf("Email: %s\n", person.email);
    
}
