#include <stdio.h>
#include "listlinier.c"
#include "point.c"

int main(){
  List l;
  CreateEmpty(&l);
  if(IsEmpty(l)){
    printf("kosong\n");
  }
  printf("setelahinsvfirst\n");
  InsVFirst(&l,CreatePoint(1,2));
  PrintInfo(l);
  printf("\n");
  printf("setelahinsvfirst\n");
  InsVFirst(&l,CreatePoint(1,3));
  PrintInfo(l);
  printf("\nsetelahinsvfirst\n");
  InsVFirst(&l,CreatePoint(1,4));
  PrintInfo(l);
  if(IsEmpty(l)){printf("\nkosong");}
  printf("\n%d elemen",NbElmt(l));
  if(Search(l,CreatePoint(1,5))!=NULL){
    printf("\nada <1,5>");
  }
  else{
    printf("\ngaada <1,5>");
  }
  if(Search(l,CreatePoint(1,4))!=NULL){
    printf("\nada <1,4>");
  }
  else{
    printf("\ngaada <1,4>");
  }
  point x;
  printf("\nsetelahdelvlast");
  DelVLast(&l,&x);
  printf("\n");
  PrintInfo(l);
  printf("\n<%d,%d>",x.x,x.y);
  printf("\nsetelahdelvlast");
  DelVLast(&l,&x);
  printf("\n");
  PrintInfo(l);
  printf("\n<%d,%d>",x.x,x.y);
  printf("\nsetelahdelvlast");
  DelVLast(&l,&x);
  printf("\n");
  PrintInfo(l);
  printf("\n<%d,%d>\n",x.x,x.y);
  if(Search(l,CreatePoint(1,4))!=NULL){
    printf("<1,4> ada\n");
  }
  else{
    printf("<1,4> gaada\n");
  }
  printf("%d elemen\n",NbElmt(l));
  printf("setelahinsvlast\n");
  InsVLast(&l,CreatePoint(1,2));
  PrintInfo(l);
  printf("\n");
  printf("setelahinsvlast\n");
  InsVLast(&l,CreatePoint(1,3));
  PrintInfo(l);
  printf("\n");
  printf("setelahinsvlast\n");
  InsVLast(&l,CreatePoint(1,4));
  PrintInfo(l);

  printf("\nsetelahdelvfirst");
  DelVFirst(&l,&x);
  printf("\n");
  PrintInfo(l);
  printf("\n<%d,%d>",x.x,x.y);
  printf("\nsetelahdelvfirst");
  DelVFirst(&l,&x);
  printf("\n");
  PrintInfo(l);
  printf("\n<%d,%d>",x.x,x.y);
  printf("\nsetelahdelvfirst");
  DelVFirst(&l,&x);
  printf("\n");
  PrintInfo(l);
  printf("\n<%d,%d>\n",x.x,x.y);

  address p;
  printf("setelah insertfirst\n");
  p = Alokasi(CreatePoint(1,2));
  InsertFirst(&l,p);
  PrintInfo(l);
  printf("\n");
  printf("setelah insertfirst\n");
  p = Alokasi(CreatePoint(1,3));
  InsertFirst(&l,p);
  PrintInfo(l);
  printf("\n");
  printf("setelah insertfirst\n");
  p = Alokasi(CreatePoint(1,4));
  InsertFirst(&l,p);
  PrintInfo(l);
  printf("\n");

  printf("setelah deletefirst\n");
  DelFirst(&l,&p);
  PrintInfo(l);
  printf("\n");
  printf("<%d,%d>\n",p->info.x,p->info.y);
  printf("setelah deletefirst\n");
  DelFirst(&l,&p);
  PrintInfo(l);
  printf("\n");
  printf("<%d,%d>\n",p->info.x,p->info.y);
  printf("setelah deletefirst\n");
  DelFirst(&l,&p);
  PrintInfo(l);
  printf("\n");
  printf("<%d,%d>\n",p->info.x,p->info.y);

  printf("setelah insertlast\n");
  p = Alokasi(CreatePoint(1,2));
  InsertLast(&l,p);
  PrintInfo(l);
  printf("\n");
  printf("setelah insertlast\n");
  p = Alokasi(CreatePoint(1,3));
  InsertLast(&l,p);
  PrintInfo(l);
  printf("\n");
  printf("setelah insertlast\n");
  p = Alokasi(CreatePoint(1,4));
  InsertLast(&l,p);
  PrintInfo(l);
  printf("\n");

  printf("setelah deletelast\n");
  DelLast(&l,&p);
  PrintInfo(l);
  printf("\n");
  printf("<%d,%d>\n",p->info.x,p->info.y);
  printf("setelah deletelast\n");
  DelLast(&l,&p);
  PrintInfo(l);
  printf("\n");
  printf("<%d,%d>\n",p->info.x,p->info.y);
  printf("setelah deletelast\n");
  DelLast(&l,&p);
  PrintInfo(l);
  printf("\n");
  printf("<%d,%d>\n",p->info.x,p->info.y);

  printf("setelah DelP(&l,CreatePoint(1,2))\n");
  DelP(&l,CreatePoint(1,2));
  PrintInfo(l);
  printf("\n");
  printf("setelah insertlast\n");
  p = Alokasi(CreatePoint(1,2));
  InsertLast(&l,p);
  PrintInfo(l);
  printf("\n");
  printf("setelah insertlast\n");
  p = Alokasi(CreatePoint(1,3));
  InsertLast(&l,p);
  PrintInfo(l);
  printf("\n");
  printf("setelah insertlast\n");
  p = Alokasi(CreatePoint(1,4));
  InsertLast(&l,p);
  PrintInfo(l);
  printf("\n");
  printf("setelah DelP(&l,CreatePoint(1,2))\n");
  DelP(&l,CreatePoint(1,2));
  PrintInfo(l);
  printf("\n");
  printf("setelah DelP(&l,CreatePoint(1,5))\n");
  DelP(&l,CreatePoint(1,5));
  PrintInfo(l);
  printf("\n");
  printf("setelah insertfirst\n");
  p = Alokasi(CreatePoint(1,2));
  InsertFirst(&l,p);
  PrintInfo(l);
  printf("\n");
  printf("setelah DelAfter(&l,&p,Search(l,CreatePoint(1,3)))\n");
  DelAfter(&l,&p,Search(l,CreatePoint(1,3)));
  PrintInfo(l);
  printf("\n");
  printf("setelah DelAfter(&l,&p,Search(l,CreatePoint(1,3)))\n");
  DelAfter(&l,&p,Search(l,CreatePoint(1,3)));
  PrintInfo(l);
  printf("\n");
  printf("setelah DelAfter(&l,&p,Search(l,CreatePoint(1,2)))\n");
  DelAfter(&l,&p,Search(l,CreatePoint(1,2)));
  PrintInfo(l);
  printf("\n");
  printf("setelah DelAfter(&l,&p,Search(l,CreatePoint(1,2)))\n");
  DelAfter(&l,&p,Search(l,CreatePoint(1,2)));
  PrintInfo(l);
  printf("\n");
  printf("%d elemen",NbElmt(l));
  return 0;
}