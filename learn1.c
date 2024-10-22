#include <stdio.h>  
int main() {  
    int n;  
    printf("Enter your array size: ");  
    scanf("%d", &n);  
    int arr[100];  
    printf("Enter elements of the array:\n");  
    for (int i = 0; i < n; i++) {  
        scanf("%d", &arr[i]);  
    }  
    int result[100];  
    int k = 0; 
    for (int i = 0; i < n; i++) {  
        int found = 0; 
        for (int j = 0; j < k; j++) {  
            if (arr[i] == result[j]) {  
                found = 1; 
                break;  
            }  
        }  
        if (!found) {  
            result[k++] = arr[i]; 
        }  
    }  
    printf("Array after removing duplicates:\n");  
    for (int i = 0; i < k; i++) {  
        printf("%d ", result[i]); 
         
    }  
    printf("\n");  
    printf("Number of elements before removing duplicates: %d\n", n);
    printf("Number of elements after removing duplicates: %d\n", k);
    return 0;  
}