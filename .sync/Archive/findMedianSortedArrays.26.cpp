#include <stdio.h>
#include <stdlib.h>

//https://www.jianshu.com/p/9bd57fd52062
int min(int x, int y)
{
    return x > y ? y : x;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int find_kth1(int *nums1, int start1, int len1, int *nums2, int start2, int len2, int k)
{
    if (len1 > len2)
        return find_kth1(nums2, start2, len2, nums1, start1, len1, k);

    int result = 0;
    while (1)
    {
        if (len1 == 0)
        {
            result = nums2[start2 + k - 1];
            break;
        }

        if (k == 1)
        {
            result = min(nums1[start1], nums2[start2]);
            break;
        }

        int p = min(max(k / 2, 1), len1);
        int q = k - p;

        if (nums1[start1 + p - 1] == nums2[start2 + q - 1])
        {
            result = nums1[start1 + p - 1];
            break;
        }
        else if (nums1[start1 + p - 1] > nums2[start2 + q - 1])
        {
            start2 = start2 + q;
            len2 = len2 - q;
            k = k - q;
        }
        else
        {
            start1 = start1 + p;
            len1 = len1 - p;
            k = k - p;
        }
    }

    return result;
}

int find_kth(int *nums1, int start1, int len1, int *nums2, int start2, int len2, int k)
{

    if (len1 > len2)
        return find_kth(nums2, start2, len2, nums1, start1, len1, k);

    if (len1 == 0)
        return nums2[start2 + k - 1];

    if (k == 1)
        return min(nums1[start1], nums2[start2]);

    int p = min(max(k / 2, 1), len1);
    int q = k - p;

    if (nums1[start1 + p - 1] == nums2[start2 + q - 1])
        return nums1[start1 + p - 1];
    else if (nums1[start1 + p - 1] > nums2[start2 + q - 1])
        return find_kth(nums1, start1, len1, nums2, start2 + q, len2 - q, k - q);
    else if (nums1[start1 + p - 1] < nums2[start2 + q - 1])
        return find_kth(nums1, start1 + p, len1 - p, nums2, start2, len2, k - p);

    return 0;
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int len = nums1Size + nums2Size;
    if (!(len & 0x01)) // len 为偶数
        return (find_kth1(nums1, 0, nums1Size, nums2, 0, nums2Size, len / 2) +
                find_kth1(nums1, 0, nums1Size, nums2, 0, nums2Size, len / 2 + 1)) /
               2.0;
    else
        return find_kth1(nums1, 0, nums1Size, nums2, 0, nums2Size, (len + 1) / 2);
}

int main()
{
    int a[] = {100001};
    int b[] = {100000};

    double median = findMedianSortedArrays(a, 1, b, 1);

    printf("%f\n", median);
}