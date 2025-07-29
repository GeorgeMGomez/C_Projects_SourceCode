#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

char* selectedRandomWord();
void displayWord(char displayLetter, char* displaySelectedWord, char guessWord[], int *displayChances);
void displayHangman(int *tries, int chances);

int main(int argc, char **argv) {
    char* selectedWord = selectedRandomWord();
    char guessWord[6] = "_____";
    int chances = 3;
    int tries=0;
    char letter;
    bool flag;

    printf("Welcome to the hangman game!\n");
    printf("_____\n");

    while(chances){
        printf("Current Chances: %d \n", chances);
        printf("Guess a letter[a-z]: ");
        scanf(" %c", &letter);
        printf("\n");

        displayWord(letter, selectedWord, guessWord, &chances);
        displayHangman(&tries, chances);

        if(strcmp(selectedWord, guessWord)==0){
            printf("Congrats! You found the word! Hangman lives!\n");
            break;
        }
    }

    if(!chances){
        printf("Hangman dies!\n");
        printf("The word was %s \n", selectedWord);
    }

    return 0;
}

char* selectedRandomWord(){
    char* RandomWords[] = {"crane", "blush", "grind", "spice", "jolly", "wrist", "mouth", "glide", "plaza", "shore"};
    int result;

    srand(time(NULL));
    result = rand() % 10;

    return RandomWords[result];
}

void displayWord(char displayLetter, char* displaySelectedWord, char guessWord[], int *displayChances){
    bool flag = false;
    for(int i=0; i<5; i++){
            if(displayLetter == displaySelectedWord[i]){
                guessWord[i] = displayLetter;
                flag=true;
            }
        }

        if(flag){
            printf("%s \n\n", guessWord);
        }else{
            printf("%s \n\n", guessWord);
            (*displayChances)--;
        }
}

void displayHangman(int *displayTries, int displayChances){
    const char* hangman[] = {"__________", "|        |", "|        O",
                             "|       /|\\", "|       / \\"};
    
    if(displayChances==2){
        (*displayTries)=3;
    }else if(displayChances==1){
        (*displayTries)=4;
    }else{
        (*displayTries)=5;
    }

    for(int j=0; j<*displayTries; j++){
        printf("%s\n", hangman[j]);
    }
}
