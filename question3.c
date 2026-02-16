#include <stdio.h>

int main()
{
    int n, k, comparisons = 0, foundIdx = -1;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    for (int i = 0; i < n; i++)
    {
        comparisons++;
        if (arr[i] == k)
        {
            foundIdx = i;
            break;
        }
    }

    if (foundIdx != -1)
    {
        printf("Found at index %d\n", foundIdx);
    }
    else
    {
        printf("Not Found\n");
    }
    
    printf("Comparisons = %d", comparisons);

    return 0;
}