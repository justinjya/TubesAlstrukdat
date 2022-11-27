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
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt_SB(ArrayDin_SB *array, ElType_SB el, IdxType i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast_SB(ArrayDin_SB *array, ElType_SB el);

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst_SB(ArrayDin_SB *array, ElType_SB el);

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin_SB
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt_SB(ArrayDin_SB *array, IdxType i);

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin_SB
 * Prekondisi: array tidak kosong
 */
void DeleteLast_SB(ArrayDin_SB *array);

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin_SB
 * Prekondisi: array tidak kosong
 */
void DeleteFirst_SB(ArrayDin_SB *array);

/**
 * Fungsi untuk melakukan print suatu ArrayDin_SB.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin_SB(ArrayDin_SB array);

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin_SB.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin_SB(ArrayDin_SB *array);

/**
 * Fungsi untuk melakukan copy suatu ArrayDin_SB.
 * Prekondisi: array terdefinisi
 */
ArrayDin_SB CopyArrayDin_SB(ArrayDin_SB array);

/**
 * Fungsi untuk melakukan search suatu ArrayDin_SB.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin_SB(ArrayDin_SB array, ElType_SB el);

#endif