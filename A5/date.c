#include<stdio.h>

void input(int *month, int *date, int *year)
{
	printf("\nEnter mm dd yyyy: ");
	scanf("%d %d %d", month, date, year);
}

long get_ndays(int month, int date, int year)
{
	long ndays, ncycles;
	int nyears;

	year-=1900;

	ndays=(long)(30.42*(month-1))+date;

	if(month==2)
		ndays++;

	if((month>2)&&(month<8))
		ndays--;

	if((year%4==0)&&(month>2))
		ndays++;

	ncycles=year/4;
	
	ndays+=ncycles*1461;

	nyears=year%4;

	if(nyears>0)
		ndays+=365*nyears+1;

	if(ndays>59)
		ndays--;
	
	return ndays;

}

int convert(int month, int date, int year)
{
	int day= get_ndays(month, date, year)%7;

	return day;

}

int difference(int m1, int d1, int y1, int m2, int d2, int 
y2)
{
	long ndays1= get_ndays(m1, d1, y1);
	long ndays2= get_ndays(m2, d2, y2);

	if(ndays2>ndays1)
		return (ndays2-ndays1);
	else
		 return -(ndays2-ndays1);
}

int main()
{
	int m1, d1, y1, day1, m2, d2, y2, day2;
	
	static char *weekday[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};	

	static char *month[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	printf("DATE 1:\n");
	input(&m1, &d1, &y1);
	day1=convert(m1, d1, y1);
	printf("FORMATTED DATE: %s, %s %d, %d\n", weekday[day1], month[m1-1], d1, y1);

	printf("\nDATE 2:\n");
	input(&m2, &d2, &y2);
	day2=convert(m2, d2, y2);
	printf("FORMATTED DATE: %s, %s %d, %d\n", weekday[day2], month[m2-1], d2, y2);

	printf("\nThe number of days between the two dates is %d\n", difference(m1, d1, y1, m2, d2, y2));

	return 0;
}
