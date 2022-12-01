#include "../functions.h"

// Membaca kata-kata dari file
ArrayDin loadHangman(){
    ArrayDin arr;
    arr = MakeArrayDin();
    char *temp;
    #ifdef _WIN32
        STARTWORD(".\\data\\hangman.txt", 1);
    #else
        STARTWORD("./data/hangman.txt");
    #endif
    while (currentChar != MARK){
        temp = (char *) malloc (25 * sizeof(char));
        wordToString(currentWord, temp);
        InsertLast(&arr, temp);
        ADVWORD(1);
    }
    return arr;
}

// Menampilkan string dengan pemisah spasi diantara karakter-karakter
void printStringWithSpaces(char *string){
    int i = 0;
    while (string[i] != '\0'){
        printf("%c ", string[i]);
        i++;
    }
}

// Permainan menebak suatu kata hingga kesempatan menebak habis
int HANGMAN(){
    ArrayDin listkata, listsudahtebak;
    listkata = loadHangman();
    listsudahtebak = MakeArrayDin();
    int kesempatan=10;
    int angka;
    int skor, skortotal;
    skortotal = 0;
    boolean valid, start, answer, benarsemua, udahada;

    valid = false;
    start = false;
    char *input;
    input = (char *) malloc (25 * sizeof(char));
    printf("\n==================================== HANGMAN ====================================\n");
    printf("Hangman merupakan permainan menebak kata dengan menebak satu-satu huruf yang ada\n");
    printf("pada kata. Pemain memiliki 10 kesempatan dalam bermain. Jika pemain berhasil\n");
    printf("menebak kata, maka pemain akan mendapatkan poin sesuai panjang kata yang\n");
    printf("berhasil ditebak, dan permainan akan berlanjut sampai kesempatan habis.\n\n");
    while (!valid){
        printf("Pilihan menu:\n");
        printf("  1. Bermain langsung\n");
        printf("  2. Menambahkan kata-kata ke dalam sistem\n");
        printf("Masukkan pilihan menu: ");
        inputString(0, input);
        if (compareString(input,"1") || compareString(input, "2")){
            valid = true;
        } else {
            printf("\nMasukan tidak valid.\n\n");
        }
    }

    if (valid){
        if (compareString(input, "2")){
            char *inputkata;
            inputkata = (char *) malloc (20 * sizeof(char));
            printf("\nSilahkan menambahkan kata-kata ke dalam sistem.");
            while (!compareString(upper(inputkata), "SUDAH")){ // 2 merupakan hasil input karakter enter
                printf("\nKetik SUDAH ketika selesai menambahkan kata.\n");
                printf("Masukkan kata: ");
                inputString(0, inputkata);
                if (!compareString(upper(inputkata), "SUDAH")){ // 2 merupakan hasil input karakter enter
                    if (SearchArrayDin(listkata, upper(inputkata)) == -1){
                        InsertLast(&listkata, upper(inputkata));
                        printf("\nBerhasil menambahkan kata %s ke dalam sistem.\n", upper(inputkata));
                    } else {
                        printf("\nKata sudah terdaftar dalam sistem. Silahkan masukkan kata lain.\n");
                    }
                }
            }
            start = true;
        } else if (compareString(input, "1")){
            start = true;
        } 

        if (start){
            system("cls||clear");
            printf("\nSelamat bermain!\n\n");
            while (kesempatan > 0){
                char *tebak = (char*) malloc (10 * sizeof(char));
                char *soal = (char*) malloc (100* sizeof(char));
                char *jawab = (char*) malloc (100* sizeof(char));
                char *udah = (char*) malloc (11* sizeof(char));
                int i=0;
                int index=0;
                angka = randomNumber(0, listkata.Neff);
                while (SearchArrayDin(listsudahtebak, listkata.A[angka]) != -1){
                    angka = randomNumber(0, listkata.Neff);
                }
                soal = listkata.A[angka];
                while (soal[index] != '\0'){
                    jawab[index] = '_';
                    index++;
                }
                jawab[index] = '\0';
                udah[0] = '-';
                udah[1] = '\0';
                printf("Kategori: ");
                if (angka < 10){
                    printf("Kota\n");
                } else if (angka >= 10 && angka < 20){
                    printf("Barang\n");
                } else if (angka >= 20 && angka < 30){
                    printf("Makanan\n");
                } else {
                    printf("Kata buatan\n");
                }
                printf("Tebakan sebelumnya: ");
                printStringWithSpaces(udah); printf("\n");
                printStringWithSpaces(jawab); printf("\n");
                printf("Kesempatan: %d\n", kesempatan);
                benarsemua = false;
                while (!benarsemua && kesempatan > 0){
                    udahada = false;
                    answer = false;
                    printf("Masukkan tebakan: ");
                    inputString(0, tebak);
                    if (stringLen(tebak) == 1 && ((tebak[0] >= 'A' && tebak[0] <= 'Z') || (tebak[0] >= 'a' && tebak[0] <= 'z'))){
                        if (tebak[0] > 90){
                            tebak[0] -= 32;
                        }
                        int h=0;
                        while(!udahada && h < stringLen(soal)){
                            if(tebak[0] == udah[h]){
                                udahada = true;
                            }
                            h++;
                        }
                        if (udahada){
                            printf("Huruf sudah ditebak sebelumnya\n");
                        } else {
                            udah[i] = tebak[0]; 
                            i++;
                        }
                        index = 0;
                        while (soal[index] != '\0'){
                            if (tebak[0] == soal[index]){
                                jawab[index] = tebak[0];
                                answer = true;
                                }
                            index++;
                        }
                        udah[i] = '\0';
                        if (!answer && !udahada){
                            kesempatan--;
                        }
                        printf("\nTebakan sebelumnya: ");
                        printStringWithSpaces(udah); printf("\n");
                        printStringWithSpaces(jawab); printf("\n");
                        printf("Kesempatan = %d\n", kesempatan);
                    
                        int j = 0;
                        int count=0;
                        while (soal[j] != '\0'){
                            if (jawab[j] == soal[j]){
                                count++;
                            }
                            j++;
                        }
                        if (count == stringLen(soal)){
                            InsertLast(&listsudahtebak, soal);
                            skor = stringLen(soal);
                            skortotal += skor;
                            printf("\nSelamat anda berhasil menebak kata ");
                            printf("%s\n", jawab);
                            printf("Kamu mendapatkan %d poin\n\n", skor);
                            benarsemua = true;
                        }
                    } else {
                        printf("\nMasukan tidak valid.\n");
                        printf("\nTebakan sebelumnya: ");
                        printStringWithSpaces(udah); printf("\n");
                        printStringWithSpaces(jawab); printf("\n");
                        printf("Kesempatan = %d\n", kesempatan);
                    }
                }
            }
            printf("Skor akhir: %d\n", skortotal);
        }
    }
    FILE *open;
    open = fopen(".\\data\\hangman.txt", "w");
    for (int i = 0; i < listkata.Neff; i++){
        fprintf(open, "%s\n", listkata.A[i]);
    }
    fprintf(open, ".");
    fclose(open);
    return skortotal;
}
