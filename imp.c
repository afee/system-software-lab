#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct
{
char dname[10],fname[10][10];
int fcnt;
}dir,dir1[10];
void main()
{
  int i,ch,j,o,y,k,z,dcnt=0,l;
  char f[30],d[30];
  do{
     printf("\n File Organisation Techniques \n 1.Single level directory \n 2.Two level directory \n 3.Heirarchical\n Enter your option\n");
     scanf("%d",&o);
       switch(o)
       {
       case 1:                                           // Single Level Directory Organisation
         printf("\n Single level directory\n");                            
         dir.fcnt = 0;
         printf("Enter name of directory:");
         scanf("%s", dir.dname);
	 do
	 {
		printf("1.Create File\n2.Delete File\n3.Search File\n4.Display Files\n5.Exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the name of the file:");
				scanf("%s",dir.fname[dir.fcnt]);
                                printf("File created \n");
				dir.fcnt++;
			break;
			case 2: printf("Enter the name of the file:");
				scanf("%s",f);
				for(i=0;i<dir.fcnt;i++)
				{
					if(strcmp(f, dir.fname[i])==0)
					{
						printf("File %s is deleted\n",f);
						for(j=i;j<dir.fcnt;j++)
						{
							strcpy(dir.fname[j],dir.fname[j+1]);
						}
                                                 break;
					}
				}
				if(i==dir.fcnt)
					printf("File %s not found\n",f);
				else
					dir.fcnt--;
                         q:break;
			case 3: printf("Enter the name of the file:");
				scanf("%s",f);
				for(i=0;i<dir.fcnt;i++)
				{
					if(strcmp(f, dir.fname[i])==0)
					{
						printf("File %s is found\n", f);
						goto p;
					}
				}
				if(i==dir.fcnt)
					printf("File %s not found\n",f);
			p:break;
			case 4: if(dir.fcnt==0)
				printf("Directory is Empty\n");
				else
				{
					printf("The Files are\n");
					for(i=0;i<dir.fcnt;i++)
						printf("\t%s",dir.fname[i]);
					printf("\n");
				}
			break;
		     default: goto s;
		}
		printf("\nIf you want to continue,press 1\n");
		scanf("%d",&y);
	    }while(y==1);
          break;

        case 2:                                            //Two level Directory Organisation
           do{
            printf("\nTwo level directory\n");
	    printf("\n\n1.Create directory\n2.Create File\n3.Delete File\n4.Search File\n5.Display\n6.Exit\nEnter your choice\n");
	    scanf("%d",&ch);
	    switch(ch)                                     
	     {
		case 1: 
		    printf("Enter the name of directory:");
			scanf("%s",d);
			for(i=0;i<dcnt;i++)
			{
				if(strcmp(d,dir1[i].dname)==0)
				{
					printf("Directory already exists,Give another name fordirectory:");
                                                     
					scanf("%s",d);
					break;
				}
			}
			strcpy(dir1[dcnt].dname,d);
			dir1[dcnt].fcnt=0;
			dcnt++;
			printf("Directory created");
	          break;

                case 2:  
                      printf("\nEnter name of the directory to which file is to be added: ");
		      scanf("%s",d);
		      for(i=0;i<dcnt;i++)
                       {
                         if(strcmp(d,dir1[i].dname)==0)
                         {
	   printf("Enter name of the file: ");
		           scanf("%s",dir1[i].fname[dir1[i].fcnt]);
		           dir1[i].fcnt++;
                           printf("File created");
                           break;
                          }
                        }
                       if(i==dcnt)
                         printf("Directory %s not found",d);
                break;

              case 3: 
	    printf("\nEnter name of the directory:");
	    scanf("%s",d);
	    for(i=0;i<dcnt;i++)
	    {
	      if(strcmp(d,dir1[i].dname)==0)
             {
               printf("Enter name of the file to be deleted: ");
               scanf("%s",f);
	       for(k=0;k<dir1[i].fcnt;k++)
               {
                if(strcmp(f, dir1[i].fname[k])==0)
                {
                printf("File %s is deleted ",f);
                  for(j=i;j<dir1[i].fcnt;j++)
                          strcpy(dir1[i].fname[k],dir1[i].fname[dir1[i].fcnt]);
                  dir1[i].fcnt--;
                  goto m;
               }
              }
           printf("File %s not found",f);
           goto m;
          }          
        }
        printf("Directory %s not found",d);
        m:break;

        case 4:
            printf("\nEnter name of the directory : ");
            scanf("%s",d);
            for(i=0;i<dcnt;i++)
            {
             if(strcmp(d,dir1[i].dname)==0)
              {
                  printf("Enter the name of the file to be searched:");
                  scanf("%s",f);
                 for(k=0;k<dir1[i].fcnt;k++)
                  {
                    if(strcmp(f, dir1[i].fname[k])==0)
                    {
                     printf("File %s is found ",f);
                     goto n;
                    }
                  }
                printf("File %s not found",f);
                goto n;
              }
          }
          printf("Directory %s not found",d);
          n:break;

        case 5:  
            if(dcnt==0)
                printf("\nNo directory's ");
            else
             {
               printf("\nDirectory\tFiles");
               for(i=0;i<dcnt;i++)
               {
                 printf("\n%s\t\t",dir1[i].dname);
                 for(k=0;k<dir1[i].fcnt;k++)
                     printf("\t%s",dir1[i].fname[k]);
                }
             }
         break;

         default:
              goto s;
        }
        printf("\n If you want to continue,press 1\n");
        scanf("%d",&z);
      }while(z==1);

      default:
             exit(0);
    }
    s:printf("\nIf you want to continue the program,press 2\n");
    scanf("%d",&l);
    }while(l==2);
 }

