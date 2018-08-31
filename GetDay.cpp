#include <iostream>
#include <math.h>
using namespace std;

int leapYear(int);
int errorHandle(int[],int,int);
int getDay(int,int,int,int);
int numDays(int);
int zeller (int);
void printDay(int);

int main()
{
	
	cout<< "Enter a date with the following: DAY MONTH YEAR \n"; 
	
	int month,day;
	int year[2]; 
	int weekDay;
	int zMonth;
	
	int errorCode;
	
	cin >> day >>  month >> year[0] >> year[1];
	
	// day, month, century, year)
	// march =1 , febuary = 12
	zMonth = zeller(month);

	weekDay = (getDay(day,zMonth,year[0],year[1])%7);
	

	
	cout <<"On " << day <<"/" << month <<"/" << year[0] << year[1] << " The day of the week is: ";
	printDay(weekDay);
	cout<<"\n";
	return 0;
}


// 1 for leap year
// 2 for not leap year
int leapYear(int year)
{
	int leap;
	if(year % 4 == 0)
	{
		if (year % 400 == 0 || year % 100 == 0 )
		{
			leap = 2;
		}
		else{
			leap = 1;
		}
	}
	else
	{
		leap = 2;
	}
	return leap;
	
}

// 1 for error
// 2 for no error
int errorHandle (int year[2], int month, int day)
{
	int errorNum;
	
	if (year < 0 || *year > 8000)
	{
		errorNum = 1;
	}
	else if (month < 0 || month > 13)
	{
		errorNum = 1;
	}
	else if (day < 0 || day > 32)
	{
		errorNum = 1;
	}
	else {
		errorNum = 2;
	}
	
	return errorNum;
}

//Returns the number of days in a month
int numDays(int month)
{
	int daysNum;
	
	if (month == 1 || month == 3 || month == 5 || month == 6 || month == 7 || month == 8 ||month == 10 || month ==12)
	{
		daysNum = 31;
	}
	else if (month == 2)
	{
		daysNum = 28;
	}
	else 
	{
		daysNum = 30;
	}
	return daysNum;
}

// k = day
// m = month
// c = century (1987, c= 19)
// y = year
// Calculate the day of the week 
int getDay (int k, int m , int c , int y)
{
	
	int weekDay;
	int rounded;
	weekDay = k + ((13 * m-1)/5) + y + (y/4) + (c/4) - 2*c;
	
	//rounded = round(weekDay);
	
	return weekDay;
}

//Converts Gregorian Month into zeller month
int zeller(int bMonth)
{
	int zMonth;
	
	switch (bMonth)
	{
		//January
		case 1: 
		zMonth = 11;
		break;
		
		//Febuary
		case 2:
		zMonth = 12;
		break;
		
		//March 
		case 3:
		zMonth = 1;
		break;
		
		//April
		case 4:
		zMonth = 2;
		break;
		
		//May
		case 5:
		zMonth = 3;
		break;
		
		//June
		case 6:
		zMonth = 4;
		break;
		
		//July
		case 7:
		zMonth = 5;
		break;
		
		//August
		case 8:
		zMonth = 6;
		break;
		
		//September
		case 9:
		zMonth = 7;
		break;
		
		//October
		case 10:
		zMonth = 8;
		break;
		
		//November
		case 11:
		zMonth = 9;
		break;
		
		//December
		case 12:
		zMonth = 10;
		break;
		
		default:
		return zMonth;
	}
	return zMonth;
	
}

//Prints the day of the week 
void printDay(int day)
{
	switch(day)
	{
		case 0:
		cout << "Sunday";
		break;
		
		case 1:
		cout << "Monday";
		break;
		
		case 2:
		cout << "Tuesday";
		break;
		
		case 3:
		cout << "Wednesday";
		break;
		
		case 4:
		cout << "Thursday";
		break;
		
		case 5:
		cout << "Friday";
		break;
		
		case 6:
		cout << "Saturday";
		break;
		
		default:
		cout << "ERROR";
		break;
	}
	
}
