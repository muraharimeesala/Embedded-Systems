#include <stdio.h>
int main(){
    int arr[100], n, i, j;
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter %d elements of array:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int count, majority_element = -1;
    for(i = 0; i < n; i++){
        count = 1;
        for(j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > n / 2){
            majority_element = arr[i];
            break;
        }
    }
    if(majority_element != -1)
        printf("Majority element is: %d\n", majority_element);
    else{
        printf("No majority element found.\n");
    }
    return 0;
}

