# include<stdio.h>

void swap(int* x, int* y);
void selectionSort(int arr[], int n);
void printArray(int arr[], int n);
void longestSequence(int arr[], int n, int* a);

int main(){
    int arr[] = {9, 8, 7, 1, 2, 3, -4, -3, -1, -2, 0, 6};
    
    // Orig = [9, 8, 7, 1, 2, 3, -4, -3, -1, -2, 0, 6]


    // test = [64, 34, 25, 12, 22, 11, 90, 91, 93, -5, -4, -2, 4, 5, 7, 92]
    // Sort = [-5, -4, -2, 4, 5, 7, 11, 12, 22, 25, 34, 64, 90, 91, 92, 93]

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
    printf("\n");

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
        // Remove comments of the code below for viewing inner workings of the loop.
        // printf("{ i=%d arr[i] = %d, arr[i+1] = %d,\n",i+1 , arr[i], arr[i+1]);

        if(arr[i]+1 == arr[i+1]){
            
            count += 1;
            // Remove comments of the code below for viewing inner workings of the loop.
            // printf("\nCount = %d\n}\n\n", count);
            
            if(*a < count){
                *a = count;
                // Remove comments of the code below for viewing inner workings of the loop.
                // printf("\n*** Max_Count = %d ***\n\n", *a);
            }

        } else{
            count = 1;
            // Remove comments of the code below for viewing inner workings of the loop.
            // printf("\nNew_Count = %d\n}\n\n", count);
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
