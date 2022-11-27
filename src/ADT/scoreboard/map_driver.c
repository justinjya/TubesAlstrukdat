#include <stdio.h>
#include "map.c"

int main(){
    Map M;
    printf("Pembuatan map baru\n");
    CreateEmpty_M(&M);
    printf("Pengecekkan map kosong\n");
    if(IsEmpty_M(M)){
        printf("Map kosong\n");
    }
    printf("Insert_M sampai map full\n");
    Insert_M(&M,"satu",1+1);
    Insert_M(&M,"dua",2+1);
    Insert_M(&M,"tiga",3+1);
    Insert_M(&M,"empat",4+1);
    Insert_M(&M,"lima",5+1);
    Insert_M(&M,"enam",6+1);
    Insert_M(&M,"tujuh",7+1);
    Insert_M(&M,"delapan",8+1);
    Insert_M(&M,"sembilan",9+1);
    Insert_M(&M,"nol",0+1);
    printf("Anggota M sekarang : %d\n",M.Count);
    printf("Pengecekkan map penuh\n");
    if(IsFull_M(M)){
        printf("Map penuh\n");
    }
    printf("Value_M dengan key ada pada map\n");
    valuetype m = Value_M(M,"satu");
    printf("%d\n",m);
    printf("Value M dengan key tidak ada pada map\n");
    m = Value_M(M,"sepuluh");
    printf("%d\n",m);
    printf("Pengecekkan IsMember_M\n");
    if(IsMember_M(M,"satu")){
        printf("Ada\n");
    }
    else{
        printf("Tidak ada\n");
    }
    if(IsMember_M(M,"sepuluh")){
        printf("Ada\n");
    }
    else{
        printf("Tidak ada\n");
    }
    printf("Delete anggota\n");
    Delete_M(&M,"dua");
    if(IsMember_M(M,"dua")){
        printf("Gagal delete\n");
    }
    else{
        printf("Berhasil delete\n");
        printf("Anggota sekarang : %d\n",M.Count);
    }
    printf("Delete bukan anggota\n");
    Delete_M(&M,"sepuluh");
    printf("Anggota sekarang : %d\n",M.Count);
    printf("Insert_M(&M,\"satu\",1) dimana key sudah ada di M\n");
    Insert_M(&M,"satu",1);
    printf("Anggota sekarang : %d\n",M.Count);

    return 0;
}