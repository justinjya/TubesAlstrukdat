#ifndef map_H
#define map_H
#include <stdio.h>
#include "../../boolean.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nil_M 0
#define MaxEl_M 10
#define Undefined_M -999

// typedef int bool;
typedef char* keytype;
typedef int valuetype;
typedef int address_M;

typedef struct {
	keytype Key;
	valuetype Value;
} infotype;

typedef struct {
	infotype Elements[MaxEl_M];
	address_M Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil_M */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty_M(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl_M */
/* Ciri Map kosong : count berNil_Mai Nil_M */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty_M(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count berNil_Mai Nil_M */

boolean IsFull_M(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count berNil_Mai MaxEl_M */

/* ********** Operator Dasar Map ********* */
valuetype Value_M(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined_M */

void Insert_M(Map *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete_M(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMember_M(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

boolean eq_string(char* string1, char* string2);
/* Mengembalikan nilai true jika string1 sama dengan string2
 * Mengembalikan nilai false jika string1 tidak sama dengan string2
 * Kedua string dikatakan sama apabila memiliki panjang yang sama dan huruf per hurufnya merupakan abjad yang sama.
 */ 

int SearchIndex(Map M, keytype k);
/* Mengembalikan index pertama kalinya ditemukan key k dari M
 */

void SortValueMap(Map *M, boolean ascending);
/* Mengembalikan Map M yang sudah disortir berdasatkan value
 * Mengembalikan hasil sortir ascending jika ascending = true
 * Mengembalikan hasil sortir decending jika ascending = false
 */

#endif
