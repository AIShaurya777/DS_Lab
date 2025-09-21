
#include <stdio.h>

int main() {
  int arr[100];
  int n = 0;
  printf("Enter size of array: ");
  scanf("%d", &n);
  printf("Enter elements of array: \n");
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  int key;
  printf("Enter element to search: ");
  scanf("%d", &key);

  printf("[");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("]\n");

  printf("Sorting the array using Bubble Sort...\n");

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  printf("[");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("]\n");

  int left = 0, right = n - 1, mid;
  int found = -1;

  while (left <= right) {
    mid = (left + right) / 2;
    if (arr[mid] == key) {
      found = mid;
      break;
    } else if (arr[mid] < key) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  if (found > 0) {
    printf("Element found at index: %d\n", found);
  } else {
    printf("Element not found in the array.\n");
  }

  return 0;
}
