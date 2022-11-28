#include "../functions.h"

/* RNG (Random Number Generator) merupakan permainan yang membuat pemain
 * menebak angka X.
 */

int RNG(){
	int jumlah, angka, tebak, skor;
    boolean nyerah;
    angka = randomNumber(1, 100);
    jumlah = 0;
    nyerah = false;

    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("X berada pada rentang angka 1 - 100\n");
    printf("Masukkan '0' jika ingin menyerah.\n");
    while (tebak != angka && nyerah == false){
        printf("Tebakan: ");
        inputInteger(&tebak);
        if (tebak < 0 || tebak > 100){
            printf("Masukan tidak valid.\n");
        }
        else{
        jumlah += 1;
        if (tebak == 0) {
            nyerah = true;
            jumlah = 25;
        } else if (tebak > angka){
            printf("Lebih kecil\n");
        } else if (tebak < angka){
            printf("Lebih besar\n");
        }
        }
    }
    if (nyerah == true){
        printf("\n");
        printf("Anda kurang beruntung, X adalah %d \n", angka);
    } else if (tebak == angka && nyerah == false){
        printf("\n");
        printf("Ya, X adalah %d \n", angka);
    }
    skor = (25-jumlah)*4;
    printf("Skor akhir: %d\n", skor);
    // INPUTNAMASCOREBOARD(skor);
    return skor;
}
