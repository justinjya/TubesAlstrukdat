#include <stdio.h>
#include "point.h"
/**** Konstruktor POINT ****/
point CreatePoint (int x, int y) {
/* Membentuk sebuah point p dari x dan y dengan x sebagai absis dan y sebagai
ordinat */
    point p;
    ABSIS(p) = x;
    ORDINAT(p) = y;
    return p;
}

/**** Predikat ****/
boolean isOrigin (point p) {
/* Mengirimkan nilai benar jika p adalah titik origin yaitu titik <0,0> */
    return ((ABSIS(p) == 0) && (ORDINAT(p) == 0));
}

/**** Prosedur - Interaksi dengan I/O device, BACA/TULIS ****/
void displayPoint (point p) {
/* Nilai p ditulis ke layar dg format "(X,Y)" */
    printf("<%d,%d>", ABSIS(p), ORDINAT(p));
}

/**** Fungsi/Operasi lain terhadap point ****/
point move (point p, int dx, int dy) {
/* Menghasilkan point yang merupakan hasil penggeseran p */
/* sebesar dx arah sumbu x dan dy arah sumbu y */
    return (CreatePoint(ABSIS(p)+dx, ORDINAT(p)+dy));
}