#include <stdio.h>

// 移除排好序的数组中的重复元素，并返回新的数组长度
// 但是允许的最大重复次数为2
int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize <= 2)
        return numsSize;

    int i;
    int index = 2;

    for (i = 2; i < numsSize; i++)
        if (nums[i] != nums[index - 2])
            nums[index++] = nums[i];

    return index;
}