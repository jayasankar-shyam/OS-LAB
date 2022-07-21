#include<stdio.h>
int main()
	{
	int m,i,n, position, k, l,total_frames,total_pages,pages[30],temp[30];
	int frames[10];
	int a = 0, b = 0, page_fault = 0;
	printf("\nEnter the number of pages : ");
	scanf("%d",&total_pages);
	printf("\nEnter the page number : ");
	for(i=0;i<=total_pages-1;i++)
		scanf("%d",&pages[i]);
	printf("\nEnter the number of frames : ");
	scanf("%d",&total_frames);
	printf("\nReference String\t");
	for(m = 0; m < total_frames; m++){
		frames[m] = -1;
		printf("f%d\t",m+1);
	}
	printf("\n");
	for(n = 0; n < total_pages; n++)
	{
		printf("%d\t\t\t", pages[n]);
		a = 0, b = 0;
		for(m = 0; m < total_frames; m++)
		{
			if(frames[m] == pages[n])
			{
			a = 1;
			b = 1;
			break;
			}
		}
		if(a == 0)
		{
			for(m = 0; m < total_frames; m++)
			{
				if(frames[m] == -1)
				{
					frames[m] = pages[n];
					b = 1;
					page_fault++;
					break;
				}
			}
		}
		if(b == 0)
		{
			for(m = 0; m < total_frames; m++)
				temp[m] = 0;
			for(k = n - 1, l = 1; l <= total_frames - 1; l++, k--)
			{
				for(m = 0; m < total_frames; m++)
				{
					if(frames[m] == pages[k])
						temp[m] = 1;
				}
			}
			for(m = 0; m < total_frames; m++)
			{
				if(temp[m] == 0)
				position = m;
			}
			frames[position] = pages[n];
			page_fault++;
		}
		for(m = 0; m < total_frames; m++)
		{
		printf("%d\t", frames[m]);
		}
		printf("\n");
	}
	printf("\nTotal Number of Page Faults:\t%d\n", page_fault);
	return 0;
}
