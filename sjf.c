#include<stdio.h>
int main()
{
	int n,i,j,t_wt,t_tat,pos,temp;
	float a_wt,a_tat;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	int b[n],wt[n],tat[n],p[n];
	printf("Enter the burst time of the processes 1 to %d :",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		p[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
		    if(b[j]<b[pos])
		        pos=j;
		}
	  
		temp=b[i];
		b[i]=b[pos];
		b[pos]=temp;
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	wt[0]=0;
	for(i=1;i<n;i++){
		wt[i]=wt[i-1]+b[i-1];
		t_wt+=wt[i];
	}
	for(i=0;i<n;i++){
		tat[i]=b[i]+wt[i];
		t_tat+=tat[i];
	}
	printf("Process No\tBurst Time\tWaiting Time\tTurn Around Time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t %d\t\t %d\t\t %d\n",p[i],b[i],wt[i],tat[i]);		
	}
	a_wt=(float)t_wt/n;
	a_tat=(float)t_tat/n;
	printf("\nAverage Waiting time = %.2f\n",a_wt);
	printf("Average Turn Around time = %.2f\n",a_tat);
}
