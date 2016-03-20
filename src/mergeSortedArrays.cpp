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
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *p[10];
	if (A == NULL||B == NULL)
		return NULL;
	int i = 0, j = 0, k = 0, dt1, dt2, mn1, mn2, yr1, yr2;
	 
	while (i < ALen&&j < BLen)
	{
		dt1 = convert(&((A + i)->date[0]), 2);
		dt2 = convert(&((B + j)->date[0]), 2);
		mn1 = convert(&((A + i)->date[3]), 2);
		mn2 = convert(&((B + j)->date[3]), 2);
		yr1 = convert(&((A + i)->date[6]), 4);
		yr2 = convert(&((B + j)->date[6]), 4);
		if (yr1 < yr2)
		{
			p[k++] = A + i;
			i++;
		}
		else if (yr2 < yr1)
		{
			p[k++] = B + j;
			j++;
		}
		else if (mn1 < mn2)
		{
			p[k++] = A + i;
			i++;
		}
		else if (mn2 < mn1)
		{
			p[k++] = B + j;
			j++;
		}
		else if (dt1 <= dt2)
		{
			p[k++] = A + i;
			i++;
		}
		else
		{
			p[k++] = B + j;
			j++;
		}
		
	}
	if (i<ALen)
		while (i < ALen)
		{
			p[k++] = A + i;
			i++;
		}
	else
		while (j < BLen)
		{
			p[k++] = B + j;
			j++;
		}
	for (i = 0; i < ALen + BLen; i++)
	{
		
		(A + i)->amount = p[i]->amount;
		strcpy((A + i)->date, p[i]->date);
		strcpy((A + i)->description, p[i]->description);
	}
	
}
int convert(char *s,int l)
{
	int i, t;
	for (i = 0, t = 0; i<l; i++)
			t = t * 10 + (s[i] - '0');
	return t;
}