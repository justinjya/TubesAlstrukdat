#include "../functions.h"

struct pole{
   int stack[10];
}; 

struct pole p[3];
int top[5];

//Mengisi tiang paling kiri (sumber piringan) / Kondisi Awal
void fillSrc(int jumlahPiringan){
    //Membentuk array berisi angka-angka ganjil untuk tower
    int temp[jumlahPiringan];
    int oddNumber = 1;
    int i, j, max, maxTemp, spaces;
    for (i = 0; i < jumlahPiringan; i++){
        temp[i] = oddNumber;
        oddNumber += 2;
    }
    //Mengisi tiang paling kiri (sumber piringan)
    top[0] = jumlahPiringan - 1;
    j = jumlahPiringan - 1;
    for (int i = 0; i < jumlahPiringan; i++){
        p[0].stack[i] = temp[j];
        p[1].stack[i] = 99;
        p[2].stack[i] = 99;
        j--;
    }
}

//Memasukkan / memindahkan piringan ke tiang
void push(int x, int asal, int *moves){
 int a;
    chooseWhereToPush: //Memilih piringan yang akan ditambahkan ke suatu tiang
    printf("TIANG TUJUAN: ");
    inputInteger(&a); //Input tiang tujuan
    printf("\n");
    
    if (a < 1 || a > 3){
        printf("MASUKAN TIDAK VALID.\n");
        printf("COBA LAGI!\n");
        goto chooseWhereToPush;
    } else {
        if(p[a-1].stack[top[a-1]] > x || p[a-1].stack[top[a-1]] == 0){ // Kondisi apabila piringan yang ingin dipush lebih kecil dari piringan dibawahnya pada tiang yang akan dimasukkan
            top[a-1]++;
            p[a-1].stack[top[a-1]] = x;
        } else { // Kondisi syarat piringan tidak terpenuhi
            printf("PROSES TIDAK BISA DILAKUKAN.\n");
            printf("COBA LAGI!\n\n");
            goto chooseWhereToPush;
        }
    }
    if (a != asal){
        (*moves)++;
    } else {
        printf("ANDA MEMINDAHKAN PIRING KE TIANG YANG SAMA,\n");
        printf("PROSES TIDAK BISA DILAKUKAN.\n");
        printf("COBA LAGI!\n\n");
    }
}

// Mengeluarkan piringan dari tiang
int pop(int *asal) {
    int a, x;
    chooseWhereToPop: //Memilih piringan yang akan dikeluarkan dari suatu tiang
    printf("\nTIANG ASAL: ");
    inputInteger(&a); //Input tiang asal
    printf("\n");
    if (a < 1 || a > 3){
        printf("MASUKAN TIDAK VALID.\n");
        printf("COBA LAGI!\n");
        goto chooseWhereToPop;
    } else {
        if(top[a-1] == -1){
            printf("TIANG KOSONG, PROSES TIDAK BISA DILAKUKAN.\n");
            printf("COBA LAGI!\n");
            goto chooseWhereToPop;
        }
    }
    
    *asal = a;
    x = p[a-1].stack[top[a-1]];
    p[a-1].stack[top[a-1]] = 99;
    top[a-1]--;
    return x;
}

// Mengembalikan nilai piringan terbesar di tower
int maxPiringan(int jumlahPiringan){
    int temp[jumlahPiringan];
    int oddNumber = 1;
    int i, j, max, maxTemp, spaces;
    for (i = 0; i < jumlahPiringan; i++){
        temp[i] = oddNumber;
        oddNumber += 2;
    }
    return temp[jumlahPiringan - 1];
}

// Menampilkan tower-tower
void displaylevel(int level, int jumlahPiringan){
    int i, j, max, maxTemp, spaces;
    char *tiang;
    char *piring;
    max = maxPiringan(jumlahPiringan);
    maxTemp = p[0].stack[level];
    tiang = (char *) malloc (20 * sizeof(char));
    piring = (char *) malloc (20 * sizeof(char));
    //Membuat string untuk menampilkan tiang
    for (j = 0; j <= max; j++){
        if (j == max / 2){
            tiang[j] = '|';
        } else if (j == max){
            tiang[j] = '\0';
        } else {
            tiang[j] = ' ';
        }
    }
    //Menampilkan piring di setiap tower
    for(i = 0; i < 3; i++){
        if(p[i].stack[level] == 99 || p[i].stack[level] == 0) {
         printf("%s\t", tiang);
        } else {
            //Membuat string untuk menampilkan piring
            spaces = (max - p[i].stack[level]) / 2;
            for (j = 0; j <= max; j++){
                if (j < spaces){
                    piring[j] = ' ';
                } else if (j < spaces + p[i].stack[level]){
                    piring[j] = '*';
                } else if (j == max){
                    piring[j] = '\0';
                } else{
                    piring[j] = ' ';
                }
            }
            printf("%s\t", piring);
        }
    }
    printf("\n");
}

