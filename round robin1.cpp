 #include<stdio.h>
#include<stdbool.h>
void WaitingTime(int process[], int n,int burst[], int wt[], int quan)
{
	
	
    int i,t,rem[n];
    t=0;
    for (i = 1 ; i <= n ; i++)
        {
            rem[i] =  burst[i];
        }
    while(1)
    {  
        bool flag= true;
        for(i = 1; i <= n; i++)
        {
            if (rem[i]>0)
            {
                flag=false; 
 
                if (rem[i]>quan)
                {
                    t += quan;
                    rem[i] -= quan;
                }
                else
                {
	            wt[i] = t - process[i];
                    t = t + rem[i];
                    rem[i] = 0;
                }
            }
        }
        if (flag == true)
          break;
    }
}
void TurnAroundTime(int process[], int n,int burst[], int wt[], int temp[])
{
    int i;
    for (i = 1; i <=n ; i++)
        temp[i] = burst[i] + wt[i];
}



void AvgTime(int process[], int n, int burst[],int q,char name)
{
    int i,wt[n], temp[n], total_wait = 0, total_time= 0;
    int avg_wait , avg_turnaround;
    WaitingTime(process, n,burst, wt, q);
    TurnAroundTime(process, n, burst, wt, temp);
    printf("Processes :   BrustTime :  ArivalTime:  WaitingTime :   TurnAroundTime : \n");
    int count=0;
       for (i=1; i<=n; i++)
    {
        total_wait = total_wait + wt[i];
              total_time = total_time + temp[i];
	    count+=burst[i];
	if(count>60)
	{
		break;
	}
        printf("%d \t\t  %d \t\t  %d \t\t %d \t\t\t%d\n",i,burst[i],process[i],wt[i],temp[i]);
    }

    avg_wait=total_wait/(i-1);
    avg_turnaround=total_time/(i-1);
    if(name=='s')
    {
	printf("\n Time he spend on handling of students query is : %d",avg_turnaround);
        printf("\n Average query time is : %d",avg_wait);
    }
    else
    {
	printf("\n Time he spend on handling of faculty query is : %d",avg_turnaround);
        printf("\n Average query time is : %d",avg_wait);
    }
}
int main()
{
 
    int y;
    int quantum =5;
    printf("#Enter no.of processes# : ");
    scanf("%d",&y);
    int p[y],p1[y];
    int burst_time[y],burst_time1[y]; 
    


    printf("********Enter STUDENTS ArrivalTime:******** \n\n");
    int i;
    for(i=1;i<=y;i++)
    {
	printf("Enter student arival time: %d\t",i);
	scanf("%d",&p[i]);
        printf("\n");
    }
    



 

    
    printf("*******Enter STUDENT BurstTime:********** \n\n");
    for(i=1;i<=y;i++)
    {

    
