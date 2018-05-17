#include <stdio.h>
#include <stdlib.h>

int min(int x, int y)
{
    return x > y ? y : x;
}

int max(int x, int y)
{
    return x > y ? x : y;
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
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int len = nums1Size + nums2Size;
    if (!(len & 0x01)) // len 为偶数
        return (find_kth(nums1, 0, nums1Size, nums2, 0, nums2Size, len / 2) +
                find_kth(nums1, 0, nums1Size, nums2, 0, nums2Size, len / 2 + 1)) /
               2.0;
    else
        return find_kth(nums1, 0, nums1Size, nums2, 0, nums2Size, (len + 1) / 2);
}

int main()
{
    int a[] = {1, 3};
    int b[] = {2};

    double median = findMedianSortedArrays(a, 2, b, 1);
}