#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./ADT/arraydin/arraydin.h"
#include "./ADT/mesinkarakterv2/mesinkarakterv2.h"
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/queue/queue.h"
// #include "./ADT/dinerdash/processedorder.h"
// #include "./ADT/dinerdash/circular_queue_of_pesanan.h"

/* Membandingkan string1 dengan string2
 * Mengeluarkan 1 bila string1 = string2
 * Mengeluarkan 2 bila string1 != string2
 */
boolean compareString(char *string1, char *string2);

/* Menggabungkan string1 dengan string2
 * Hasil penggabungan menjadi string3
 */
void concat(char *string1, char *string2, char *string3);

/* Mengubah type Word menjadi type char
 * Mengisi string dengan isi currentWord.TabWord
 */
void wordToString(Word currentWord, char *string);

/* Mengubah type Word menjadi type int
 *
 * Contoh pemakaian:
 * int value;
 * value = wordToString(currentWord)
 */
int wordToInteger(Word currentWord);

/* Menerima input stdin yang kemudian diubah menjadi string
 * type = 0 -> Menggunakan mesinkata type 0 (Memisahkan setiap word dengan blank)
 * type = 1 -> Menggunakan mesinkata type 1 (Memisahkan setiap word dengan newline)
 *
 * Contoh pemakaian:
 * char *string;
 * string = (char *) malloc (n * sizeof(char));
 * inputString(0, string);
 */
void inputString(int type, char* value);

/* Menerima input stdin yang kemudian diubah menjadi integer
 *
 * Contoh pemakaian:
 * int value;
 * inputInteger(&value);
 */
void inputInteger(int *value);

/*
*/



/* Membaca file konfigurasi default yang berisi list game
 * yang akan dimainkan.
 */
void STARTBNMO(ArrayDin *Games);

/* Membaca file konfigurasi dari input pemain yang berisi list
 * game yang dapat dimainkan, dan histori game.
 */
void LOADFILE(ArrayDin *Games, char *inputfile);

/* Menyimpan state game pemain saat ini ke dalam suatu file
 * yang merupakan input dari pemain.
 */
void SAVE(ArrayDin *Games, char *inputfile);

/* Menambahkan game baru pada daftar game.
 */
void CREATEGAME(ArrayDin *arrayGames);

/* Menampilkan daftar game yang disediakan oleh sistem
 */
void LISTGAME(ArrayDin *arrayGames);

/* Menghapus sebuah game dari daftar game. Aturan penghapusan :
 * - Game yang dapat dihapus hanya game yang dibuat secara
 *   custom oleh pengguna.
 * - 5 game pertama pada file konfigurasi tidak dapat dihapus.
 * - Game yang saat itu terdapat di dalam queue game tidak dapat dihapus.
 */
void DELETEGAME(ArrayDin *arrayGames);

/* Mendaftarkan permainan kedalam list. List queue akan hilang ketika
 * pemain menjalankan command QUIT.
 */
void QUEUEGAME(ArrayDin *Games, Queue *Queue);

/* Memainkan sebuah permainan sesuai permainan yang tersedia oleh
 * sistem. Jika suatu permainan tidak dapat dimainkan akan menampilkan
 * pesan bahwa game tidak dapat dimainkan.
 */
void PLAYGAME(ArrayDin *arraygame, Queue *queuegame);

/* Melewatkan permainan sebanyak n kali.
 */
void SKIPGAME(ArrayDin *arraygame, Queue *queuegame, int skips);

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
int random_number(int lowerlimit, int upperlimit);
/*
  Menerima input berupa dua buah integer, yaitu batas bawah dan batas atas dari angka yang ingin dikembalikan. Mengembalikan integer yang berada di batas bawah dan batas atas
*/
char* food_id_generator(int id);
/*
  Menerima input berupa id bertipe integer serta mengembalikan Food ID bertipe char* dengan format "M(id)"
*/

char* getCurrentWord(Word string);
/*
  Menerima input berupa sebuah Word dan mengembalikan pointer to char dari Word.TabWord sesuai dengan Word.Length
*/

void PrintUIPesanan(QueueOfPesanan pesanan);
/*Menampikan daftar pesanan di Diner Dash
  Menerima input berupa sebuah QueueOfPesanan
*/

void PrintUIOnCook(processedorder oncook);
/*Menampilkan daftar pesanan yang sedang dimasak di Diner Dash
  Menerima input berupa sebuah processedorder
*/

void PrintUIReadyToServe(processedorder readytoserve);
/*Menampilkan daftar pesanan yang siap untuk disajikan di Diner Dash
  Menerima input berupa processedorder
*/

int stringlen(char* string);
/*Mengembalikan panjang dari sebuah string
 Menerima input berupa pointer to char 
*/

void GAMEBUATAN();

#endif
