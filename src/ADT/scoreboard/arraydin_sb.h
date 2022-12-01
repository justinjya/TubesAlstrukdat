#ifndef __ARRAY_DINAMIK_SB__
#define __ARRAY_DINAMIK_SB__

// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#define InitialSize 10

#include "map.h"

typedef int IdxType;
typedef Map ElType_SB;
typedef struct {
    ElType_SB *A;
    int Capacity;
    int Neff;
} ArrayDin_SB;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin_SB kosong dengan ukuran InitialSize
 */
ArrayDin_SB MakeArrayDin_SB();

/**
 * Destruktor
 * I.S. ArrayDin_SB terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin_SB(ArrayDin_SB *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty_SB(ArrayDin_SB array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length_SB(ArrayDin_SB array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType_SB Get_SB(ArrayDin_SB array, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity_SB(ArrayDin_SB array);

/**
 * array mungkin penuh
 * Menambahkan Neff ArrayDin_SB
 * Digunakan ketika menamnbahkan Game baru
 */
void AddNeff_SB(ArrayDin_SB *array);

/**
 * array tidak kosong
 * Mengurangi Neff ArrayDin_SB
 * Digunakan ketika menghapus Game
 */
void SubNeff_SB(ArrayDin_SB *array);

#endif
