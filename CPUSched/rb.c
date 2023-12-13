#include <stdio.h>
int q[100], f=-1, r=-1;
void insert(int n)
{
   if(f==-1) // queue being empty 
   {
     f=0;
   }
   r=r+1;
   q[r] = n;
}
int delete()
{
    int n;
    n = q[f];
    f++;
    return n;
}
int main()
{
    int n,p,t=0;
    float ttat=0,twt=0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int a[n][5], bt[10], exist[10] = {0}, tq=0;
    //reading arrival time and burst time
    printf("Enter the arrival time and burst time of each process: \n");

    for(int i=0; i<n; i++)
    {
        printf("Process ID: ");
        scanf("%d", &a[i][0]);
        printf("Arrival time: ");
        scanf("%d", &a[i][1]);
        printf("Burst time: ");
        scanf("%d", &a[i][2]);
        printf("\n");

        bt[i] = a[i][2];
    }

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    insert(0);
    exist[0] = 1;

    while(f<=r)
    {
        p = delete();
        if(a[p][2]>=tq)
        {
            a[p][2]-=tq;
            t+=tq; // to keep track of time elapsed
        }
        else
        {
            t+=a[p][2];
            a[p][2]=0;
        }

        for(int i=0;i<n;i++) // enter the ready queue if the arrival time < time elapsed
        {
            if(exist[i]==0 && a[i][1]<=t)
            {
                insert(i);
                exist[i]=1;
            }
        }

        if(a[p][2]==0)
        {
            a[p][4] = t - a[p][1];
            a[p][3] = a[p][4]-bt[p];
            ttat = ttat + a[p][4];
            twt = twt + a[p][3];
        }
        else
        {
            insert(p);
        }
    }

    printf("\tPRO\tAT\tBT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", a[i][0], a[i][1], bt[i], a[i][4], a[i][3]);
    }
    printf("Average turnaround time: %f\n", ttat/n);
    printf("Average waitinng time: %f\n", twt/n);
    return 0;
}

