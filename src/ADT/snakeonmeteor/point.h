#ifndef POINT_H
#define POINT_H
#include "../../boolean.h"

/**** Definisi Abstract Data Type POINT ****/
typedef struct Point {
int x; /* absis */
int y; /* ordinat */
} point;

/**** Selektor point ****/
#define ABSIS(p) (p).x
#define ORDINAT(p) (p).y

/**** Konstruktor POINT ****/
point CreatePoint (int x, int y);
/* Membentuk sebuah point dari x dan y dengan x sebagai absis dan y sebagai ordinat */

/**** Predikat ****/
boolean isOrigin (point p);
/* Mengirimkan nilai benar jika p adalah titik origin yaitu titik <0,0> */

/**** Prosedur - Interaksi dengan I/O device, BACA/TULIS ****/
void displayPoint (point p);
/* Nilai p ditulis ke layar dg format "<X,Y>" */

/**** Fungsi/Operasi lain terhadap point ****/
point move (point p, int dx, int dy);
/* Menghasilkan point yang merupakan hasil penggeseran p */
/* sebesar dx arah sumbu x dan dy arah sumbu y */
#endif