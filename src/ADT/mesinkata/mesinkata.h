/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "C:\Users\Legion\OneDrive - Institut Teknologi Bandung\vscode\C\tubes\src\boolean.h"
#include "C:\Users\Legion\OneDrive - Institut Teknologi Bandung\vscode\C\tubes\src\ADT\mesinkarakterv2\mesinkarakterv2.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks(int type);
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(char *directory, int type);
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata 
    type = 0 -> Untuk membaca karakter hingga newline, dipakai ketika menerima input stdin 
    type = 1 -> Untuk membaca karakter hingga newline atau mark, dipakai ketika membaca pita dari file */

void ADVWORD(int type);
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord
   type = 0 -> Untuk membaca karakter hingga newline, dipakai ketika menerima input stdin 
   type = 1 -> Untuk membaca karakter hingga newline atau mark, dipakai ketika membaca pita dari file */

void CopyWord(int type);
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong"
    type = 0 -> Untuk membaca karakter hingga newline, dipakai ketika menerima input stdin 
    type = 1 -> Untuk membaca karakter hingga newline atau mark, dipakai ketika membaca pita dari file */

boolean isEndWord();

#endif
