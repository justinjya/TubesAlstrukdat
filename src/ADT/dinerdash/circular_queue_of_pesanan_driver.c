#include <stdio.h>
#include <stdlib.h>
#include "circular_queue_of_pesanan.h"

int main(){
    pesanan p = CreatePesanan("M1",10,9,8);
    printf("%s %d %d %d\n",p.makanan,p.durasimasak,p.ketahanan,p.harga);
    QueueOfPesanan qp = CreateQueueOfPesanan(10);
    if(IsQueueOfPesananEmpty(qp)){
        printf("QofPesanan is Empty\n");
        printf("MaxEl of QofPesanan = %d\n",qp.MaxEl);
        printf("HEAD : %d, TAIL : %d\n",qp.HEAD,qp.TAIL);
    }

    while (LengthQueueOfPesanan(qp)<MaxLengthQPesanan(qp))
    {
        PushPesanan(&qp,p);
    }
    if(IsQueueOfPesananFull(qp)){
        printf("QofPesanan is full\n");
        printf("MaxEl of QofPesanan = %d\n",qp.MaxEl);
        printf("HEAD : %d, TAIL : %d\n",qp.HEAD,qp.TAIL);
    }
    PopPesanan(&qp);
    printf("Length of QofPesanan : %d\n",LengthQueueOfPesanan(qp));
    printf("Pesanan terdepan: %s %d %d %d\n",FrontPesanan(qp).makanan,FrontPesanan(qp).durasimasak,FrontPesanan(qp).ketahanan,FrontPesanan(qp).harga);
    DeleteQueueOfPesanan(&qp);
    if(qp.MaxEl == 0){
        printf("Berhasil dealokasi\n");
    }
    return 0;
}
