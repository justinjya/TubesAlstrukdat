#include <stdio.h>
#include "arraydin_sb.c"
#include "map.c"

int main()
{
    int i;
    char ch;
    ArrayDin_SB array;
    i = 0;
    printf("MakeArrayDin_SB(0)\n");
    array = MakeArrayDin_SB(0);
    if(IsEmpty_SB(array)){
        printf("Scoreboard kosong\n");
    }
    printf("capacity: %d\n",GetCapacity_SB(array));
    printf("neff: %d\n",Length_SB(array));
    printf("MakeArrayDin_SB(5)\n");
    array = MakeArrayDin_SB(5);
    printf("capacity: %d\n",GetCapacity_SB(array));
    printf("neff: %d\n",Length_SB(array));
    printf("check each map content\n");
    for (i=0;i<array.Neff;i++){
        if(IsEmpty_M(array.A[i])){
            printf("score game kosong\n");
        }
    }
    Insert_M(&array.A[0],"nol",0);
    Insert_M(&array.A[1],"satu",1);
    Insert_M(&array.A[2],"dua",2);
    Insert_M(&array.A[3],"tiga",3);
    Insert_M(&array.A[4],"empat",4);
    printf("after inserting key-value pair in each of the maps, we want to get the index-1 map and see the value\n");
    printf("<%s,%d>\n",Get_SB(array,1).Elements[0].Key,Get_SB(array,1).Elements[0].Value);
    printf("neff before: %d\n",array.Neff);
    printf("AddNeff_SB(array) five times\n");
    AddNeff_SB(&array);
    AddNeff_SB(&array);
    AddNeff_SB(&array);
    AddNeff_SB(&array);
    AddNeff_SB(&array);
    printf("neff after: %d\n",array.Neff);
    printf("addneff if the array is full\n");
    AddNeff_SB(&array);
    printf("neff after: %d\n",array.Neff);
    printf("check the empty map\n");
    int countempty = 0;
    for (i=0;i<array.Neff;i++){
        if(IsEmpty_M(array.A[i])){
            printf("score game kosong\n");
            countempty++;
        }
    }
    printf("the empty map amount is %d\n",countempty);
    printf("subneff\n");
    SubNeff_SB(&array);
    printf("neffafter: %d\n",array.Neff);
    DeallocateArrayDin_SB(&array);
    printf("After deallocate\n");
    printf("neff: %d",array.Neff);
    return 0;
}
