#include <stdio.h>
#define ARRSIZE 50

int arr[ARRSIZE] = {0};

int *get_last_address(int *currCell, int i)
{
    return currCell + i;
}

void shift_elements(int *arr, int i)
{
    int *nextCell = NULL;
    int *lastCellInRange = NULL;
    for (int t = i; t >= 0; t--)
    {
        lastCellInRange = get_last_address(arr, t);
        nextCell = lastCellInRange + 1;
        *nextCell = *lastCellInRange;
    }
}

void insertion_sort(int *arr, int len)
{
    int key;
    for (int i = 1; i <= len; i++)
    {
        key = *(arr + i);
        int j = i - 1;
        while (j >= 0 && *(arr + j) > key)
        {
            int temp = *(arr+j+1);
            shift_elements(arr+j,0);
            *(arr+j) = temp;
            j--;
        }
    }
}

int main()
{
      for (int i = 0; i < ARRSIZE; i++)
    {
        int num;
        scanf(" %d",&num);
        *(arr+i) = num;
        printf("%d,",*(arr+i));
    }
    printf("\n\n");
    insertion_sort(arr, ARRSIZE);
    for (int i = 0; i < ARRSIZE; i++)
    {
        printf("%d,", *(arr+i));
    }
    return 0;
}