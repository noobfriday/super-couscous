# include<stdio.h>

void swap(int* x, int* y);
void selectionSort(int arr[], int n);
void printArray(int arr[], int n);
void longestSequence(int arr[], int n, int* a);

int main(){
    int arr[] = {9, 8, 7, 1, 2, 3, -4, -3, -1, -2, 0, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int a;

    //Original array.
    printf("\nOriginal ");
    printArray(arr, n);
    
    //Sorting the array.
    selectionSort(arr, n);

    //Sorted Array.
    printf("\nSorted ");
    printArray(arr, n);
    
    longestSequence(arr, n, &a);

    printf("\nLongest continuous sequence in the given array = %d\n\n", a);
    

    
    return 0;
}


//Swap Function.
void swap(int* x, int* y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}


//Selection Sort Function.
void selectionSort(int arr[], int n){
    int i, j, min_idx;
    
    for(i = 0; i < n-1; i++){
        min_idx = i;
        
        for(j = i+1; j < n; j++){
            
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
            
        }
        
        swap(&arr[min_idx], &arr[i]);
    }
}


//Longest Continuous Sequence Function.
void longestSequence(int arr[], int n, int* a){
    selectionSort(arr, n);
    *a = 1;
    int count = 1;
    for(int i = 0; i < n-1; i++){
        
        if(arr[i]+1 == arr[i+1]){
            count += 1;
        } else{
            if(*a < count){
                *a = count;
            }
            count = 1;
            
        }

    }

}


//Array Printing Function.
void printArray(int arr[], int n){
    
    printf("Array = [");
    
    for(int i = 0; i < n; i++){
        if(i < n-1){
            printf("%d, ", arr[i]);
        } else{
            printf("%d]", arr[i]);
        }
    
    }

    printf("\n");
}