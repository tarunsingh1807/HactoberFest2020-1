#include<stdio.h>
swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
selectionsort(int arr[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(arr[j]<arr[min])
				min=j;
		swap(&arr[min],&arr[i]);
	}
}
main()
{
	int i,n;
	scanf("%d",&n);
	int arr[n];
	printf("enter the array elements");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	selectionsort(arr,n);
	printf("sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d",arr[i]);
}
