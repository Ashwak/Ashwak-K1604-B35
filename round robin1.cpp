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
