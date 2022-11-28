#include "./src/console.h"

int main()
{
    system("cls");
    ArrayDin Games;
    Stack History;
    Queue GamesQueue;
    ArrayDin_SB Scoreboard;
    Games = MakeArrayDin();
    CreateEmptyStack(&History);
    CreateQueue(&GamesQueue);
    Scoreboard = MakeArrayDin_SB();

    boolean endProgram = false;
    char *command;
    command = (char *) malloc (50 * sizeof(char));

    printf("                                  PERINGATAN!!!\n");
    printf("======================================================================================\n");
    printf("PROGRAM AKAN ERROR ATAU BERHENTI KETIKA MENJALANKAN COMMAND YANG MEMILIKI KARAKTER '.'\n");
    printf("======================================================================================\n\n");
    printf("Selamat datang pada BNMO!\n\n");
    printf("Jalankan command START atau LOAD <filename tanpa .txt> untuk membuka file.\n");
    printf("Jalankan command QUIT untuk keluar dari program.\n");
    // printf("ArrayDinCapacity = %d\n", GetCapacity(Games));
    while (endProgram == false)
    {
        printf("\nENTER COMMAND: ");
        inputString(0, command);
        system("cls");
        if (IsEmpty(Games))
        {
            if (compareString(command, "START") == true)
            {
                STARTBNMO(&Games, &History);
            }
            else if (compareString(command, "LOAD") == true)
            {
                char *inputfile;
                inputfile = (char *) malloc (50 * sizeof(char));
                ADVWORD(0);
                if (currentChar == '\n')
                {
                    wordToString(currentWord, inputfile);
                    if (compareString(inputfile, "LOAD") == false)
                    {
                        LOADFILE(&Games, &History, inputfile, 6);
                    }
                    else
                    {
                        printf("Command belum memiliki parameter. Silahkan input command sesuai format LOAD <filename tanpa .txt>\n");
                    }
                }
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
                if (currentChar == '\n')
                {
                    wordToString(currentWord, inputfile);
                    if (compareString(inputfile, "SAVE") == false)
                    {
                        SAVE(&Games, &History, inputfile);   
                    }
                    else
                    {
                        printf("Command belum memiliki parameter. Silahkan input command sesuai format SAVE <filename tanpa .txt>\n");
                    }
                }
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
                else
                {
                    printf("Command tidak dikenali, apakah yang Anda maksud CREATE GAME?\n");
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
                else
                {
                    printf("Command tidak dikenali, apakah yang Anda maksud LIST GAME?\n");
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
                    DELETEGAME(&Games, &GamesQueue);
                }
                else
                {
                    printf("Command tidak dikenali, apakah yang Anda maksud DELETE GAME?\n");
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
                else
                {
                    printf("Command tidak dikenali, apakah yang Anda maksud QUEUE GAME?\n");
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
                    PLAYGAME(&Games, &GamesQueue, &History);
                }
                else
                {
                    printf("Command tidak dikenali, apakah yang Anda maksud PLAY GAME?\n");
                }
            }
            else if (compareString(command, "SKIP") == true)
            {
                char *game;
                game = (char *) malloc (10 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, game);
                if (compareString(game, "GAME") == true)
                {
                    ADVWORD(0);
                    if (currentChar == '\n')
                    {   
                        int skips;
                        skips = wordToInteger(currentWord);
                        if (skips == -9999)
                        {
                            printf("Command belum memiliki parameter. Silahkan input command sesuai format SKIP GAME <skips>\n");
                        }
                        else
                        {
                            SKIPGAME(&Games, &GamesQueue, &History, skips);
                        }
                    }
                }
                else
                {
                    printf("Command tidak dikenali, apakah yang Anda maksud SKIP GAME <skips>?\n");
                }
            }
            else if (compareString(command, "SCOREBOARD") == true)
            {
                SCOREBOARD(Scoreboard, Games);
            }
            else if (compareString(command, "HISTORY") == true)
            {
                ADVWORD(0);
                if (currentChar == '\n')
                {
                    int n;
                    n = wordToInteger(currentWord);
                    if (n == -9999)
                    {
                        printf("Command belum memiliki parameter. Silahkan input command sesuai format HISTORY <skips>\n");   
                    }
                    else
                    {
                        HISTORY(&History, n);
                    }
                }
            }
            else if (compareString(command, "RESET") == true)
            {
                char *history;
                history = (char *) malloc (10 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, history);
                if (compareString(history, "HISTORY") == true)
                {
                    RESETHISTORY(&History);
                }
                else
                {
                    printf("Command tidak dikenali, apakah yang Anda maksud RESET HISTORY?\n");
                }
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
