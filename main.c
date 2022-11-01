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
    while (endProgram == false)
    {
        printf("\nENTER COMMAND: ");
        scanf("%s", command);
        if (compareString(command, "START") == true)
        {
            STARTBNMO(&Games);
        }
        else if (compareString(command, "LOAD") == true)
        {
            char *inputfile;
            inputfile = (char *) malloc (50 * sizeof(char));
            scanf("%s", inputfile);
            LOADFILE(&Games, &History, inputfile);
        }
        else if (compareString(command, "SAVE") == true)
        {
            char *inputfile;
            inputfile = (char *) malloc (50 * sizeof(char));
            scanf("%s", inputfile);
            SAVE(&Games, &History, inputfile);
        }
    }
}
