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
        if (compareString(command, "START") == 1)
        {
            STARTBNMO(&Games);
        }
    }
}
