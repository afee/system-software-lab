#include<stdio.h>
void seq()
{
	int i,n,j,b[20],sb[20],t[20],c[20][20];
	printf("Enter number of files	:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter number of blocks occuipied by file f%d ",i+1);
		scanf("%d",&b[i]);
		printf("Enter starting block of file f%d ",i+1);
		scanf("%d",&sb[i]);
		t[i]=sb[i];
		for(j=0;j<b[i];j++)
			c[i][j]=sb[i]++;
	}
	printf("\nFilename start length \n");
	for(i=0;i<n;i++)
	{
		printf("%d	 %d     %d\n",i+1,t[i],b[i]);
	}
}
void ind()
{
	int n,m[20],i,j,sb[20],s[20],b[20][20],x;
	printf("Enter number of files	:	");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("Enter starting block  of file f%d 	",i+1);
	scanf("%d",&sb[i]);
	printf("\nEnter no of blocks occipied by file%d	",i+1);
	scanf("%d",&m[i]);
	printf("\nEnter blocks of file\n ");
	for(j=0;j<m[i];j++)
		scanf("%d",&b[i][j]);
	}
	printf("Filename	index	length \n");
	for(i=0;i<n;i++)
	{
		printf("%d		%d	%d\n",i+1,sb[i],m[i]);
	}
	printf("Enter filename ");
	scanf("%d",&x);
	printf("Filename is %d \n",x);
	i=x-1;
	printf("\n");
	printf("index is %d:",sb[i]);
        printf("\n");
	printf("Blocks occuipied by file");
	for(j=0;j<m[i];j++)
			printf("%3d",b[i][j]);
	printf("\n");
}
struct file
{
	char fname[20];
	int start,size,block[20];
}f[10];
void link()
{
	int i,j,n;
	printf("Enter number of files	:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("Enter filename ");
	scanf("%s",f[i].fname);
	printf("Enter starting block of file ");
	scanf("%d",&f[i].start);
	f[i].block[0]=f[i].start;
	printf("Enter number of block of file ");
	scanf("%d",&f[i].size);
	printf("Enter block number ");
	for(j=1;j<f[i].size;j++)
		scanf("%d",&f[i].block[j]);
	}
	printf("File	start	size	block	\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\t%d\t",f[i].fname,f[i].start,f[i].size);
		for(j=0;j<f[i].size-1;j++)
			printf("%d->",f[i].block[j]);
		printf("%d",f[i].block[j]);
		printf("\n");
	}
}
void main()
{
	int choice;
	char ch;
	printf("Please select the file allocation \n");
	printf("1.Seqential\n");
	printf("2.Indexed\n");
	printf("3.Linked\n");
	
	do
	{
	printf("Please select the file allocation \n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		    seq();
		    break;
		case 2:
		    ind();
		    break;
		case 3:
		    link();
		    break;
		
		default:
			printf("Invalid\n");
	}
	printf ("Do you want to repeat the operation Y/N: ");
	scanf (" %c", &ch);
	}while (ch == 'y' || ch == 'Y');
}
	
