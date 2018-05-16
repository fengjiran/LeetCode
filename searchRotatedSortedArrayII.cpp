#include <stdio.h>

bool search(int *nums, int numsSize, int target)
{
    if (nums == NULL || numsSize == 0)
        return false;

    int l = 0;
    int r = numsSize - 1;
    int m;

    while (l <= r)
    {
        m = (l + r) / 2;
        if (nums[m] == target)
            return true;
        if (nums[m] > nums[l])
        {
            if (target >= nums[l] && target < nums[m])
                r = m - 1;
            else
                l = m + 1;
        }
        else if (nums[m] == nums[l])
            l = l + 1;
        else
        {
            if (target > nums[m] && target <= nums[r])
                l = m + 1;
            else
                r = m - 1;
        }
    }

    return false;
}