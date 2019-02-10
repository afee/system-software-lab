#include<stdio.h>
void sjf()
{
	int n,wt[20],bt[20],tat[20],p[20],i,j,ttat=0,pos,total,temp;
	float awt,atat,twt=0;
	printf("Please enter the number of processes :	");
	scanf("%d",&n);
   	printf("Please enter the burst time of each process\n");
	for(i=0;i<n;i++)
	{
	printf("p[%d] ",i);
	scanf("%d",&bt[i]);
	p[i]=i;
	}
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)	
		{
			if(bt[j]<bt[pos])
			pos=j;
		}
	temp=bt[i];
	bt[i]=bt[pos];
	bt[pos]=temp;
	temp=p[i];
	p[i]=p[pos];
	p[pos]=temp;
	
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
	wt[i]=0;
	for(j=0;j<i;j++)
		wt[i]=wt[i]+bt[j];
	twt+=wt[i];
	}
	for(i=0;i<n ;i++)
	{
	tat[i]=bt[i]+wt[i];
	
	ttat+=tat[i];
	}
	awt=(float)twt/n;
	atat=(float)ttat/n;
	printf("Process\tburst time waiting time turn around time \n");
	for(i=0;i<n;i++)
	{
	  printf("%d \t %d \t   %d \t\t %d \n ",p[i],bt[i],wt[i],tat[i]);
	}
	printf("Average waiting time %f\n",awt);
	printf("Average turnaround time %f\n",atat);
}
void fcfs()
{
	int n,wt[20],bt[20],tat[20],i,j,ttat=0,twt=0;
	float awt,atat;
	printf("Please enter the number of processes :	");
	scanf("%d",&n);
   	printf("Please enter the burst time of each process\n");
	for(i=0;i<n;i++)
	{
	printf("p[%d] ",i+1);
	scanf("%d",&bt[i]);
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
	wt[i]=0;
	for(j=0;j<i;j++)
	{
		wt[i]=wt[i]+bt[j];
		
	}
	}
	for(i=0;i<n ;i++)
	{
	tat[i]=bt[i]+wt[i];
	twt+=wt[i];
	ttat+=tat[i];
	}
	awt=(float)twt/n;
	atat=(float)ttat/n;
	printf("Process\tburst time\t waiting time\t turn around time \n");
	for(i=0;i<n;i++)
	{
	  printf("%d \t %d \t %d \t\t %d \n ",i,bt[i],wt[i],tat[i]);
	}
	printf("Average waiting time %f\n",awt);
	printf("Average turnaround time %f\n",atat);
}
void prio()
{
	int n,wt[20],bt[20],tat[20],p[20],i,j,ttat=0,pos,total,temp,pr[20];
	float awt,atat,twt=0;
	printf("Please enter the number of processes :	");
	scanf("%d",&n);
   	printf("Please enter the burst time of each process\n");
	for(i=0;i<n;i++)
	{
	printf("p[%d] ",i);
	scanf("%d",&bt[i]);
	printf("Please  enter priority\n");
	scanf("%d",&pr[i]);
	//p[i]=i+1;
	p[i]=i;
	}
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)	
		{
			if(pr[j]<pr[pos])
			pos=j;
		}
	temp=pr[i];
	pr[i]=pr[pos];
	pr[pos]=temp;
	temp=bt[i];
	bt[i]=bt[pos];
	bt[pos]=temp;
	temp=p[i];
	p[i]=p[pos];
	p[pos]=temp;
	
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
	wt[i]=0;
	for(j=0;j<i;j++)
		wt[i]=wt[i]+bt[j];
	twt+=wt[i];
	}
	for(i=0;i<n ;i++)
	{
	tat[i]=bt[i]+wt[i];
	
	ttat+=tat[i];
	}
	awt=(float)twt/n;
	atat=(float)ttat/n;
	printf("Process\tburst time waiting time turn around time \n");
	for(i=0;i<n;i++)
	{
	  printf("%d \t %d \t   %d \t\t %d \n ",p[i],bt[i],wt[i],tat[i]);
	}
	printf("Average waiting time %f\n",awt);
	printf("Average turnaround time %f\n",atat);
}	
int rr() 
{ 
      int i, limit, total = 0, x, counter = 0, time_quantum; 
      int wait_time = 0, turnaround_time = 0, at[10], bt[10], temp[10]; 
      float average_wait_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &limit); 
      x = limit; 
      for(i = 0; i < limit; i++) 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &at[i]);
            printf("Burst Time:\t");
            scanf("%d", &bt[i]); 
            temp[i] = bt[i];
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &time_quantum); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, bt[i], total - at[i], total - at[i] - bt[i]);
                  wait_time = wait_time + total - at[i] - bt[i]; 
                  turnaround_time = turnaround_time + total - at[i]; 
                  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
            }
            else if(at[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); 
      return 0; 
}
void main()
{
	int choice;
	char ch;
	printf("Please select the file allocatio \n");
	printf("1.SJF\n");
	printf("2.FCFS\n");
	printf("3.PRIORITY\n");
	printf("4.ROUND ROBIN\n");
	//scanf("%d",&choice);
	do
	{
	printf("Please select the file allocation\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		    sjf();
		    break;
		case 2:
		    fcfs();
		    break;
		case 3:
		    prio();
		    break;
		case 4:
		    rr();
		    break;
		default:
			printf("Invalid\n");
	}
	printf ("Do you want to repeat the operation Y/N: ");
	scanf (" %c", &ch);
	}while (ch == 'y' || ch == 'Y');
}

