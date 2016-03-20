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

long int convert(char *);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *p[10];
	if (A == NULL||B == NULL)
		return NULL;
	int i=0,j=0,k=0;
	long int date1, date2;
	while (i < ALen&&j < BLen)
	{
		date1 = convert((A + i)->date);
		date2 = convert((B + i)->date);
		if (date1 < date2)
		{
			p[k++] = A + i;
			i++;
		}
		else if (date2< date1)
		{
			p[k++] = B + j;
			j++;
		}
		else
		{
			p[k++] = A + i;
			i++;
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
long int convert(char *s)
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