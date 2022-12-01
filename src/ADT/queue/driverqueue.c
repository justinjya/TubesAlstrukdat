#include <stdio.h>
#include "queue.h"

int main()
{
    int i;
    char ch;
    ElType val;
    Queue Q;
    i = 0;
    system("cls||clear");
    printf("Ketik enter untuk melanjutkan program.\n");
    while (i < 7)
    {
        scanf("%c", &ch);
        system("cls||clear");
        if (i == 0)
        {
            printf("CreateQueue(Q), isEmpty(Q), isFull(Q), & length(Q)\n");
            printf("Hasil yang diharapkan:\n");
            printf("[]\n");
            printf("isEmpty(Q) = 1\n");
            printf("isFull(Q) = 0\n");
            printf("length(Q) = 0\n");
            printf("IDX_HEAD(Q) = -1\n");
            printf("IDX_TAIL(Q) = -1\n");
            printf("\nHasil Test Case:\n");
            CreateQueue(&Q);
            displayQueue(Q);
            printf("isEmpty(Q) = %d\n", isEmpty(Q));
            printf("isFull(Q) = %d\n", isFull(Q));
            printf("length(Q) = %d\n", length(Q));
            printf("IDX_HEAD(Q) = %d\n", IDX_HEAD(Q));
            printf("IDX_TAIL(Q) = %d\n", IDX_TAIL(Q));
        }
        else if (i == 1)
        {
            printf("enqueue(Q, Test1) & enqueue(Q, Test)\n");
            printf("Hasil yang diharapkan:\n");
            printf("[Test, Test1]\n");
            printf("isEmpty(Q) = 0\n");
            printf("isFull(Q) = 0\n");
            printf("length(Q) = 2\n");
            printf("IDX_HEAD(Q) = 0\n");
            printf("HEAD(Q) = Test\n");
            printf("IDX_TAIL(Q) = 1\n");
            printf("TAIL(Q) = Test1\n");
            printf("\nHasil Test Case:\n");
            enqueue(&Q, "Test");
            enqueue(&Q, "Test1");
            displayQueue(Q);
            printf("isEmpty(Q) = %d\n", isEmpty(Q));
            printf("isFull(Q) = %d\n", isFull(Q));
            printf("length(Q) = %d\n", length(Q));
            printf("IDX_HEAD(Q) = %d\n", IDX_HEAD(Q));
            printf("HEAD(Q) = %s\n", HEAD(Q));
            printf("IDX_TAIL(Q) = %d\n", IDX_TAIL(Q));
            printf("TAIL(Q) = %s\n", TAIL(Q));
        }
        else if (i == 2)
        {
            printf("dequeue(Q, val)\n");
            printf("Hasil yang diharapkan:\n");
            printf("[Test1]\n");
            printf("Val = Test\n");
            printf("isEmpty(Q) = 0\n");
            printf("isFull(Q) = 0\n");
            printf("length(Q) = 1\n");
            printf("IDX_HEAD(Q) = 1\n");
            printf("HEAD(Q) = Test1\n");
            printf("IDX_TAIL(Q) = 1\n");
            printf("TAIL(Q) = Test1\n");
            printf("\nHasil Test Case:\n");
            dequeue(&Q, &val);
            displayQueue(Q);
            printf("Val = %s\n", val);
            printf("isEmpty(Q) = %d\n", isEmpty(Q));
            printf("isFull(Q) = %d\n", isFull(Q));
            printf("length(Q) = %d\n", length(Q));
            printf("IDX_HEAD(Q) = %d\n", IDX_HEAD(Q));
            printf("HEAD(Q) = %s\n", HEAD(Q));
            printf("IDX_TAIL(Q) = %d\n", IDX_TAIL(Q));
            printf("TAIL(Q) = %s\n", TAIL(Q));
        }
        else if (i == 3)
        {
            printf("dequeue(Q, val)\n");
            printf("Hasil yang diharapkan:\n");
            printf("[]\n");
            printf("Val = Test1\n");
            printf("isEmpty(Q) = 1\n");
            printf("isFull(Q) = 0\n");
            printf("length(Q) = 0\n");
            printf("IDX_HEAD(Q) = -1\n");
            printf("IDX_TAIL(Q) = -1\n");
            printf("\nHasil Test Case:\n");
            dequeue(&Q, &val);
            displayQueue(Q);
            printf("Val = %s\n", val);
            printf("isEmpty(Q) = %d\n", isEmpty(Q));
            printf("isFull(Q) = %d\n", isFull(Q));
            printf("length(Q) = %d\n", length(Q));
            printf("IDX_HEAD(Q) = %d\n", IDX_HEAD(Q));
            printf("IDX_TAIL(Q) = %d\n", IDX_TAIL(Q));
        }
        else if (i == 4)
        {
            printf("dequeue(Q, val)\n");
            printf("Hasil yang diharapkan:\n");
            printf("Queue is empty!\n");
            printf("[]\n");
            printf("Val = Test1\n");
            printf("isEmpty(Q) = 1\n");
            printf("isFull(Q) = 0\n");
            printf("length(Q) = 0\n");
            printf("IDX_HEAD(Q) = -1\n");
            printf("IDX_TAIL(Q) = -1\n");
            printf("\nHasil Test Case:\n");
            dequeue(&Q, &val);
            displayQueue(Q);
            printf("Val = %s\n", val);
            printf("isEmpty(Q) = %d\n", isEmpty(Q));
            printf("isFull(Q) = %d\n", isFull(Q));
            printf("length(Q) = %d\n", length(Q));
            printf("IDX_HEAD(Q) = %d\n", IDX_HEAD(Q));
            printf("IDX_TAIL(Q) = %d\n", IDX_TAIL(Q));
        }
        else if (i == 5)
        {
            printf("enqueue(Q, TestPenuh) hingga queue penuh.\n");
            printf("Hasil yang diharapkan:\n");
            printf("[TestPenuh, TestPenuh, .., TestPenuh(100)]\n");
            printf("isEmpty(Q) = 0\n");
            printf("isFull(Q) = 1\n");
            printf("length(Q) = 100\n");
            printf("IDX_HEAD(Q) = 0\n");
            printf("HEAD(Q) = TestPenuh\n");
            printf("IDX_TAIL(Q) = 99\n");
            printf("TAIL(Q) = TestPenuh(100)\n");
            printf("\nHasil Test Case:\n");
            for (int j = 0; j < 99; j++)
            {
                enqueue(&Q, "TestPenuh");
            }
            enqueue(&Q, "TestPenuh(100)");
            displayQueue(Q);
            printf("isEmpty(Q) = %d\n", isEmpty(Q));
            printf("isFull(Q) = %d\n", isFull(Q));
            printf("length(Q) = %d\n", length(Q));
            printf("IDX_HEAD(Q) = %d\n", IDX_HEAD(Q));
            printf("HEAD(Q) = %s\n", HEAD(Q));
            printf("IDX_TAIL(Q) = %d\n", IDX_TAIL(Q));
            printf("TAIL(Q) = %s\n", TAIL(Q));
        }
        else if (i == 6)
        {
            printf("enqueue(Q, TestPenuh(101)) jika queue penuh.\n");
            printf("Hasil yang diharapkan:\n");
            printf("Queue is full!\n");
            printf("[TestPenuh, TestPenuh, .., TestPenuh(100)]\n");
            printf("isEmpty(Q) = 0\n");
            printf("isFull(Q) = 1\n");
            printf("length(Q) = 100\n");
            printf("IDX_HEAD(Q) = 0\n");
            printf("HEAD(Q) = TestPenuh\n");
            printf("IDX_TAIL(Q) = 99\n");
            printf("TAIL(Q) = TestPenuh(100)\n");
            printf("\nHasil Test Case:\n");
            enqueue(&Q, "TestPenuh(101)");
            displayQueue(Q);
            printf("isEmpty(Q) = %d\n", isEmpty(Q));
            printf("isFull(Q) = %d\n", isFull(Q));
            printf("length(Q) = %d\n", length(Q));
            printf("IDX_HEAD(Q) = %d\n", IDX_HEAD(Q));
            printf("HEAD(Q) = %s\n", HEAD(Q));
            printf("IDX_TAIL(Q) = %d\n", IDX_TAIL(Q));
            printf("TAIL(Q) = %s\n", TAIL(Q));
        }
        i++;
    }
}
