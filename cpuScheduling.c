#include<stdio.h> // Including all the required header files
#include<stdlib.h>
#include<conio.h>

int main()
{

  int count,i,j,m=0,numOfProcess,y=0; // Declaring variables
  int time,remain=0,min,flag=0;
  int wait_time=0,turn_around_time=0,arrival_time[10],burst_time[10],p[10],z[10]; // Declaring vaiables for turnaround time,waiting time,and queue
  float k=0,x=0;
  printf("Enter number of Process:  "); // Number of processes entered
  scanf("%d",&numOfProcess);
  printf("\n #Keep Arrival time Greater than 3 time units(CPU remains idle for First 3 seconds) \n");// Condition applied as specified in question
  printf("\n #Burst time should be less than 10 time units\n\n");
  for(count=0;count<numOfProcess;count++)
  {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1);// Enter the values for arrival time and burst time 
    scanf("%d",&arrival_time[count]); 
    scanf("%d",&burst_time[count]);
  } // COMPLEXITY=O(n)
  for(i=0;i<numOfProcess;i++)
{
	if(burst_time[i]>10)
	{
		printf("\n INVALID BURST TIME \n");// For INVALID arrival time
		getch();
		exit(1);
	}
} // COMPLEXITY=O(n)
for(i=0;i<numOfProcess;i++)
{
	if(arrival_time[i]<3)
	{
		printf("\n Invalid Arrival Time it should be greater than 3 \n");
		getch();
		exit(1);
	}
}
  printf("\n\n\tProcess\t|Turnaround Time|Waiting Time\n"); // Table created for displaying process,turnaround time and waiting time
  printf("\t===========================================\n");
for(i=0;i<numOfProcess;i++)
{
	m=m+burst_time[i];
} // COMPLEXITY=O(n)
min=m;
time=m;
//minimum arrival time
for(i=0;i<numOfProcess;i++)
{
	if(arrival_time[i]<time)
	{
		time=arrival_time[i];
	}
} // COMPLEXITY=O(n)
for(i=time;i<=m;i=i+burst_time[j])
{
	min=m;
	remain=0;
	flag=0;

	for(count=0;count<numOfProcess;count++)
	{

		if(arrival_time[count]<=i)
		{

			if(burst_time[count]<min)
			{

				min = burst_time[count];
				j=count;
				flag=1;
			}
			remain=1;
		}
	} // COMPLEXITY=O(n)
	if(flag==1&&remain==1)
	{
		wait_time=i-arrival_time[j];
		turn_around_time=wait_time+burst_time[j];
		printf("\tP[%d]\t|\t%d\t|\t%d\n",j+1,turn_around_time,wait_time);
		k=k+wait_time;
		x=x+turn_around_time;

		arrival_time[j]=m+1;
		p[y]=j+1;
		z[y]=i;
		y++;
	}
} // The output is displayed below
printf("\n\n\nAverage Waiting Time= %.2f\n",k/numOfProcess);
printf("Avg Turnaround Time = %.2f",x/numOfProcess);
printf("\n\n\nTotal time taken by processor to complete all the jobs : %d",m);
printf("\n\n\nQueue  for order of execution: ");
printf("\n\nProcess		");

for(i=0;i<numOfProcess;i++)
{
	printf(" P[%d]   ",p[i]);
	if(i==(numOfProcess-1))
	{
		printf("End");
	}
} // COMPLEXITY=O(n)


  return 0;
}
