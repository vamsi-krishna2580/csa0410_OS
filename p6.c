#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int bt[n], rt[n], pr[n], wt[n], tat[n];

    for(int i=0;i<n;i++)
    {
        printf("Burst Time P%d: ",i+1);
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);

        rt[i]=bt[i];
    }

    int complete=0,time=0,min,index=-1;

    while(complete!=n)
    {
        min=9999;
        index=-1;

        for(int i=0;i<n;i++)
        {
            if(rt[i]>0 && pr[i]<min)
            {
                min=pr[i];
                index=i;
            }
        }

        rt[index]--;
        time++;

        if(rt[index]==0)
        {
            complete++;
            tat[index]=time;
            wt[index]=tat[index]-bt[index];
        }
    }

    printf("\nPID\tBT\tPR\tWT\tTAT\n");

    for(int i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",
        i+1,bt[i],pr[i],wt[i],tat[i]);
    }

    return 0;
}