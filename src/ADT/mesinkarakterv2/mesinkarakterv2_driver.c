#include <stdio.h>
#include "mesinkarakterv2.h"

int main(){
    char* dir = "../../../data/config.txt";
    printf("BACA STDIN\n");
    START(NULL);
    while (!EOP)
    {
        printf("%c",currentChar);
        ADV();
    }
    printf("\n");

    printf("BACA FILE\n");
    START(dir);
    while (!EOP)
    {
        printf("%c",currentChar);
        ADV();
    }
    return 0;
}
