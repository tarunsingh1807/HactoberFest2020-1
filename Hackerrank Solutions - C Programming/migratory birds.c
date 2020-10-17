#include<stdio.h>
main()
{
	int n,i;
	scanf("%d",&n);
	int birdsid[n];
	int freq[6]={0};
	for(i=0;i<n;i++)
	{
		scanf("%d",&birdsid[i]);
		freq[birdsid[i]]++;
	}
	int maxtype=1;
	int maxfreq=freq[1];
	for(i=2;i<6;i++)
			if(freq[i]>maxfreq)
			{
				maxtype=i;
				maxfreq=freq[i];
			}
	printf("%d",maxtype);
}
