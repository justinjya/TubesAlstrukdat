#ifndef __CONSOLE__
#define __CONSOLE__

#include "./ADT/arraydin/arraydin.h"
#include "./ADT/mesinkarakter/mesinkarakter.h"
#include "./ADT/mesinkata/mesinkata.h"
// #include "./ADT/queue/queue.h"


/* Membaca file konfigurasi default yang berisi list game
 * yang akan dimainkan.
 */
void STARTBNMO(ArrayDin *Games);

/* Membaca file konfigurasi dari input pemain yang berisi list
 * game yang dapat dimainkan, dan histori game.
 */
void LOADFILE(ArrayDin *Games, ArrayDin *History, char *inputfile);

/* Menyimpan state game pemain saat ini ke dalam suatu file
 * yang merupakan input dari pemain.
 */
void SAVE(ArrayDin *Games, ArrayDin *History, char *inputfile);

/* Menambahkan game baru pada daftar game.
 */
void CREATEGAME();

/* Menampilkan daftar game yang disediakan oleh sistem
 */
void LISTGAME();

/* Menghapus sebuah game dari daftar game. Aturan penghapusan :
 * - Game yang dapat dihapus hanya game yang dibuat secara
 *   custom oleh pengguna.
 * - 5 game pertama pada file konfigurasi tidak dapat dihapus.
 * - Game yang saat itu terdapat di dalam queue game tidak dapat dihapus.
 */
void DELETEGAME();

/* Mendaftarkan permainan kedalam list. List queue akan hilang ketika
 * pemain menjalankan command QUIT.
 */
void QUEUEGAME();

/* Memainkan sebuah permainan sesuai permainan yang tersedia oleh
 * sistem. Jika suatu permainan tidak dapat dimainkan akan menampilkan
 * pesan bahwa game tidak dapat dimainkan.
 */
void PLAYGAME();

/* Melewatkan permainan sebanyak n kali.
 */
void SKIPGAME();

/* Keluar dari program.
 */
void QUIT();

/* Menampilan daftar command-command yang dapat dijalankan
 * oleh pemain.
 */
void HELP();

/* RNG (Random Number Generator) merupakan permainan yang membuat pemain
 * menebak angka X.
 */
void RNG();

/* 
 */
void DINERDASH();

/* Permainan buatan pemain yang dibuat dengan command CREATE GAME yang
 * akan langsung selesai dan masuk ke tahap game over dengan skor akhir
 * berupa integer random.
 */
void GAMEBUATAN();

#endif
