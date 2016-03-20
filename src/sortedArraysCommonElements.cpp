/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

long int converttoint(char *);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction p[10] ;
	if (A == NULL || B == NULL)
		return NULL;
	int i , j , k;
	long int date1, date2;
	for (i = 0,k=0; i < ALen; i++)
	{
		date1 = converttoint((A + i)->date);
		for (j = 0; j < BLen; j++)
		{
			date2 = converttoint((B + j)->date);
			if (date1 == date2)
			{
				(p + k)->amount = (B + j)->amount;
				strcpy((p + k)->date, (B + j) -> date);
				strcpy((p + k)->description, (B + j)->description);
				k++;
			}
		}
	}
	if (k == 0)
		return NULL;
	else
		return p;
}
long int converttoint(char *s)
{
	int i;
	long int t;
	for (i = 0, t = 0; s[i]; i++)
	{
		if (i != 3 && i != 5)
			t = t * 10 + (s[i] - '0');
	}
	return t;
}