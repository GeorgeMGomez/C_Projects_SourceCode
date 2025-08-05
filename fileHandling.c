#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void addContact();
void viewContacts();
void searchContact();

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
        case 2:
            viewContacts();
            break;
        case 3:
            searchContact();
            break;
    }

    return 0;
}

void addContact(){
    struct contact person;
    int decisionContact = false;

    FILE *fp = fopen("data.txt", "a");

    if(fp==NULL){
        printf("File is not opened\n");
        fclose(fp);
        return;
    }

    printf("Add your name: ");
    scanf("%s", person.name);
    
    printf("Add your phone number: ");
    scanf("%s", person.phone);
    
    printf("Add your email: ");
    scanf("%s", person.email);

    system("clear");

    printf("---CONTACT DETAILS---\n");
    printf("Name:%s\n", person.name);
    printf("Phone number:%s\n", person.phone);
    printf("Email:%s\n", person.email);

    fprintf(fp, "Name:%s  Phone number:%s  Email:%s\n", person.name, person.phone, person.email);
    fclose(fp);

    printf("Contact added successfully to the file\n");
    
}

void viewContacts(){
    char data[50];

    FILE *fp2 = fopen("data.txt", "r");

    if(fp2==NULL){
        printf("File is not opened\n");
        fclose(fp2);
        return;
    }

    printf("---VIEW CONTACTS---\n");
    while(fgets(data, 50, fp2)!=NULL){
        printf("%s", data);
    }

    fclose(fp2);
}

void searchContact(){
    char searchName[50];
    char line[100];
    bool found=false;

    FILE *fp3 = fopen("data.txt", "r");

    if(fp3==NULL){
        printf("File is not opened\n");
        fclose(fp3);
        return;
    }

    printf("Enter Name: ");
    scanf("%s", searchName);
    
    while(fgets(line, sizeof(line), fp3)!=NULL){
        char tag[50] = "Name:";
        strcat(tag, searchName);

        if (strstr(line, tag) != NULL) {
            printf("---CONTACT FOUND---\n");
            printf("%s\n", line);
            found = true;
            break;  
        }
    }

    if(!found){
        printf("Contact with name %s is not found\n", searchName);
    }

    fclose(fp3);
}
