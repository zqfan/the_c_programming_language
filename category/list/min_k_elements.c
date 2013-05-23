/*
  get the min k elements of an integer array

  sample usage:
  int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
  get_min_elements(arr, 8, 4); //arr[:4] == {1, 2, 3, 4}
*/
#include<stdio.h>

void get_min_elements(int * arr, int len, int k)
{
  int i, j, min_index, tmp;
  for (int i = 0; i < k; i++) {
    min_index = i;
    for (int j = i + 1; j < len; j++) {
      if (arr[j] < arr[min_index])
        min_index = j;
    }
    tmp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = tmp;
  }
}

int main()
{
  int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
  get_min_elements(arr, 8, 4);
  for (int i = 0; i < 4; i++)
    printf("%d ", arr[i]);
  return 0;
}
