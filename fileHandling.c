#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

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
    bool exit=false;

    do{
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n\n");

        printf("Pick [1-4]: ");
        scanf("%d", &decision);

        system("clear");

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
            case 4:
                exit=true;
        }
    }
    while(!exit);

    printf("Program terminated...\n");

    return 0;
}

void addContact(){
    struct contact person;
    int decisionContact = true;
    char correctness;

    FILE *fp = fopen("data.txt", "a");

    if(fp==NULL){
        printf("File is not opened\n");
        fclose(fp);
        return;
    }

    while(decisionContact){
        printf("Add your name: ");
        scanf("%s", person.name);

        //Applying lower casing to each letter in the name
        for(int i=0; person.name[i]!='\0'; i++){
            person.name[i] = tolower(person.name[i]);
        }
    
        printf("Add your phone number: ");
        scanf("%s", person.phone);
    
        printf("Add your email: ");
        scanf("%s", person.email);

        system("clear");

        do{
            printf("---CONTACT DETAILS---\n");
            printf("Name:%s\n", person.name);
            printf("Phone number:%s\n", person.phone);
            printf("Email:%s\n", person.email);

            printf("Is your information correct? [Y/N]: ");
            scanf(" %c", &correctness);
            correctness = toupper(correctness);
            system("clear");
        }while(correctness!='Y' && correctness!='N');

        if(correctness=='Y'){
            decisionContact=false;
        }
    }
        
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
    printf("Press any key to continue... \n");
    while(getchar() != '\n');
    getchar();

    fclose(fp2);

    system("clear");
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

    for(int j=0; searchName[j]!='\0'; j++){
        searchName[j] = tolower(searchName[j]);
    }
    
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

    printf("Press any key to continue... \n");
    while(getchar() != '\n');
    getchar();

    fclose(fp3);

    system("clear");
}
