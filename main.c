#include "./src/console.c"

int main()
{
    system("cls||clear");
    srand(time(NULL));
    
    ArrayDin Games;
    Stack History;
    Queue GamesQueue;
    ArrayDin_SB Scoreboard;

    Games = MakeArrayDin(); 
    CreateQueue(&GamesQueue);
    CreateEmptyStack(&History);

    boolean saved = false;
    boolean endProgram = false;
    char *command;
    command = (char *) malloc (50 * sizeof(char));

    printf("                                  PERINGATAN!!!\n");
    printf("======================================================================================\n");
    printf("PROGRAM AKAN ERROR ATAU BERHENTI KETIKA MENJALANKAN COMMAND YANG MEMILIKI KARAKTER '.'\n");
    printf("======================================================================================\n\n");
    printf("Selamat datang pada BNMO!\n\n");
    printf("Jalankan command START atau LOAD <filename tanpa .txt> untuk membuka file.\n");
    printf("Jalankan command QUIT untuk keluar dari program.");
    while (endProgram == false)
    {
        printf("\nJalankan command HELP untuk melihat daftar commands yang tersedia.");
        printf("\nENTER COMMAND: ");
        inputString(0, command);
        system("cls||clear");
        if (IsEmpty(Games))
        {
            if (compareString(upper(command), "START") == true)
            {
                STARTBNMO(&Games, &History, &GamesQueue, &Scoreboard);
            }
            else if (compareString(upper(command), "LOAD") == true)
            {
                char *inputfile;
                inputfile = (char *) malloc (30 * sizeof(char));
                ADVWORD(0);
                if (currentChar == '\n')
                {
                    wordToString(currentWord, inputfile);
                    if (compareString(upper(inputfile), "LOAD") == false)
                    {
                        LOADFILE(&Games, &History, &GamesQueue, &Scoreboard, inputfile, false);
                    }
                    else
                    {
                        printf("Command belum memiliki parameter. Silahkan input command sesuai format LOAD <filename tanpa .txt>\n");
                    }
                }
            }
            else if (compareString(upper(command), "QUIT") == true)
            {
                QUIT(&Games, &GamesQueue, &History, &Scoreboard, true);
                endProgram = true;
            }
            else if (compareString(upper(command), "HELP") == true)
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
            if (compareString(upper(command), "SAVE") == true)
            {
                char *inputfile;
                inputfile = (char *) malloc (50 * sizeof(char));
                ADVWORD(0);
                if (currentChar == '\n')
                {
                    wordToString(currentWord, inputfile);
                    if (compareString(upper(inputfile), "SAVE") == false)
                    {
                        SAVE(&Games, &History, &Scoreboard, inputfile);   
                        saved = true;
                    }
                    else
                    {
                        printf("Command belum memiliki parameter. Silahkan input command sesuai format SAVE <filename tanpa .txt>\n");
                    }
                }
            }
            else if (compareString(upper(command), "CREATE") == true)
            {
                char *game;
                game = (char *) malloc (10 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, game);
                if (compareString(upper(game), "GAME") == true)
                {
                    CREATEGAME(&Games, &Scoreboard, &saved);
                }
                else
                {
                    printf("Command tidak dikenali, apakah yang Anda maksud CREATE GAME?\n");
                }
            }
            else if (compareString(upper(command), "LIST") == true)
            {
                char *game;
                game = (char *) malloc (10 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, game);
                if (compareString(upper(game), "GAME") == true)
                {
                    LISTGAME(&Games);
                }
                else
                {
                    printf("Command tidak dikenali, apakah yang Anda maksud LIST GAME?\n");
                }
            }
            else if (compareString(upper(command), "DELETE") == true)
            {
                char *game;
                game = (char *) malloc (10 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, game);
                if (compareString(upper(game), "GAME") == true)
                {
                    DELETEGAME(&Games, &GamesQueue, &Scoreboard, &saved);
                }
                else
                {
                    printf("Command tidak dikenali, apakah yang Anda maksud DELETE GAME?\n");
                }
            }
            else if (compareString(upper(command), "QUEUE") == true)
            {
                char *game;
                game = (char *) malloc (10 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, game);
                if (compareString(upper(game), "GAME") == true)
                {
                    QUEUEGAME(&Games, &GamesQueue);
                }
                else
                {
                    printf("Command tidak dikenali, apakah yang Anda maksud QUEUE GAME?\n");
                }
            }
            else if (compareString(upper(command), "PLAY") == true)
            {
                char *game;
                game = (char *) malloc (10 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, game);
                if (compareString(upper(game), "GAME") == true)
                {
                    PLAYGAME(&Games, &GamesQueue, &History, &Scoreboard);
                    saved = false;
                }
                else
                {
                    printf("Command tidak dikenali, apakah yang Anda maksud PLAY GAME?\n");
                }
            }
            else if (compareString(upper(command), "SKIP") == true)
            {
                char *game;
                game = (char *) malloc (10 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, game);
                if (compareString(upper(game), "GAME") == true)
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
                            SKIPGAME(&Games, &GamesQueue, &History, &Scoreboard, skips);
                            saved = false;
                        }
                    }
                }
                else
                {
                    printf("Command tidak dikenali, apakah yang Anda maksud SKIP GAME <skips>?\n");
                }
            }
            else if (compareString(upper(command), "SCOREBOARD") == true)
            {
                SCOREBOARD(Scoreboard, Games);
            }
            else if (compareString(upper(command), "HISTORY") == true)
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
            else if (compareString(upper(command), "RESET") == true)
            {
                char *wordAfter;
                wordAfter = (char *) malloc (13 * sizeof(char));
                ADVWORD(0);
                wordToString(currentWord, wordAfter);
                if (compareString(upper(wordAfter), "HISTORY") == true)
                {
                    RESETHISTORY(&History);
                    saved = false;
                }
                else if (compareString(upper(wordAfter), "SCOREBOARD") == true)
                {
                    RESETSCOREBOARD(&Games, &Scoreboard);
                    saved = false;
                }
                else
                {
                    printf("Command tidak dikenali, apakah yang Anda maksud RESET HISTORY/RESET SCOREBOARD?\n");
                }
            }
            else if (compareString(upper(command), "QUIT") == true)
            {
                QUIT(&Games, &GamesQueue, &History, &Scoreboard, saved);
                endProgram = true;
            }
            else if (compareString(upper(command), "HELP") == true)
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
