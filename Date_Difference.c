#include<stdio.h>
void days(int,int,int,int,int,int);
int month(int,int);
int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
int d1,d2,m1,m2,y1,y2;
printf("\t___________ FIND THE DIFFERENCE BETWEEN TWO DATES ___________\n");
printf("\n\tEnter First Date(in format dd/mm/yyyy):");
scanf("%d/%d/%d",&d1,&m1,&y1);
printf("\n\tEnter Second Date(in format dd/mm/yyyy):");
scanf("%d/%d/%d",&d2,&m2,&y2);
if(y2>=y1)
        days(y1,y2,m1,m2,d1,d2);
else
        days(y2,y1,m2,m1,d2,d1);
printf("\n\t_________________________ END ______________________________\n");
    return 0;
}
void days(int y1,int y2,int m1,int m2,int d1,int d2)
{
int count=0,i;
for(i=y1;i<y2;i++)
{

    if(i%4==0)
        count+=366;
    else
        count+=365;
}
//printf("0:%d",count);
count-=month(m1,y1);
//printf("\n1:%d",count);
count-=d1;
//printf("\n2:%d",count);
count+=month(m2,y2);
//printf("\n3:%d",count);
count+=d2;
//printf("\n4:%d",count);

if(count<0)
 {
     count=count*-1;
     //count--;
 }
printf("\n\tThe no. of days between the two dates is %d days\n",count);

}
int month(int a,int yy)
{

    int x=0,c;
    for(c=0;c<a-1;c++)
    {

        if(c==1)
        {
            if(yy%100==0){
                if(yy%400==0)
                    x+=29;
                else
                    x+=28;
            }
            else if(yy%4==0)
                x+=29;
            else
                x+=28;
        }
        else
            x+=mon[c];
        }
        //printf("\nX:%d",x);
        return x;
    }
