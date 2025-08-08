#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct account {
    char name[25];
    char accountNumber[50];
    double balance;
};

void createNewAccount();
void depositMoney();
void withdrawMoney();
void viewAccountDetails();

//Bank Management System
int main(int argc, char* argv[]){
    int option;
    bool exit=false;

    do{
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Account Details\n");
        printf("5. List All Accounts\n");
        printf("6. Delete Account\n");
        printf("7. Update Account Info\n");
        printf("8. Exit\n");
        printf("Pick [1-8]: ");
        scanf("%d", &option);

        system("clear");

        switch(option){
            case 1:
                createNewAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                viewAccountDetails();
                break;
            case 8:
                exit=true;
                break;
        }

    }while(!exit);

    printf("Program Terminated...\n");

    return 0;
}

void createNewAccount(){
    struct account person;
    FILE *ptr = fopen("accounts.txt", "a");
    char correctness;
    bool flag=false;

    if(ptr == NULL){
        printf("File has not opened\n");
        fclose(ptr);
        return;
    }
    
    while(!flag){
        printf("Add name: ");
        scanf("%s", person.name);
        for(int i=0; person.name[i]!='\0'; i++){
            person.name[i] = tolower(person.name[i]);
        }

        printf("Add account number: ");
        scanf("%s", person.accountNumber);

        printf("Add balance: ");
        scanf("%lf", &person.balance);

        system("clear");

        do{
            printf("---ACCOUNT DETAILS---\n");
            printf("Name: %s\n", person.name);
            printf("Account Number: %s\n", person.accountNumber);
            printf("Balance: %.2lf\n", person.balance);
            printf("Is the information correct? ");

            scanf(" %c", &correctness);
            correctness = toupper(correctness);

            system("clear");
        }while(correctness != 'Y' && correctness != 'N');

        if(correctness = 'Y'){
            flag = true;
        }
    }

    fprintf(ptr, "Name:%s  Account Number:%s  Balance:%.2lf\n", person.name, person.accountNumber, person.balance);
    fclose(ptr);
    printf("Contact added successfully to the file\n");

}

void depositMoney(){    
    double amountDeposit;
    char targetAccountNumber[50];
    struct account person2;
    bool found = false;

    FILE *ptr2 = fopen("accounts.txt", "r");
    FILE *tmp = fopen("temp.txt", "w");

    if(ptr2 == NULL || tmp == NULL){
        printf("File has not opened\n");
        fclose(ptr2);
        fclose(tmp);
        return;
    }

    printf("Add the account number where you want to deposit: ");
    scanf("%s", targetAccountNumber);

    system("clear");

    while(fscanf(ptr2, "Name:%s  Account Number:%s  Balance:%lf\n", 
        person2.name, person2.accountNumber, &person2.balance)==3){
            if(strcmp(person2.accountNumber, targetAccountNumber)==0){
                found = true;

                do{
                    printf("Add the amount you want to deposit[>0]: ");
                    scanf("%lf", &amountDeposit);
                    system("clear");
                }while(amountDeposit<0);

                person2.balance+=amountDeposit;
                printf("New balance %.2lf\n", person2.balance);
            }

            fprintf(tmp, "Name:%s  Account Number:%s  Balance:%.2lf\n", person2.name, person2.accountNumber, person2.balance);
    }

    fclose(ptr2);
    fclose(tmp);

    if(found){
        remove("accounts.txt");
        rename("temp.txt", "accounts.txt");
        printf("Deposit successful and file updated\n");

        printf("Press any key to continue... ");
        while(getchar()!='\n');
        getchar();

        system("clear");
    }else{
        remove("temp.txt");
        printf("Account not found\n");

        printf("Press any key to continue... ");
        while(getchar()!='\n');
        getchar();

        system("clear");
    }
}

void withdrawMoney(){
    double amountWithdraw;
    char targetAccountNumber[50];
    struct account person3;
    bool found = false;
    bool sufficient;

    FILE *ptr3 = fopen("accounts.txt", "r");
    FILE *tmp2 = fopen("temp.txt", "w");

    if(ptr3 == NULL || tmp2 == NULL){
        printf("File has not opened\n");
        fclose(ptr3);
        fclose(tmp2);
        return;
    }

    printf("Add the account number where you want to deposit: ");
    scanf("%s", targetAccountNumber);

    system("clear");

    while(fscanf(ptr3, "Name:%s  Account Number:%s  Balance:%lf\n", 
        person3.name, person3.accountNumber, &person3.balance)==3){
            if(strcmp(person3.accountNumber, targetAccountNumber)==0){
                found = true;
                do{
                    printf("Add the amount you want to withdraw[>=0]: ");
                    scanf("%lf", &amountWithdraw);
                    system("clear");

                    if(person3.balance<amountWithdraw){
                        printf("Not enough in the balance to withdraw...\n");
                        sufficient = false;
                    }else{
                        sufficient = true;
                    }

                }while(amountWithdraw<0 || !sufficient);

                person3.balance-=amountWithdraw;
                printf("New balance %.2lf\n", person3.balance);
            }

            fprintf(tmp2, "Name:%s  Account Number:%s  Balance:%.2lf\n", person3.name, person3.accountNumber, person3.balance);
    }

    fclose(ptr3);
    fclose(tmp2);

    if(found){
        remove("accounts.txt");
        rename("temp.txt", "accounts.txt");
        printf("Withdrawal successful and file updated\n");

        printf("Press any key to continue... ");
        while(getchar()!='\n');
        getchar();

        system("clear");
    }else{
        remove("temp.txt");
        printf("Account not found\n");

        printf("Press any key to continue... ");
        while(getchar()!='\n');
        getchar();

        system("clear");
    }
}

void viewAccountDetails(){
    
}
