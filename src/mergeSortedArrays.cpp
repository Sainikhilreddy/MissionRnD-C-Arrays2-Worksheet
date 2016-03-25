 /*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<string.h>

int convert(char *,int);

struct transaction {
	int amount;
	char date[11];
	char description[20];
}p[10];

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL||B == NULL)
		return NULL;
	int i = 0, j = 0, k = 0;
	while (i < ALen&&j < BLen)
	{
		if ((A + i)->amount <= (B + j)->amount)
		{
			(p + k)->amount = (A + i)->amount;
			strcpy((p + k)->date, (A + i)->date);
			strcpy((p + k)->description, (A + i)->description);
			i++;
		}
		else if ((B + j)->amount<(A+i)->amount)
		{
			(p + k)->amount = (B + j)->amount;
			strcpy((p + k)->date, (B + j)->date);
			strcpy((p + k)->description, (B + j)->description);
			j++;
		
		}
		k++;
		}
		
	if (i<ALen)
		while (i < ALen)
		{
			(p + k)->amount = (A + i)->amount;
			strcpy((p + k)->date, (A + i)->date);
			strcpy((p + k)->description, (A + i)->description);
			i++;
			k++;
		}
	else
		while (j < BLen)
		{
			(p + k)->amount = (B + j)->amount;
			strcpy((p + k)->date, (B + j)->date);
			strcpy((p + k)->description, (B + j)->description);
			j++;
			k++;
		}
	return p;
}
int convert(char *s,int l)
{
	int i, t;
	for (i = 0, t = 0; i<l; i++)
			t = t * 10 + (s[i] - '0');
	return t;
}