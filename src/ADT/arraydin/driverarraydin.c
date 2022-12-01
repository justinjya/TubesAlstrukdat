#include <stdio.h>
#include "arraydin.h"

int main()
{
    int i;
    char ch;
    ArrayDin array;
    i = 0;
    system("cls||clear");
    printf("Ketik enter untuk melanjutkan program.\n");
    while (i < 10)
    {
        scanf("%c", &ch);
        system("cls||clear");
        if (i == 0)
        {
            printf("MakeArrayDin()\n");
            printf("Hasil yang diharapkan:\n");
            printf("[]\n");
            printf("GetCapacity = 10\n");
            printf("IsEmpty(array) = 1\n");
            printf("Length = 0\n");
            printf("\nHasil Test Case:\n");
            array = MakeArrayDin();
            PrintArrayDin(array);
            printf("GetCapacity = %d\n", GetCapacity(array));
            printf("IsEmpty(array) = %d\n", IsEmpty(array));
            printf("Length = %d\n", Length(array));
        }
        else if (i == 1)
        {
            printf("InsertFirst(array, Test1)\n");
            printf("Hasil yang diharapkan:\n");
            printf("[Test1]\n");
            printf("GetCapacity = 10\n");
            printf("IsEmpty(array) = 0\n");
            printf("Length = 1\n");
            printf("\nHasil Test Case:\n");
            InsertFirst(&array, "Test1");
            PrintArrayDin(array);
            printf("GetCapacity = %d\n", GetCapacity(array));
            printf("IsEmpty(array) = %d\n", IsEmpty(array));
            printf("Length = %d\n", Length(array));
        }
        else if (i == 2)
        {
            printf("InsertLast(array, Test3)\n");
            printf("[Test1, Test3]\n");
            printf("Hasil yang diharapkan:\n");
            printf("GetCapacity = 10\n");
            printf("IsEmpty(array) = 0\n");
            printf("Length = 2\n");
            printf("\nHasil Test Case:\n");
            InsertLast(&array, "Test3");
            PrintArrayDin(array);
            printf("GetCapacity = %d\n", GetCapacity(array));
            printf("IsEmpty(array) = %d\n", IsEmpty(array));
            printf("Length = %d\n", Length(array));
        }
        else if (i == 3)
        {
            printf("InsertAt(array, Test2, 1)\n");
            printf("[Test1, Test2, Test3]\n");
            printf("Hasil yang diharapkan:\n");
            printf("GetCapacity = 10\n");
            printf("IsEmpty(array) = 0\n");
            printf("Length = 3\n");
            printf("\nHasil Test Case:\n");
            InsertAt(&array, "Test2", 1);
            PrintArrayDin(array);
            printf("GetCapacity = %d\n", GetCapacity(array));
            printf("IsEmpty(array) = %d\n", IsEmpty(array));
            printf("Length = %d\n", Length(array));
        }
        else if (i == 4)
        {
            printf("InsertFirst(array, 'Test') & InsertLast(array, 'Test4')\n");
            printf("Hasil yang diharapkan:\n");
            printf("[Test, Test1, Test2, Test3, Test4]\n");
            printf("GetCapacity = 10\n");
            printf("IsEmpty(array) = 0\n");
            printf("Length = 5\n");
            printf("\nHasil Test Case:\n");
            InsertFirst(&array, "Test");
            InsertLast(&array, "Test4");
            PrintArrayDin(array);
            printf("GetCapacity = %d\n", GetCapacity(array));
            printf("IsEmpty(array) = %d\n", IsEmpty(array));
            printf("Length = %d\n", Length(array));
        }
        else if (i == 5)
        {
            printf("DeleteFirst & DeleteLast\n");
            printf("Hasil yang diharapkan:\n");
            printf("[Test1, Test2, Test3]\n");
            printf("GetCapacity = 10\n");
            printf("IsEmpty(array) = 0\n");
            printf("Length = 3\n");
            printf("\nHasil Test Case:\n");
            DeleteFirst(&array);
            DeleteLast(&array);
            PrintArrayDin(array);
            printf("GetCapacity = %d\n", GetCapacity(array));
            printf("IsEmpty(array) = %d\n", IsEmpty(array));
            printf("Length = %d\n", Length(array));
        }
        else if (i == 6)
        {
            printf("DeleteAt(array, 1) & Get(array, 1)\n");
            printf("Hasil yang diharapkan:\n");
            printf("[Test1, Test3]\n");
            printf("Get(array, 1) = Test3\n");
            printf("GetCapacity = 10\n");
            printf("IsEmpty(array) = 0\n");
            printf("Length = 2\n");
            printf("\nHasil Test Case:\n");
            DeleteAt(&array, 1);
            PrintArrayDin(array);
            printf("Get(array, 1) = %s\n", Get(array, 1));
            printf("GetCapacity = %d\n", GetCapacity(array));
            printf("IsEmpty(array) = %d\n", IsEmpty(array));
            printf("Length = %d\n", Length(array));
        }
        else if (i == 7)
        {
            printf("Empty dari keisi.\n");
            printf("Hasil yang diharapkan:\n");
            printf("[]\n");
            printf("GetCapacity = 10\n");
            printf("IsEmpty(array) = 1\n");
            printf("Length = 0\n");
            printf("\nHasil Test Case:\n");
            DeleteLast(&array);
            DeleteLast(&array);
            PrintArrayDin(array);
            printf("GetCapacity = %d\n", GetCapacity(array));
            printf("IsEmpty(array) = %d\n", IsEmpty(array));
            printf("Length = %d\n", Length(array));
        }
        else if (i == 8)
        {
            printf("InsertLast(array, TestPenuh) hingga Length mencapai Capacity.\n");
            printf("Hasil yang diharapkan:\n");
            printf("[TestPenuh, TestPenuh, TestPenuh, TestPenuh, TestPenuh, TestPenuh, TestPenuh, TestPenuh, TestPenuh, TestPenuh]\n");
            printf("GetCapacity = 10\n");
            printf("IsEmpty(array) = 1\n");
            printf("Length = 10\n");
            printf("\nHasil Test Case:\n");
            for (int j = 0; j < 10; j++)
            {
                InsertLast(&array, "TestPenuh");
            }
            PrintArrayDin(array);
            printf("GetCapacity = %d\n", GetCapacity(array));
            printf("IsEmpty(array) = %d\n", IsEmpty(array));
            printf("Length = %d\n", Length(array));
        }
        else if (i == 9)
        {
            printf("InsertLast(array, TestRealokasi) setelah Length mencapai Capacity & SearchArrayDin.\n");
            printf("Hasil yang diharapkan:\n");
            printf("[TestPenuh, TestPenuh, TestPenuh, TestPenuh, TestPenuh, TestPenuh, TestPenuh, TestPenuh, TestPenuh, TestPenuh, TestRealokasi]\n");
            printf("SearchArrayDin(array, 'TestRealokasi') = 10\n");
            printf("GetCapacity = 20\n");
            printf("IsEmpty(array) = 0\n");
            printf("Length = 11\n");
            printf("\nHasil Test Case:\n");
            InsertLast(&array, "TestRealokasi");
            PrintArrayDin(array);
            printf("SearchArrayDin(array, 'TestRealokasi') = %d\n", SearchArrayDin(array, "TestRealokasi"));
            printf("GetCapacity = %d\n", GetCapacity(array));
            printf("IsEmpty(array) = %d\n", IsEmpty(array));
            printf("Length = %d\n", Length(array));
        }
        i++;
    }
}
