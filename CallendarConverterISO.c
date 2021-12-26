#include <stdio.h>
#include "convert_integer.h"
int main(int argc, char *argv[]){
    int day=1;
    int month=0;
    int year=0;
    int ordinalday=0;
    int i;
    int monthLengths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int d;
    int week;
    /*day = get_integer();
	month = get_integer();
	year = get_integer();*/
    int dow(int ordinalday, int year);
     int p(int year);
     int calculate_weeks_in_year(int year);
 int floorm(int n);
 int calculate_week(int ordinal_day, int weekday , int year);

    scanf("%d",&day);
scanf("%d",&month);
scanf("%d",&year);
    printf("%d-%02d-%02d\n" ,year , month , day);

    if((year%4)==0){
          monthLengths[1] =29;
        if((year%100)==0){
               monthLengths[1] =28;
            if(year%400 ==0){
                 monthLengths[1] =29;
            }
    }
    }

   for(i=0;i<month-1; i++){
    ordinalday += monthLengths[i];
   }

    ordinalday+=day;
    printf("%d-%.3d\n" ,year, ordinalday );
   d = dow(ordinalday,year);
   week=calculate_week(ordinalday,d,year);
   if(week==1 && month ==12){
       year++;
   }else if(month==1 && (week==52 || week ==53)){
       year--;
   }
   printf("%d-W%02d-%d\n",year,week,d);
return 0;
}

int floorm(int n){
    return n;
}
int dow(int ordinalday, int year){
     int day1, dayoftheweek;
    day1 = ((1 + (5 * ((year-1) % 4)) + (4 * ((year-1) % 100)) + (6 * ((year-1) % 400))) % 7);
    if (day1== 0){
        day1 = 7;
    }
    ordinalday = ordinalday -1;
    ordinalday = (ordinalday % 7);
    dayoftheweek = day1 + ordinalday;
    if (dayoftheweek > 7){
        dayoftheweek = (dayoftheweek % 7);
    }
    return dayoftheweek;
}

int p(int year){
    return ((year + (year / 4) - (year / 100) + (year / 400))%7);
}

int calculate_weeks_in_year(int year){
    if(p(year)== 4 || p(year-1) ==3){
        return 53;
    }else{
        return 52;
    }
}

int calculate_week(int ordinal_day, int weekday , int year){
    int week = (ordinal_day - weekday +10) /7;
    if (week == 0){
        week=calculate_weeks_in_year(year-1);
    }else if(week>calculate_weeks_in_year(year)){
        if(weekday<4){
            week = 1;
        }
    }
    return week;
}

