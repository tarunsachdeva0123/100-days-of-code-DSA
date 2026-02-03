#include <stdio.h>
#include <stdlib.h>
int main()
{   int pos;
    printf ("enter size of element\n");
    int n;
    scanf("%d",&n);
    int *arr;
    arr=(int *)malloc(n*sizeof(int));
    printf("enter elements\n");
    for (int i =0;i<n;i++)
    scanf("%d", &arr[i]);
    printf("enter position for deletion\n");
    scanf("%d",&pos);
    for (int j=pos;j<n;j++)
    {
        arr[j-1]=arr[j];
    }
    printf("your new array\n");
    for(int k=0;k<n-1;k++)
    {
        printf(" %d,",arr[k]);
    }
    free (arr);
    return 0;
    
}