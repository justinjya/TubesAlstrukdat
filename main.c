#include ".\src\console.c"

int main()
{
    ArrayDin Games;
    ArrayDin Queue;
    ArrayDin History;
    Games = MakeArrayDin();
    Queue = MakeArrayDin();
    History = MakeArrayDin();

    boolean endProgram = false;
    char *command;

    printf("Selamat datang pada BNMO\n");
    printf("Jalankan command START atau LOAD <filename> untuk membuka file.\n");
    while (endProgram == false)
    {
        printf("\nENTER COMMAND: ");
        inputString(0, command);
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
                LOADFILE(&Games, &History, inputfile);
            }
            else
            {
                printf("Belum ada file yang dibuka. Silahkan buka file terlebih dahulu.\n");
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
        }
    }
}
