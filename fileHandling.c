#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *fp = fopen("data.txt", "w");

    if(fp==NULL){
        printf("File does not exist\n");
    }else{
        fprintf(fp, "Hello World!\n");
        fclose(fp);
    }

    return 0;
}
