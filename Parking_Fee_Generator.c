#include<stdio.h>
#define AmountPerDay 3.50
#define NoOfDayException 2

struct date{
int dd,mm,yyyy;
}first,second;

int monthDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};

void calc_amt(int days)
{
    //printf("\nDays:%d",days);
    float amt;
    if((days-NoOfDayException)>0)
        {
            amt=(days-NoOfDayException)*AmountPerDay;
            printf("\n\tAmount Payable for %d Days is %.2f\n",days,amt);
        }
    else
    printf("\n\tNo fine\n");

}

int daysInMonth(int month,int year)
{
    int i,days_in_month=0;
    for(i=0;i<month-1;i++)
    {

        if(i==1)
        {
            if(year%100==0)
            {//printf("\nEntered 100th year loop");
                if(year%400==0)
                    days_in_month+=29;
                else
                    days_in_month+=28;
                continue;
            }
            if(year%4==0)
                days_in_month+=29;
            else
                days_in_month+=28;

        }
        else
            {
             days_in_month+=monthDays[i];
            //printf("Days_in_month[%d]:%d",i,days_in_month);
            }
    }
    return days_in_month;
}

void calc_days(int d1,int m1,int y1,int d2,int m2,int y2)
{
    int days=0,i;
    for(i=y1;i<y2;i++)
    {
        if(i%100==0)
        {
            if(i%400!=0)
            days+=365;
            else
            days+=366;
            continue;
        }
        if(i%4==0)
            days+=366;
        else
            days+=365;
    }
    //printf("\nDifference in years:%d",days);
    days-=daysInMonth(m1,y1);
    //printf("\nAfter Subtraction of the first date's month:%d",days);
    days-=d1;
    //printf("\nAfter Subtraction of the first date:%d",days);
    days+=daysInMonth(m2,y2);
    //printf("\ndays in month(m2,y2):%d",daysInMonth(m2,y2));
    //printf("\nAfter Addition of the second date's month:%d",days);
    days+=d2;
    //printf("\nAfter Addition of the second date:%d",days);
    if(days<0)
        days=days*-1;
    calc_amt(days);
}

int main()
{
    printf("\t__________________ PARKING FEE GENERATOR ____________________\n");

    printf("\n\tEnter the Incoming date(dd/mm/yyyy): ");
    scanf("%d/%d/%d",&first.dd,&first.mm,&first.yyyy);

    printf("\n\tEnter the OutGoing date(dd/mm/yyyy): ");
    scanf("%d/%d/%d",&second.dd,&second.mm,&second.yyyy);

    if(first.yyyy<=second.yyyy)
        calc_days(first.dd,first.mm,first.yyyy,second.dd,second.mm,second.yyyy);
    else
        calc_days(second.dd,second.mm,second.yyyy,first.dd,first.mm,first.yyyy);

    printf("\n\t_________________________ END ______________________________\n");

    return 0;
}
