#include<stdio.h>
int main()
{
    int at[10],at2[10],bt[100],ex[100],seq[100],re[100],wt[100],tat[100];
    //ex completion time
    //seq holo sequence
    //re response time
    int n,i,j,start,pos,max=0,min,idle=0,k=0;
    float av1=0,av2=0;

    printf("*****INPUT*****\n");
    printf("Enter number of process\n");
    scanf("%d",&n);
    printf("Enter arrival time for processess\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&at[i]);
        at2[i]=at[i];
    }
    printf("Enter burst time for processess\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&bt[i]);
    }
    start=at[0];
    //minimum arrival time pailam je age waiting queue te jabe
    for(i=1; i<n; i++)
    {
        if(start>at[i])
        {
            start=at[i]; // min avrival time ;
        }
    }
    printf("*****OUTPUT*****\n");
    printf("Sequence of execution is\n");
    for(i=0; i<n; i++)
    {
        if(max<at[i])
        {
            max=at[i]; // max arrival time;
        }
    }
    max=max+1; // 5 ;
    for(i=0; i<n; i++,k++)
    {
        min=max; //5
        for(j=0; j<n; j++)
        {
            if(at[j]!=-1)
            {
                if(at[j]<min)
                {
                    min=at[j]; // 0
                    pos=j; // 2
                }
            }
        }
        printf("[P%d]  ",pos);
        seq[k]=pos;
        if(start<at[pos])
        {
            re[pos]=start;
            idle+=at[pos]-start;
            start=at[pos];
            start+=bt[pos];
            at[pos]=-1;
            ex[pos]=start;
        }
        else
        {
            re[pos]=start;
            start+=bt[pos];
            at[pos]=-1;
            ex[pos]=start;
        }
    }
    printf("\n");

    for(i=0; i<n; i++)
    {
        tat[i]=ex[i]-at2[i];
        wt[i]=tat[i]-bt[i];
    }
    printf("Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s) Completation Time\n");
    for(i=0; i<n; i++)
    {
        printf("P%d            %d              %d             %d               %d               %d\n",i,at2[i],bt[i],wt[i],tat[i],ex[i]);
    }
    for(i=0; i<n; i++)
    {
        av1+=tat[i];
        av2+=wt[i];
    }
    printf("Average waiting time(s) %f\nAverage turnaroundtime(s) %f\nCPU idle time(s)%d\n",av2/n,av1/n,idle);
}
