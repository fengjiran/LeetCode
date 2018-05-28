#include <stdlib.h>
#include <stdio.h>

void insertSort(int *Arr, int len)
{
    if (Arr == NULL || len == 0)
        return;

    for (int i = 1; i < len; i++)
    {
        int key = Arr[i];
        int j = i - 1;

        while ((j >= 0) && (Arr[j] > key))
        {
            Arr[j + 1] = Arr[j];
            j = j - 1;
        }
        Arr[j + 1] = key;
    }
}
