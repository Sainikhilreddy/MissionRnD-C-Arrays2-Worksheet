/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
int checkdate(int,int,int);
int strtoint(char *, int);
int notleap(int, int);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i, dt1, dt2, mn1, mn2, yr1, yr2,l;
	if (Arr == NULL)
		return -1;
	dt1 = strtoint(date, 2);
	mn1 = strtoint(date + 3, 2);
	yr1 = strtoint(date + 6, 4);
	if (checkdate(dt1, mn1, yr1) == -1)
		return -1;
	else
	{
		for (i = 0,l=0;l!=1&&i < len; i++)
		{
			dt2 = strtoint(&((Arr+i)->date[0]), 2);
			mn2 = strtoint(&((Arr+i)->date[3]), 2);
			yr2 = strtoint(&((Arr+i)->date[6]), 4);
			if (yr2 > yr1)
				l++;
			else if (yr2 == yr1)
			{
				if (mn2 > mn1)
					l++;
				else if (mn2 == mn1)
					if (dt2 > dt1)
						l++;
			}
		}
		if (l == 1)
			l += len - i;
	}
	return l;
}
int checkdate(int dt,int mn,int yr)
{
	if ((yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0)
	{
		if (mn == 2)
		{
			if (dt <= 29)
				return 1;
			else
				return -1;
		}
		else
			return notleap(mn, dt);
	}
	else if (mn == 2)
	{
		if (dt <= 28)
			return 1;
		else
			return -1;
	}
	else
		return notleap(mn, dt);
		
}
int notleap(int mn, int dt)
{
	if (mn == 4 || mn == 6 || mn == 9 || mn == 11)
	{
		if (dt <= 30)
			return 1;
		else
			return -1;
	}
	else if (dt <= 31)
		return 1;
	else
		return -1;
}
int strtoint(char *s, int l)
{
	int i, t;
	for (i = 0, t = 0; i < l; i++)
		t = t * 10 + (s[i] - '0');
	return t;
}
