#include<stdio.h>
int OddDays;
int main()
{
int date,month,year,leapyears,staticyear;
printf("\t***** FIND THE DAY OF THE WEEK *****\n\n");
printf("Enter date in th format(dd/mm/yyyy): ");
scanf("%d/%d/%d",&date,&month,&year);
if(date<=0||date>31||year<=0){printf("\n\tWrong Expression\n\n");goto Last;}
staticyear=year;
if(staticyear%4!=0&&month==2&&date>=29){printf("\n\tWrong Expression\n\n");goto Last;}
switch(month)
{
case 4:
case 6:
case 9:
case 11:
  if(date>=31){printf("\n\tWrong Expression\n\n");goto Last;}

}
year--;
year%=400;//printf("year:%d\n",year);
if(year>300){OddDays+=1;year-=300;}//printf("OddDays:%d\n",OddDays);printf("year:%d\n",year);}
else if(year>200&&year<300){OddDays+=3;year-=200;}//printf("OddDays:%d\n",OddDays);printf("year:%d\n",year);}
else if(year>100&&year<200){OddDays+=5;year-=100;}//printf("OddDays:%d\n",OddDays);printf("year:%d\n",year);}

leapyears=year/4;//printf("leap year:%d\n",leapyears);
year=year-leapyears;//printf("year:%d\n",year);
OddDays+=((leapyears*2)+year);//printf("OddDays:%d\n",OddDays);

switch(month)
{
    case 1:OddDays+=0;break;
    case 2:OddDays+=3;break;
    case 3:OddDays+=3;break;
    case 4:OddDays+=6;break;
    case 5:OddDays+=8;break;
    case 6:OddDays+=11;break;
    case 7:OddDays+=13;break;
    case 8:OddDays+=16;break;
    case 9:OddDays+=19;break;
    case 10:OddDays+=21;break;
    case 11:OddDays+=26;break;
    case 12:OddDays+=26;break;
    default:{printf("Wrong Expression");goto Last;}
}
//printf("OddDays:%d\n",OddDays);
OddDays+=date;
//printf("OddDays:%d\n",OddDays);
if(staticyear%100==0)
{
if(staticyear%400==0)OddDays+=1;
}
else if(staticyear%4==0)OddDays+=1;
//printf("OddDays:%d\n",OddDays);
OddDays%=7;
//printf("OddDays:%d\n",OddDays);
printf("\n\t\t");
switch(OddDays)
{
    case 0:printf("SUNDAY");break;
    case 1:printf("MONDAY");break;
    case 2:printf("TUESDAY");break;
    case 3:printf("WEDNESDAY");break;
    case 4:printf("THURSDAY");break;
    case 5:printf("FRIDAY");break;
    case 6:printf("SATURDAY");break;

    default:printf("Incorrect");
}
printf("\n");
Last:
 return 0;
}
