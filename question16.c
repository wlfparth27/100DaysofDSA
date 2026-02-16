#include <stdio.h>

void printFrequency(int* nums, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        int counted = 0;
        for (int j = 0; j < i; j++) 
        {
            if (nums[i] == nums[j]) 
            {
                counted = 1;
                break;
            }
        }

        if (!counted) 
        {
            int count = 0;
            for (int j = 0; j < n; j++) 
            {
                if (nums[i] == nums[j]) 
                {
                    count++;
                }
            }
            printf("%d:%d ", nums[i], count);
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &nums[i]);
    }
    printFrequency(nums, n);
    return 0;
}