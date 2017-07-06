#include<stdio.h>


int findElementInArray(int arr[], int n, int k){
    for (int i=0; i<n-1; i++){
        if (arr[i] == k){
            printf("\nFound at %d\n", i);
            return 0;
        }
    }
        printf("\n%d Not found\n", k);
}
int main()
{
    printf("Long time, No 'C' \n");
    int array[] = {23, 42, 12, 56, 64, 3, 10, 90};
    printf("Array declared.\n");
    int k;
    scanf("%d", &k);
    int num_of_elem = sizeof(array)/sizeof(int);
    printf("Entered number: %d\n", k);
    printf("Size of array: %d\n",num_of_elem);
    for (int j=0; j<num_of_elem ; j++){
        printf("%d %d \n", j, array[j]);
        }
    findElementInArray(array, num_of_elem, k);
    return 0;
    }
