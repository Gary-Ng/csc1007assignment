#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TB 10000

void add();
void delete();
void read();
int BFull();
int readFile();
FILE *fp;
struct data{
      char func[6];//to read add, read, delete based on first letter
      int filename;
      int data[];
};
struct Sequence
{
    char n[30];
    int len;
    int st;
}F[30];
int readFile(){

   char file_name[25];
   int i = 0;
   struct data d[10];//basically able to read 10 lines so got 10 different set of data
   char *token;
   char buff[1024];

   printf("Enter name of a file you wish to see\n");
   gets(file_name);

   fp = fopen(file_name, "r"); // read mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");//if file does not exist
      exit(EXIT_FAILURE);
   }
   while(fgets(buff,1024,fp)!= NULL){
       int j = 0;
      token = strtok(buff,",");
      strcpy(d[i].func,token);
      token = strtok(buff,",");
      d[i].filename == atoi(token);
      token = strtok(buff,",");
      while(token!=NULL){
        d[i].data[j] == atoi(token);
        token = strtok(buff,",");
        j++;
      }
      i++;
   }

   
   fclose(fp);

   return 0;

}

int Table[TB],pos=0,r,i,j,ch,B=0;
char fn[30];
int main()
{
       
    printf("\n Contiguous File Allocation \n\n");
    do{
    printf("\n\n1.Add\n2.Delete\n3.Read\n4.Exit");
    printf("\n\nEnter Your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            pos++;
            add();
            break;

        case 2:
            delete();
            break;

        case 3:
            read();
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid Choice ");
    }
    }while(ch!=4);

}
void add()
{
   //printf("\nEnter File Name : ");
   //scanf("%s",&(F[pos].n));
   
   int a =  100;
   //printf("\nEnter File Length : ");
   //scanf("%d",&(F[pos].len));
   F[pos].len = 6;
   if(BFull())
   {
        pos--;
       printf("\n\nNo Enough Free Space Available \n");
       return;
   }
   while(1)
   {
        i=0;
        r=(a);
        if(r+F[pos].len-1>TB)
           continue;
        if(Table[r]==0)
        {
                for(i=r+1;i<r+F[pos].len;i++)
                    if(Table[i]==1)
                        break;
        }
        if(i==r+F[pos].len)
            break;


    }
    F[pos].st=r;
    for(i=r;i<r+F[pos].len;i++)
        Table[i]=1;
    printf("\n\tFile Allocation Table\n");
    printf("\nFileName\tStart\tLength\n");
    for(i=1;i<=pos;i++)
    {
        printf("\n100\t\t%d\t%d",F[i].st,F[i].len);
        printf("\n");
    }

}
void delete()
{
   printf("\nEnter The File Name : ");
   scanf("%s",&fn);
   for(i=1;i<=pos;i++)
   {
            if(strcmp(F[i].n,fn)==0)
            {
                    for(j=F[i].st ;j<(F[i].len+F[i].st);j++)
                        Table[j]=0;
                    strcpy(F[i].n,"NULL");
                    F[i].st=0;
                    F[i].len=0;
                    printf("\nFile (%s) Deleted Successfully \n",fn);
                    break;
            }
            else
                printf("\nDeletion Unsuccessful\n");
    }
    printf("\n\t\tFile Allocation Table\n");
    printf("\nFileName\tStart\tLength\n");
    for(i=1;i<=pos;i++)
    {
        printf("\n%s\t\t%d\t%d",F[i].n,F[i].st,F[i].len);
        printf("\n");
    }
}
void read()
{
    printf("\nEnter The File Name : ");
    scanf("%s",fn);
    printf("\nBlocks Allocated Are : ");
    for(i=1;i<=pos;i++)
    {
        if(strcmp(F[i].n,fn)==0)
        {
            for(j=F[i].st;j<(F[i].st+F[i].len);j++)
                printf("--%d--",j);
            break;
        }
    }
}
int BFull()
{
    for(i=1,B=0;i<=pos;i++)
        B=B+F[i].len;
    if(B>TB)
        return 1;
    else
        return 0;
}
