#include <stdio.h>
int cnt = 0;
void bubble_sort(int arr[], int len)
{
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                cnt++;
            }
        }
    }
}
int main()
{
    int arr[] = {4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n%d\n", cnt);
    return 0;
}