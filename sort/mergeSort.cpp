#include <stdio.h>
#include <stdlib.h>

//合并两个有序数组，不使用哨兵
void merge(int *data, int nLpos, int nRpos, int nRightEnd)
{
    int i;
    int k = nLpos;
    int nLeftEnd = nRpos;
    int nTmpPos = 0;
    int nLen = nRightEnd - nLpos + 1;

    int *a = (int *)malloc(sizeof(int) * nLen);

    nRpos++;

    while (nLpos <= nLeftEnd && nRpos <= nRightEnd)
    {
        if (data[nLpos] <= data[nRpos])
            a[nTmpPos++] = data[nLpos++];
        else
            a[nTmpPos++] = data[nRpos++];
    }

    while (nLpos <= nLeftEnd)
        a[nTmpPos++] = data[nLpos++];

    while (nRpos <= nRightEnd)
        a[nTmpPos++] = data[nRpos++];

    nTmpPos = 0;

    for (i = k; i < nLen; i++)
        data[i] = a[nTmpPos++];

    free(a);
}