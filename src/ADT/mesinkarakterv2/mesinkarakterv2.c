/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkarakterv2.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START(char *directory, int type)
{
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
                 Jika currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       if (directory == NULL) // Untuk dipakai menerima input
       {
              pita = stdin;
       }
       else
       {
              pita = fopen(directory, "r"); // Untuk dipakai membaca file
       }
       ADV(type);
}

void ADV(int type)
{
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARK
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARK.
                       Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       retval = fscanf(pita, "%c", &currentChar);
       if(type == 1){
            EOP = (currentChar == MARK);
            if (EOP)
            {
                    fclose(pita);
            }
       }
       else if(type == 0){
            EOP = (currentChar == MARK2);
            if (EOP){
                fclose(pita);
            }
       }
}
