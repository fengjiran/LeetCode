#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>

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

    for (i = k; i <= nRightEnd; i++)
        data[i] = a[nTmpPos++];

    free(a);
}

//合并两个有序数组，使用哨兵
void merge(int *data, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = (int *)malloc(sizeof(int) * (n1 + 1));
    int *R = (int *)malloc(sizeof(int) * (n2 + 1));

    for (int i = 0; i < n1; i++)
        L[i] = data[i + p];
    for (int i = 0; i < n2; i++)
        R[i] = data[i + q + 1];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++)
        if (L[i] <= R[j])
            data[k] = L[i];
        else
            data[k] = R[j];

    free(L);
    free(R);
}