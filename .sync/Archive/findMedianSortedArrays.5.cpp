#include <stdio.h>
#include <stdlib.h>

int find_kth(int *nums1, int start1, int len1, int *nums2, int start2, int len2, int k)
{

    if (len1 > len2)
        return find_kth(nums2, start2, len2, nums1, start1, len1, k);

    if (len1 == 0)
        return nums2[start2 + k - 1];

    if (k == 1)
        return nums1[start1] > nums2[start2] ? nums2[start2] : nums1[start1];

    p = k / 2;
    q = k - p;
}