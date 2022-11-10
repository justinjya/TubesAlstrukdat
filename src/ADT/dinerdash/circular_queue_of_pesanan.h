/* MODUL CIRCULAR QUEUE */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Implementasi Queue menggunakan circular buffer (Alternatif III) */

#ifndef __circular_queue_of_pesanan_h__
#define __circular_queue_of_pesanan_h__

#include "../../boolean.h"

/* Nilai untuk indeks yang tidak terdefinisi */
#define NIL -999

/* Definisi tipe elemen dan indeks pada Queue */
typedef struct  { char* makanan;
                  int durasimasak;
                  int ketahanan;
                  int harga;
                } pesanan;

typedef int IdxType;

typedef struct { pesanan * Tab;  /* tabel penyimpan elemen */
                 IdxType HEAD;  /* indeks elemen paling awal (terdepan) */
                 IdxType TAIL;  /* indeks tempat menambah elemen baru */
                 int MaxEl;     /* kapasitas jumlah elemen */
               } QueueOfPesanan;
/* Definisi Queue kosong: HEAD=NIL; TAIL=NIL. */

/* ********* Prototype ********* */
boolean IsQueueOfPesananEmpty (QueueOfPesanan Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsQueueOfPesananFull (QueueOfPesanan Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int LengthQueueOfPesanan (QueueOfPesanan Q);
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
int MaxLengthQPesanan (QueueOfPesanan Q);
/* Mengirimkan kapasitas jumlah elemen Q */

/* *** Kreator *** */
pesanan CreatePesanan (char* makanan, int durasimasak, int ketahanan, int harga);
/* I.S. sembarang */
/* F.S. mengembalikan sebuah QElType yang sudah diisi dengan makanan, durasimasak, ketahanan, serta harga*/
QueueOfPesanan CreateQueueOfPesanan (int Max);
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxEl=0 */

/* *** Destruktor *** */
void DeleteQueueOfPesanan (QueueOfPesanan * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxEl di-set 0 */

/* *** Primitif Add/Delete *** */
void PushPesanan (QueueOfPesanan * Q, pesanan X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
pesanan PopPesanan (QueueOfPesanan * Q);
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
pesanan FrontPesanan (QueueOfPesanan Q);
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */

#endif  