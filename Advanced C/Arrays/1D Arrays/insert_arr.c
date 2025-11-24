#include <stdio.h>
int main() {
    int arr[100], n, pos, val, i;
    printf("Enter array size: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n", n);
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("Enter position to insert (1 to %d): ", n+1);
    scanf("%d",&pos);
    printf("Enter value to insert: ");
    scanf("%d",&val);
    // Shift elements
    for(i=n-1;i>=pos-1;i--) arr[i+1]=arr[i];
    arr[pos-1]=val;
    n++;
    printf("Array after insertion:\n");
    for(i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}

