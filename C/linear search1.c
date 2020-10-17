#include<stdio.h>
int searchnum(int arr[],int x,int n)
{
	int i;
	for(i=0;i<x;i++)
		if(arr[i]==n)
		{ 
			return i;
			break;
		}
}
main()
{	
	int x,i,key;
	scanf("%d",&x);
	int arr[x];
	printf("enter the integers\n");
	for(i=0;i<x;i++)
		scanf("%d",&arr[i]);
	printf("enter the number to be seacrhed!!\n");
	scanf("%d",&key);
	int k=searchnum(arr,x,key);
	printf("the number found at %d pos",k+1);

}
