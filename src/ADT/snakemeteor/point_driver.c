#include <stdio.h>
#include "point.c"

int main(){
    point p = CreatePoint(1,1);
    displayPoint(p);
    printf("\n");
    if(isOrigin(p)){
        printf("p merupakan titik <0,0>\n");
    }
    else{
        printf("p bukan merupakan titik <0,0>\n");
    }
    printf("setelah dimove sebesar dx = 1 dan dy = 2\n");
    p = move(p,1,2);
    displayPoint(p);
}