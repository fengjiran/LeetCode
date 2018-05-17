#include <stdio.h>

int search(int *nums, int numsSize, int target)
{
    if (nums == 0 || numsSize == 0)
        return -1;

    int l = 0;
    int r = numsSize - 1;

    while (l <= r)
    {
        int m = (l + r) / 2;
        if (nums[m] == target)
            return m;

        if (nums[m] < nums[r])
        {
            if (target > nums[m] && target <= nums[r])
                l = m + 1;
            else
                r = m - 1;
        }
        else
        {
            if (target >= nums[l] && target < nums[m])
                r = m - 1;
            else
                l = m + 1;
        }
    }

    return -1;
}