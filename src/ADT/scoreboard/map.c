#include <stdio.h>
#include "map.h"
/* *** Konstruktor/Kreator *** */
void CreateEmpty_M(Map *M){
    M->Count=Nil_M;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl_M */
/* Ciri Map kosong : count bernilai Nil_M */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty_M(Map M){
    return M.Count==Nil_M;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil_M */

boolean IsFull_M(Map M){
    return M.Count==MaxEl_M;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl_M */

/* ********** Operator Dasar Map ********* */
valuetype Value_M(Map M, keytype k){
    if(IsMember_M(M,k)){
        int i = 0;
        while (M.Elements[i].Key!=k){
            i++;
        }
        return M.Elements[i].Value;
        
    }
    else{
        return Undefined_M;
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined_M */

void Insert_M(Map *M, keytype k, valuetype v){
    if(!IsMember_M(*M,k)){
        M->Elements[M->Count].Key=k;
        M->Elements[M->Count].Value=v;
        M->Count+=1;
    }   
}

/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete_M(Map *M, keytype k){
    if(IsMember_M(*M,k)){
        int i = 0;
        while (M->Elements[i].Key!=k){
            i++;
        }
        if(!( M->Elements[i].Key == M->Elements[M->Count-1].Key)){
            int j = i+1;
            while (j<M->Count){
                M->Elements[i]=M->Elements[j];
                i++;
                j++;
            }
        }
        M->Count-=1;   
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMember_M(Map M, keytype k){
    boolean temp = false;
    int i=0;
    while (i<M.Count && temp==false){
        if(eq_string(M.Elements[i].Key,k)){
            temp=true;
        }
        i++;
    }
    return temp;
}
/* Mengembalikan true jika k adalah member dari M */

boolean eq_string(char* string1, char* string2){
    int lengtha=0;
    int lengthb=0;
    int i = 0;
    char *a;
    char *b;
    a = malloc(50*sizeof(char));
    b = malloc(50*sizeof(char));
    while (string1[i]!='\0'){
        a[i] = string1[i];
        lengtha += 1;
        i+=1;
    }
    a[i] = '\0';
    i=0;
    while (string2[i]!='\0')
    {
        b[i] = string2[i];
        lengthb+=1;
        i+=1;
    }
    b[i] = '\0';
    if (lengtha!=lengthb){
        return false;
    }
    else{
        int temp = 1;
        for (i=0;i<lengtha;i++){
            if (a[i]!=b[i]){
                if(a[i]>='A' && a[i]<='Z'){
                    a[i]+=32;
                    if(a[i]!=b[i]){
                        temp = 0;
                        break;
                    }
                }
                else if(b[i]>='A' && b[i]<='Z'){
                    b[i]+=32;
                    if(a[i]!=b[i]){
                        temp = 0;
                        break;
                    }
                }
                else{
                    temp = 0;
                    break;
                }
            }
        }
        if(temp == 1){
            return true;
        }
        else{
            return false;
        }
    }
}
/* Mengembalikan nilai true jika string1 sama dengan string2
 * Mengembalikan nilai false jika string1 tidak sama dengan string2
 * Kedua string dikatakan sama apabila memiliki panjang yang sama dan huruf per hurufnya merupakan abjad yang sama.
 */ 

int SearchIndex(Map M, keytype k){
    int i=0;
    while (i<M.Count){
        if(eq_string(M.Elements[i].Key,k)){
            return i;
        }
        i++;
    }
    return Undefined_M;
}
/* Mengembalikan index pertama kalinya ditemukan key k dari M
 */

void SortValueMap(Map *M, boolean ascending){
    infotype temp;
    if (ascending == true){
        for (int i = 0; i < M->Count - 1; i++){
            for (int j = 0; j < M->Count - 1; j++){
                if (M->Elements[j + 1].Value < M->Elements[j].Value){
                    temp = M->Elements[j];
                    M->Elements[j] = M->Elements[j + 1];
                    M->Elements[j + 1] = temp;
                }
            }
        }
    }
    else{
        for (int i = 0; i < M->Count - 1; i++){
            for (int j = 0; j < M->Count - 1; j++){
                if (M->Elements[j + 1].Value > M->Elements[j].Value){
                    temp = M->Elements[j];
                    M->Elements[j] = M->Elements[j + 1];
                    M->Elements[j + 1] = temp;
                }
            }
        }
    }
}
/* Mengembalikan Map M yang sudah disortir berdasatkan value
 * Mengembalikan hasil sortir ascending jika ascending = true
 * Mengembalikan hasil sortir decending jika ascending = false
 */
