#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "includes.h"

/* Permainan buatan pemain yang dibuat dengan command CREATE GAME yang
 * akan langsung selesai dan masuk ke tahap game over dengan skor akhir
 * berupa integer random.
 */
void GAMEBUATAN();

/* Membaca file konfigurasi dari input pemain yang berisi list
 * game yang dapat dimainkan, dan histori game.
 */
void LOADFILE(ArrayDin *Games, Stack *History, Queue *GamesQueue, ArrayDin_SB *Scoreboard, char *inputfile, boolean Start);

/* Membaca file konfigurasi default yang berisi list game
 * yang akan dimainkan.
 */
void STARTBNMO(ArrayDin *Games, Stack *History, Queue *GamesQueue, ArrayDin_SB *Scoreboard);

/* Menyimpan state game pemain saat ini ke dalam suatu file
 * yang merupakan input dari pemain.
 */
void SAVE(ArrayDin *Games, Stack *History, ArrayDin_SB *Scoreboard, char *inputfile);

/* Menampilkan daftar game yang disediakan oleh sistem
 */
void LISTGAME(ArrayDin *arrayGames);

/* Menambahkan game baru pada daftar game.
 */
void CREATEGAME(ArrayDin *arrayGames, ArrayDin_SB *Scoreboard, boolean *saved);

/* Menghapus sebuah game dari daftar game. Aturan penghapusan :
 * - Game yang dapat dihapus hanya game yang dibuat secara
 *   custom oleh pengguna.
 * - 5 game pertama pada file konfigurasi tidak dapat dihapus.
 * - Game yang saat itu terdapat di dalam queue game tidak dapat dihapus.
 */
void DELETEGAME(ArrayDin *arrayGames, Queue *queueGames, ArrayDin_SB *scoreboard, boolean *saved);

/* Mendaftarkan permainan kedalam list. List queue akan hilang ketika
 * pemain menjalankan command QUIT.
 */
void QUEUEGAME(ArrayDin *Games, Queue *Queue);

/* Memainkan sebuah permainan sesuai permainan yang tersedia oleh
 * sistem. Jika suatu permainan tidak dapat dimainkan akan menampilkan
 * pesan bahwa game tidak dapat dimainkan.
 */
void PLAYGAME(ArrayDin *arraygame, Queue *queuegame, Stack *history, ArrayDin_SB *scoreboard);

/* Melewatkan permainan sebanyak n kali.
 */
void SKIPGAME(ArrayDin *arraygame, Queue *queuegame, Stack *history, ArrayDin_SB *scoreboard, int skips);

/* Keluar dari program.
 */
void QUIT(ArrayDin *Games, Queue *GamesQueue, Stack *History, ArrayDin_SB *Scoreboard, boolean saved);

/* Menampilan daftar command-command yang dapat dijalankan
 * oleh pemain.
 */
void HELP(int type);

/* Menampilkan Scoreboard setiap Game yang tersedia dalam sistem
 */
void SCOREBOARD(ArrayDin_SB Scoreboard, ArrayDin Games);

/* Menghilangkan isi Scoreboard Game yang tersedia dalam sistem atau
 * Menghilangkan isi Scoreboard semua Game yang tersedia dalam sistem
 */
void RESETSCOREBOARD(ArrayDin *Games, ArrayDin_SB *Scoreboard);

/* Menampilkan history dari game yang telah dimainkan
*/
void HISTORY(Stack *history, int n);

/*Menghilangkan semua isi History yang tersedia dalam sistem
*/
void RESETHISTORY(Stack *history);

#endif
