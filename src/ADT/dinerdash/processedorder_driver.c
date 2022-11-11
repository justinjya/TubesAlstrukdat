#include <stdio.h>
#include <stdlib.h>
#include "processedorder.h"
int main(){
    int i;
    masakan m = MakeMasakan("M",0);
    printf("makanan: %s durasiorketahanan:%d\n",m.makanan,m.sisa_durasi_or_ketahanan_masakan);
    processedorder po = MakeProcessedOrder(10);
    if(IsProcessedOrderEmpty(po)){
        printf("po is empty \n");
        printf("capacity: %d neff: %d\n",GetProcessedOrderCapacity(po),LengthOfProcessedOrder(po));
    }
    
    for (i=0;i<GetProcessedOrderCapacity(po);i++){
        InsertProcessedOrderLast(&po, MakeMasakan("M",i));
        printf("po terakhir setelah insertlast: %s %d\n",GetProcessedOrder(po,i).makanan, GetProcessedOrder(po,i).sisa_durasi_or_ketahanan_masakan);
    }
    for (i=0;i<LengthOfProcessedOrder(po);i++){
        printf("%s %d\n",po.A[i].makanan,po.A[i].sisa_durasi_or_ketahanan_masakan);
    }
    printf("capacity: %d, neff: %d\n", po.Capacity, po.Neff);
    
    printf("po full dan ingin diinsertlast, I.S. po terakhir adalah %s %d\n",GetProcessedOrder(po,LengthOfProcessedOrder(po)-1).makanan,GetProcessedOrder(po,LengthOfProcessedOrder(po)-1).sisa_durasi_or_ketahanan_masakan);
    InsertProcessedOrderLast(&po,MakeMasakan("M",LengthOfProcessedOrder(po)));
    printf("F.S. po terakhir adalah %s %d\n", GetProcessedOrder(po,LengthOfProcessedOrder(po)-1).makanan, GetProcessedOrder(po,LengthOfProcessedOrder(po)-1).sisa_durasi_or_ketahanan_masakan);
    
    printf("po terakhir sebelum deletelast: %s %d\n",GetProcessedOrder(po,LengthOfProcessedOrder(po)-1).makanan,GetProcessedOrder(po,LengthOfProcessedOrder(po)-1).sisa_durasi_or_ketahanan_masakan);
    while(!IsProcessedOrderEmpty(po)){
        DeleteProcessedOrderLast(&po);  
        if(LengthOfProcessedOrder(po)!=0){
            printf("po terakhir setelah deletelast: %s %d\n",GetProcessedOrder(po,LengthOfProcessedOrder(po)-1).makanan,GetProcessedOrder(po,LengthOfProcessedOrder(po)-1).sisa_durasi_or_ketahanan_masakan);
        }
    }
    printf("I.S. po kosong, neff po sebelum process delete selanjutnya: %d\n", po.Neff);
    DeleteProcessedOrderAt(&po,0);
    printf("neff po setelah delete: %d\n",po.Neff);
    if(IsProcessedOrderEmpty(po)){
        printf("po kosong\n");
    }

    for (i=0;i<GetProcessedOrderCapacity(po);i++){
        InsertProcessedOrderFirst(&po,MakeMasakan("M",i));
        printf("po pertama setelah insertfirst: %s %d\n",GetProcessedOrder(po,0).makanan, GetProcessedOrder(po,0).sisa_durasi_or_ketahanan_masakan);
    }
    for (i=0;i<LengthOfProcessedOrder(po);i++){
        printf("%s %d\n",po.A[i].makanan,po.A[i].sisa_durasi_or_ketahanan_masakan);
    }
    printf("capacity: %d, neff: %d\n",po.Capacity,po.Neff);

    printf("po full dan ingin diinsertfirst, I.S. po pertama adalah %s %d\n",GetProcessedOrder(po,0).makanan,GetProcessedOrder(po,0).sisa_durasi_or_ketahanan_masakan);
    InsertProcessedOrderFirst(&po,MakeMasakan("M",LengthOfProcessedOrder(po)));
    printf("F.S. po pertama adalah %s %d\n", GetProcessedOrder(po,0).makanan, GetProcessedOrder(po,0).sisa_durasi_or_ketahanan_masakan);
    
    printf("po full dan ingin diinsertat idx 6, I.S. po idx-6 adalah %s %d\n",GetProcessedOrder(po,6).makanan,GetProcessedOrder(po,6).sisa_durasi_or_ketahanan_masakan);
    InsertProcessedOrderAt(&po,MakeMasakan("M",LengthOfProcessedOrder(po)),6);
    printf("F.S. po idx-6 adalah %s %d\n", GetProcessedOrder(po,6).makanan, GetProcessedOrder(po,6).sisa_durasi_or_ketahanan_masakan);
    printf("po pertama sebelum deletefirst: %s %d\n",GetProcessedOrder(po,0).makanan,GetProcessedOrder(po,0).sisa_durasi_or_ketahanan_masakan);
    while(IsProcessedOrderEmpty(po) == false){
        DeleteProcessedOrderFirst(&po);
        if(LengthOfProcessedOrder(po)!=0){
            printf("po pertama setelah deletefirst: %s %d\n",GetProcessedOrder(po,0).makanan,GetProcessedOrder(po,0).sisa_durasi_or_ketahanan_masakan);
        }
    }

    if(IsProcessedOrderEmpty(po)){
        printf("po kosong\n");
    }

    InsertProcessedOrderAt(&po,MakeMasakan("M",6),6);
    printf("po idx-6 setelah diinsert di idx-6 : %s %d\n", GetProcessedOrder(po,6).makanan, GetProcessedOrder(po,6).sisa_durasi_or_ketahanan_masakan);
    DeleteProcessedOrderAt(&po, 6);
    printf("Index element yang diinsert di idx-6 setelah dilakukan detele at idx-6: %d\n",SearchMasakan(po,MakeMasakan("M",6)));


    if(IsProcessedOrderEmpty(po)){
        printf("kosong\n");

    }
    InsertProcessedOrderLast(&po, MakeMasakan("M",0));
    InsertProcessedOrderLast(&po,MakeMasakan("M",1));
    printf("InsertProcessedOrderLast(&po, MakeMasakan(%cM%c,0));InsertProcessedOrderLast(&po,MakeMasakan(%cM%c,1)\n",'"','"','"','"');
    printf("indeks masakan (%cM%c,1) adalah %d\n",'"','"',SearchMasakan(po,MakeMasakan("M",1)));
    printf("masakan idx ke-0 adalah %s %d\n",GetProcessedOrder(po,0).makanan, GetProcessedOrder(po,0).sisa_durasi_or_ketahanan_masakan);
    return 0;


    
}
