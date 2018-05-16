#include <stdio.h>

// 移除排好序的数组中的重复元素，并返回新的数组长度
int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;

    int i;
    int index = 0;
    for (i = 1; i < numsSize; i++)
        if (nums[index] != nums[i])
            nums[++index] = nums[i];

    return index + 1;
}

int main()
{
    //
}