#include ".\src\console.h"

int main()
{
    system("cls");
    ArrayDin Games;
    Queue GamesQueue;
    Games = MakeArrayDin();
    CreateQueue(&GamesQueue);

    boolean endProgram = false;
    char *command;
    command = (char *) malloc (50 * sizeof(char));

    printf("Selamat datang pada BNMO!\n\n");
    printf("Jalankan command START atau LOAD <filename tanpa .txt> untuk membuka file.\n");
    printf("Jalankan command QUIT untuk keluar dari program.\n");
    while (endProgram == false)
    {
        printf("\nENTER COMMAND: ");
        inputString(0, command);
        system("cls");
        if (IsEmpty(Games))
        {
            if (compareString(command, "START") == true)
            {
                STARTBNMO(&Games);
            }
            else if (compareString(command, "LOAD") == true)
            {
                char *inputfile;
                inputfile = (char *) malloc (50 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, inputfile);
                LOADFILE(&Games, inputfile);
            }
            else if (compareString(command, "QUIT") == true)
            {
                QUIT(&Games, &GamesQueue);
                endProgram = true;
            }
            else if (compareString(command, "HELP") == true)
            {
                HELP(0);
            }
            else
            {
                printf("Belum ada file yang dibuka. Silahkan buka file terlebih dahulu.\n");
                printf("Jalankan command START atau LOAD <filename> untuk membuka file.\n");
                printf("Jalankan command QUIT untuk keluar dari program.\n");
            }
        }
        else
        {
            if (compareString(command, "SAVE") == true)
            {
                char *inputfile;
                inputfile = (char *) malloc (50 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, inputfile);
                SAVE(&Games, inputfile);
            }
            else if (compareString(command, "CREATE") == true)
            {
                char *game;
                game = (char *) malloc (10 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, game);
                if (compareString(game, "GAME") == true)
                {
                    CREATEGAME(&Games);
                }
            }
            else if (compareString(command, "LIST") == true)
            {
                char *game;
                game = (char *) malloc (10 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, game);
                if (compareString(game, "GAME") == true)
                {
                    LISTGAME(&Games);
                }
            }
            else if (compareString(command, "DELETE") == true)
            {
                char *game;
                game = (char *) malloc (10 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, game);
                if (compareString(game, "GAME") == true)
                {
                    DELETEGAME(&Games);
                }
            }
            else if (compareString(command, "QUEUE") == true)
            {
                char *game;
                game = (char *) malloc (10 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, game);
                if (compareString(game, "GAME") == true)
                {
                    QUEUEGAME(&Games, &GamesQueue);
                }
            }
            else if (compareString(command, "PLAY") == true)
            {
                char *game;
                game = (char *) malloc (10 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, game);
                if (compareString(game, "GAME") == true)
                {
                    PLAYGAME(&Games, &GamesQueue);
                }
            }
            else if (compareString(command, "SKIPGAME") == true)
            {
                ADVWORD(0);
                if (currentChar == '\n')
                {
                    printf("test\n");
                }
                int skips;
                skips = wordToInteger(currentWord);
                SKIPGAME(&Games, &GamesQueue, skips);
            }
            else if (compareString(command, "QUIT") == true)
            {
                QUIT(&Games, &GamesQueue);
                endProgram = true;
            }
            else if (compareString(command, "HELP") == true)
            {
                HELP(1);
            }
            else
            {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
    }
}
