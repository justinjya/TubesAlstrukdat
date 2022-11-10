#ifndef __PROCESSEDORDER__
#define __PROCESSEDORDER__

#include "../../boolean.h"

#define InitialSize 10

typedef int IdxType;
typedef struct
{
    char* makanan;
    int sisa_durasi_or_ketahanan_masakan;
} masakan;

typedef struct {
    masakan *A;
    int Capacity;
    int Neff;
} processedorder;
/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk processedorder berupa pesanan yang sedang dimasak(kosong) atau pesanan yang ready to serve (kosong) dengan ukuran size
 */
processedorder MakeProcessedOrder(int size);
/*
 * I.S. sembarang
 * F.S. Terbentuk masakan berupa makanan serta sisa_durasi_or_ketahanan_masakan
*/
masakan MakeMasakan(char* makanan, int sisa_durasi_or_ketahanan_masakan);

/**
 * Fungsi untuk mengetahui apakah suatu processedorder kosong.
 * Prekondisi: processedorder terdefinisi
 */
boolean IsProcessedOrderEmpty(processedorder processedorder);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif processedorder, 0 jika tabel kosong.
 * Prekondisi: processedorder terdefinisi
 */
int LengthOfProcessedOrder(processedorder processedorder);

/**
 * Mengembalikan elemen processedorder yang ke-i (indeks lojik).
 * Prekondisi: processedorder tidak kosong, i di antara 0..LengthOfProcessedOrder(processedorder).
 */
masakan GetProcessedOrder(processedorder processedorder, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas processedorder yang tersedia.
 * Prekondisi: processedorder terdefinisi
 */
int GetProcessedOrderCapacity(processedorder processedorder);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: processedorder terdefinisi, i di antara 0..LengthOfProcessedOrder(processedorder).
 */
void InsertProcessedOrderAt(processedorder *processedorder, masakan masakkan, IdxType i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir processedorder.
 * Prekondisi: processedorder terdefinisi
 */
void InsertProcessedOrderLast(processedorder *processedorder, masakan masakkan);

/**
 * Fungsi untuk menambahkan elemen baru di awal processedorder.
 * Prekondisi: processedorder terdefinisi
 */
void InsertProcessedOrderFirst(processedorder *processedorder, masakan masakkan);

/**
 * Fungsi untuk menghapus elemen di index ke-i processedorder
 * Prekondisi: processedorder terdefinisi, i di antara 0..LengthOfProcessedOrder(processedorder).
 */
void DeleteProcessedOrderAt(processedorder *processedorder, IdxType i);

/**
 * Fungsi untuk menghapus elemen terakhir processedorder
 * Prekondisi: processedorder tidak kosong
 */
void DeleteProcessedOrderLast(processedorder *processedorder);

/**
 * Fungsi untuk menghapus elemen pertama processedorder
 * Prekondisi: processedorder tidak kosong
 */
void DeleteProcessedOrderFirst(processedorder *processedorder);

/**
 * Fungsi untuk melakukan search suatu processedorder.
 * Prekondisi: processedorder terdefinisi
 */
IdxType SearchMasakan(processedorder processedorder, masakan masakkan);
#endif