#include <stdio.h>

int search(int *nums, int numsSize, int target)
{
    if (nums == NULL || numsSize == 0)
        return -1;

    int l = 0;
    int r = numsSize - 1;
    int m;

    while (l <= r)
    {
        m = (l + r) / 2;
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

int main()
{
    int a[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = search(a, 7, target);
    printf("%d\n", result);
}