//Menampilkan seluruh pirigan pada tiang
void display(int jumlahPiringan){
    int i, j, max;
    max = maxPiringan(jumlahPiringan);
    //Menampilkan setiap piringan yang ada
    for(i = jumlahPiringan - 1; i >= 0; i--) {
        displaylevel(i, jumlahPiringan);
    }
    //Menampilkan batas bawah piringan
    char *pembatas;
    pembatas = (char *) malloc (20 * sizeof(char));
    for(i = 0; i <= max; i++){
        if (i < max){
            pembatas[i] = '-';
        } else {
            pembatas[i] = '\0';
        }
    }
    for(i = 0; i < 3; i++){
        printf("%s\t", pembatas);
    }
    printf("\n");
    //Menampilkan nama untuk setiap tiang
    char *namaTiang;
    for(i = 0; i < 3; i++){
        namaTiang = (char *) malloc (20 * sizeof(char));
        for (j = 0; j <= max; j++){
            if (j == max / 2){
                namaTiang[j] = 49 + i;
            } else if (j == max){
                namaTiang[j] = '\0';
            } else {
                namaTiang[j] = ' ';
            }
        }
        printf("%s\t", namaTiang);
    }
    printf("\n");
}    

//Kondisi apabila game berhasil diselesaikan
boolean gameWinCondition(int jumlahPiringan) {
    int i, j, max, maxTemp, spaces;
    //Array dengan isi angka-angka ganjil untuk setiap piring di tower
    int temp[jumlahPiringan];
    int oddNumber = 1;
    for (i = 0; i < jumlahPiringan; i++){
        temp[i] = oddNumber;
        oddNumber += 2;
    }
    //Proses memeriksa kondisi menang
    i = 0;
    j = jumlahPiringan - 1;
    while(i < jumlahPiringan){
        if (p[2].stack[i] != temp[j]){
            return false; //Kondisi menang belum terpenuhi
        }
        i++;
        j--;
    }
    return true; //Kondisi menang terpenuhi
}

//Program Utama
int TOWEROFHANOI(){
    top[2] = top[1] = -1;
    int win = 0;
    int x, score, asal, jumlahPiringan;
    int moves = 0; //Variabel untuk hitung banyak gerakan pemain
    printf("\n==================================== TOWER OF HANOI ====================================\n");
    printf("Tujuan: Memindahkan seluruh piringan pada tiang paling kiri ke tiang paling kanan.\n");
    printf("Rule: Tidak bisa memindahkan piringan yang lebih besar di atas piringan yang lebih kecil.");
    do{
        printf("\nSilahkan input jumlah piringan (Min: 1, Max: 10): ");
        inputInteger(&jumlahPiringan);
        if (jumlahPiringan < 1 || jumlahPiringan > 10){
            printf("\nJumlah piringan melewati batas minimum/maximum.\n");
        }
    } while(jumlahPiringan < 1 || jumlahPiringan > 10);
    printf("\nSELAMAT BERMAIN!\n\n");
    fillSrc(jumlahPiringan);
    display(jumlahPiringan);
    while(win != 1){ // Saat kondisi akhir (menang) belum terpenuhi
        x = pop(&asal);
        push(x, asal, &moves); //Gerakan bertambah 1 tiap berhasil proses pemindahan
        win = gameWinCondition(jumlahPiringan);
        display(jumlahPiringan);
    }
    score = ((jumlahPiringan * 20) - (moves - (power(2, jumlahPiringan) - 1))) / 10; //Hitung skor akhir pemain
    printf("\n");
    printf("SELAMAT, KAMU BERHASIL!\n\n");
    printf("Total move: %d\n", moves);
    printf("Skor yang didapatkan: %d\n", score);
    return score;
}
