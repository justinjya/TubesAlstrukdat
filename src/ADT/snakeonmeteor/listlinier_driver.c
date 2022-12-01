#include <stdio.h>
#include "listlinier.c"
#include "point.c"

int main(){
  List l;
  CreateEmpty_LL(&l);
  if(IsEmpty_LL(l)){
    printf("kosong\n");
  }
  printf("setelahinsvfirst\n");
  InsVFirst_LL(&l,CreatePoint(1,2));
  PrintInfo_LL(l);
  printf("\n");
  printf("setelahinsvfirst\n");
  InsVFirst_LL(&l,CreatePoint(1,3));
  PrintInfo_LL(l);
  printf("\nsetelahinsvfirst\n");
  InsVFirst_LL(&l,CreatePoint(1,4));
  PrintInfo_LL(l);
  if(IsEmpty_LL(l)){printf("\nkosong");}
  printf("\n%d elemen",NbElmt_LL(l));
  if(Search_LL(l,CreatePoint(1,5))!=NULL){
    printf("\nada <1,5>");
  }
  else{
    printf("\ngaada <1,5>");
  }
  if(Search_LL(l,CreatePoint(1,4))!=NULL){
    printf("\nada <1,4>");
  }
  else{
    printf("\ngaada <1,4>");
  }
  point x;
  printf("\nsetelahdelvlast");
  DelVLast_LL(&l,&x);
  printf("\n");
  PrintInfo_LL(l);
  printf("\n<%d,%d>",x.x,x.y);
  printf("\nsetelahdelvlast");
  DelVLast_LL(&l,&x);
  printf("\n");
  PrintInfo_LL(l);
  printf("\n<%d,%d>",x.x,x.y);
  printf("\nsetelahdelvlast");
  DelVLast_LL(&l,&x);
  printf("\n");
  PrintInfo_LL(l);
  printf("\n<%d,%d>\n",x.x,x.y);
  if(Search_LL(l,CreatePoint(1,4))!=NULL){
    printf("<1,4> ada\n");
  }
  else{
    printf("<1,4> gaada\n");
  }
  printf("%d elemen\n",NbElmt_LL(l));
  printf("setelahinsvlast\n");
  InsVLast_LL(&l,CreatePoint(1,2));
  PrintInfo_LL(l);
  printf("\n");
  printf("setelahinsvlast\n");
  InsVLast_LL(&l,CreatePoint(1,3));
  PrintInfo_LL(l);
  printf("\n");
  printf("setelahinsvlast\n");
  InsVLast_LL(&l,CreatePoint(1,4));
  PrintInfo_LL(l);

  printf("\nsetelahdelvfirst");
  DelVFirst_LL(&l,&x);
  printf("\n");
  PrintInfo_LL(l);
  printf("\n<%d,%d>",x.x,x.y);
  printf("\nsetelahdelvfirst");
  DelVFirst_LL(&l,&x);
  printf("\n");
  PrintInfo_LL(l);
  printf("\n<%d,%d>",x.x,x.y);
  printf("\nsetelahdelvfirst");
  DelVFirst_LL(&l,&x);
  printf("\n");
  PrintInfo_LL(l);
  printf("\n<%d,%d>\n",x.x,x.y);

  address p;
  printf("setelah insertfirst\n");
  p = Alokasi_LL(CreatePoint(1,2));
  InsertFirst_LL(&l,p);
  PrintInfo_LL(l);
  printf("\n");
  printf("setelah insertfirst\n");
  p = Alokasi_LL(CreatePoint(1,3));
  InsertFirst_LL(&l,p);
  PrintInfo_LL(l);
  printf("\n");
  printf("setelah insertfirst\n");
  p = Alokasi_LL(CreatePoint(1,4));
  InsertFirst_LL(&l,p);
  PrintInfo_LL(l);
  printf("\n");

  printf("setelah deletefirst\n");
  DelFirst_LL(&l,&p);
  PrintInfo_LL(l);
  printf("\n");
  printf("<%d,%d>\n",p->info.x,p->info.y);
  printf("setelah deletefirst\n");
  DelFirst_LL(&l,&p);
  PrintInfo_LL(l);
  printf("\n");
  printf("<%d,%d>\n",p->info.x,p->info.y);
  printf("setelah deletefirst\n");
  DelFirst_LL(&l,&p);
  PrintInfo_LL(l);
  printf("\n");
  printf("<%d,%d>\n",p->info.x,p->info.y);

  printf("setelah insertlast\n");
  p = Alokasi_LL(CreatePoint(1,2));
  InsertLast_LL(&l,p);
  PrintInfo_LL(l);
  printf("\n");
  printf("setelah insertlast\n");
  p = Alokasi_LL(CreatePoint(1,3));
  InsertLast_LL(&l,p);
  PrintInfo_LL(l);
  printf("\n");
  printf("setelah insertlast\n");
  p = Alokasi_LL(CreatePoint(1,4));
  InsertLast_LL(&l,p);
  PrintInfo_LL(l);
  printf("\n");

  printf("setelah deletelast\n");
  DelLast_LL(&l,&p);
  PrintInfo_LL(l);
  printf("\n");
  printf("<%d,%d>\n",p->info.x,p->info.y);
  printf("setelah deletelast\n");
  DelLast_LL(&l,&p);
  PrintInfo_LL(l);
  printf("\n");
  printf("<%d,%d>\n",p->info.x,p->info.y);
  printf("setelah deletelast\n");
  DelLast_LL(&l,&p);
  PrintInfo_LL(l);
  printf("\n");
  printf("<%d,%d>\n",p->info.x,p->info.y);

  printf("setelah DelP(&l,CreatePoint(1,2))\n");
  DelP_LL(&l,CreatePoint(1,2));
  PrintInfo_LL(l);
  printf("\n");
  printf("setelah insertlast\n");
  p = Alokasi_LL(CreatePoint(1,2));
  InsertLast_LL(&l,p);
  PrintInfo_LL(l);
  printf("\n");
  printf("setelah insertlast\n");
  p = Alokasi_LL(CreatePoint(1,3));
  InsertLast_LL(&l,p);
  PrintInfo_LL(l);
  printf("\n");
  printf("setelah insertlast\n");
  p = Alokasi_LL(CreatePoint(1,4));
  InsertLast_LL(&l,p);
  PrintInfo_LL(l);
  printf("\n");
  printf("setelah DelP(&l,CreatePoint(1,2))\n");
  DelP_LL(&l,CreatePoint(1,2));
  PrintInfo_LL(l);
  printf("\n");
  printf("setelah DelP(&l,CreatePoint(1,5))\n");
  DelP_LL(&l,CreatePoint(1,5));
  PrintInfo_LL(l);
  printf("\n");
  printf("setelah insertfirst\n");
  p = Alokasi_LL(CreatePoint(1,2));
  InsertFirst_LL(&l,p);
  PrintInfo_LL(l);
  printf("\n");
  printf("setelah DelAfter(&l,&p,Search(l,CreatePoint(1,3)))\n");
  DelAfter_LL(&l,&p,Search_LL(l,CreatePoint(1,3)));
  PrintInfo_LL(l);
  printf("\n");
  printf("setelah DelAfter(&l,&p,Search(l,CreatePoint(1,3)))\n");
  DelAfter_LL(&l,&p,Search_LL(l,CreatePoint(1,3)));
  PrintInfo_LL(l);
  printf("\n");
  printf("setelah DelAfter(&l,&p,Search(l,CreatePoint(1,2)))\n");
  DelAfter_LL(&l,&p,Search_LL(l,CreatePoint(1,2)));
  PrintInfo_LL(l);
  printf("\n");
  printf("setelah DelAfter(&l,&p,Search(l,CreatePoint(1,2)))\n");
  DelAfter_LL(&l,&p,Search_LL(l,CreatePoint(1,2)));
  PrintInfo_LL(l);
  printf("\n");
  printf("%d elemen",NbElmt_LL(l));
  return 0;
}
