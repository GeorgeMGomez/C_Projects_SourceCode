#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int RandBotHand();
void announceHands(int hand, int handBot);
void victor(int person, int bot);

int main(int argc, char **argv){
    int hand;
    int handBot;

    printf("---ROCK PAPER SCISSORS---\n\n");

    do{
        printf("1. Rock \n2. Paper \n3. Scissors \nChoose[1-3]: ");
        scanf("%d", &hand);
        printf("\n");
    }while(hand < 1 || hand > 3);

    handBot = RandBotHand();

    announceHands(hand, handBot);
    victor(hand, handBot);

    return 0;
}

//Randomly generates the bot's hand
int RandBotHand(){
    int result;

    srand(time(NULL));
    result = rand() % 3+1;

    return result;
}

void announceHands(int personHand, int botHand){
    switch (personHand){
        case 1:
            printf("You chose: Rock\n");
            break;
        case 2:
            printf("You chose: Paper\n");
            break;
        default:
            printf("You chose: Scissors\n");
            break;
    }

    switch (botHand){
        case 1:
            printf("Bot chose: Rock\n");
            break;
        case 2:
            printf("Bot chose: Paper\n");
            break;
        default:
            printf("Bot chose: Scissors\n");
            break;
    }
}

//Prints the victor
void victor(int person, int bot){
    if(person == 1){
        switch (bot){
            case 1:
                printf("Tie\n");
                break;
            case 2:
                printf("You lost.\n");
                break;
            default:
                printf("You win.\n");
                break;
        }
    }

    if(person == 2){
        switch (bot){
            case 1:
                printf("You win.\n");
                break;
            case 2:
                printf("Tie.\n");
                break;
            default:
                printf("You lost.\n");
                break;
        }
    }

    if(person == 3){
        switch (bot){
            case 1:
                printf("You lost.\n");
                break;
            case 2:
                printf("You win.\n");
                break;
            default:
                printf("Tie.\n");
                break;
        }
    }
}
