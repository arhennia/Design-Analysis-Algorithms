#include <stdio.h>
void EXCHANGE(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void ROTATE_RIGHT(int p1[], int p2)
{
    int i;
    //swap
    for (i = p2 - 1; i > 0; i--)
        EXCHANGE(&p1[i], &p1[i - 1]);
}
int main()
{
    int n, k, i;
    int arr[100];
    printf("Enter the size of array: "); scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("enter # elements to rotate: "); scanf("%d", &k);
    printf("\nBefore ROTATE: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    ROTATE_RIGHT(arr, k);
    printf("\nAfter ROTATE : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n"); return 0;
}