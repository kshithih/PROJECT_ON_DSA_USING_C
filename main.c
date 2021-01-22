#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define qmax 15
int y=0,n2,n3;
int x;
int z=0,p=0,o=0;
int l=0,m=0,n=0;
int q[qmax];
int front=0,rear=-1,count=0;
void booktable();
int dinnerfinished();
void viewtables();
void savefile();
int main()
{
int ch;
printf("\n\nHELLO , HAVE A NICE DAY :-)\n");
printf("\n 1:Book a seat\n");
printf("\n     a.TWO SEATER TABLE\n");
printf("\n     b.THREE SEATER TABLE\n");
printf("\n     c.SIX SEATER TABLE\n");
printf("\n 2:Delete reserved table token\n");
printf("\n 3:View tables\n");
printf("\n 4:Save in file\n");
printf("\n 5.Exit\n\n");
while(1)
{
printf("\nEnter your choice  ");
scanf("%d",&ch);


switch(ch)
{
case 1:
       printf("Enter your choice among 3 seats to book table :\n 1.TWO SEATER TABLE \n 2.FOUR SEATER TABLE \n 3.SIX SEATER TABLE\n ");
       int n2;
scanf("%d",&n2);
    switch(n2)
    {

        case 1:

            booktable();
            l=l+1;
            z=z+1;
            if(z==5){
            printf(" Token Number given above  is succefully booked . But Please wait for a while inorder to book further tables in 2 seater tables. :-)\n");
            }
            break;
        case 2:
            booktable();
            m=m+1;
            o=o+1;
            if(o==5){
            printf("All tables amongst 4 seater tables are full.\n\tPlease wait for a while\n");
            }

            break;
        case 3:
            booktable();
            n=n+1;
            p=p+1;
            if(p==5){
            printf("All tables amongst 6 seater tables are full.\n\t\tPlease wait for a while\n");
            }


            break;

  }
break;
case 2:
printf("Enter your choice amongst 3 table types  to delete :\n 1.TWO SEATER TABLE \n 2.FOUR SEATER TABLE \n 3.SIX SEATER TABLE\n");
scanf("%d",&n3);

      switch(n3)
      {

        case 1:
            dinnerfinished();
            if(count==-1){
            printf("Two Seater Tables are Empty.\n\n");
            }
            z=z-1;

              break;
        case 2:

            dinnerfinished();
            if(count==-1){
            printf("Four Seater Tables are Empty.\n\n");
            }
            o=o-1;

              break;
        case 3:
            dinnerfinished();
            if(count==-1){
            printf("Six Seater Tables are Empty.\n\n");
            }
             p=p-1;

                break;
}
break;

case 3: viewtables();
        break;
case 4:
        savefile();
        printf("SAVED SUCCESSFULLY!!!\n\n");
        break;
case 5:
        exit(0);
        break;
default:
        printf("Invalid option\n");
}
}
}

void booktable(int table1,int table2,int table3)
{
int x;
if((front==0&&rear==qmax-1)||(front>0&&rear==front-1)){
printf("All tables are full.\n\t\tPlease wait for a while\n");
}
else
{
printf("\nEnter the token no.\n");
scanf("\n%d",&x);
    if(rear==qmax-1&&front>0)
    {
        rear=0;      //if front is not equal to 0  and rear is at last position./
        q[rear]=x;   //    we must initialize rear =0 and add elements to rear
    }
    else
    {
    if((front==0&&rear==-1)||(rear!=front-1))
    q[++rear]=x;
    }
}
y=y+1;
}
int dinnerfinished()
{
int a;
printf("Enter token number of person finishing his/her meal:\n\n ");
scanf("%d",&a);
if((front==0)&&(rear==-1))
{
printf("Restaurant is completely empty.\n\t\tPlease book some seats\n");
return 0;
}
if(front==rear)
{
a=q[front];   //when there is only 1 element in list then initialize rear to -1 and front as 0
rear=-1;
front=0;
}
else if(front==qmax-1)
{
a=q[front];     //when front points to last element of queue then initialize front as 0
front=0;
}
else
{                                       //as deleting in between element is not possible in circular queue
    int index;                                   //so we used deletion of element based on search key.Hence, element
                                        //can be deleted even if it's present in middle of other elements.
    for(int i = 0; i < qmax; i++)
    {
        if(q[i] == a)
        {
            index = i;
            break;
        }
    }
if(index != -1)
    {
        //for deleting in between token numbers
        for(int i = index; i < qmax- 1; i++)
            q[i] = q[i+1];
            rear=rear-1;
    }
}

printf("Token number %d is succesfully removed.\n\n",a);
return  0;
}


void viewtables()
{
  int i,j;
  int token(int x);
   printf("NUMBER OF AVAILABLE TABLES ( 2 SEATER):%d\n\n",5-z);  //displaying number of available seat by subtracting respective seater tables by the
   printf("NUMBER OF AVAILABLE TABLES ( 4 SEATER):%d\n\n",5-o);  //number of tables booked in respective seater tables
   printf("NUMBER OF AVAILABLE TABLES ( 6 SEATER):%d\n\n",5-p);
if(front==0&&rear==-1)
{
printf("Restaurant is completely empty.\n\t\tPlease book some seats\n");
return;
}

i=front;
if(front<=rear)
{
    while(i<=rear)
{
        printf("%d\t",q[i++]);
}
}
else
{
while(i<=qmax-1)
{
            printf("%d\t",q[i++]);
}
i=0;
while(i<=rear)
{
    printf("%d\t",q[i++]);
}
}
    printf("\n");

}

void savefile()
{
  FILE* fp= fopen("output.txt", "w");
   //this file management concept gives total number of tables booked on that particular day and saves it in external file.
  fprintf(fp,"Date : %s\n",__DATE__);
  fprintf(fp,"TOTAL NUMBER OF 2 SEATER TABLE RESERVED : %d\n",l);
  fprintf(fp,"TOTAL NUMBER OF 4 SEATER TABLE RESERVED : %d\n",m);
  fprintf(fp,"TOTAL NUMBER OF 6 SEATER TABLE RESERVED : %d\n",n);
  fprintf(fp,"TOTAL NUMBER OF TABLES RESERVED TODAY : %d",y);
  fclose(fp);
}
