#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

char* selectedRandomWord();

int main(int argc, char **argv) {

    char* selectedWord = selectedRandomWord();
    char guessWord[6] = "_____";
    int chances = 3;
    char letter;
    bool flag;

    printf("Welcome to the hangman game!\n");
    printf("_____\n");
    while(chances){
        flag=false;
        printf("Current Chances: %d \n", chances);
        printf("Guess a letter[a-z]: ");
        scanf(" %c", &letter);
        printf("\n");

        for(int i=0; i<5; i++){
            if(letter == selectedWord[i]){
                guessWord[i] = letter;
                flag=true;
            }
        }

        if(flag){
            printf("%s \n", guessWord);
        }else{
            printf("\n");
            chances--;
        }

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
