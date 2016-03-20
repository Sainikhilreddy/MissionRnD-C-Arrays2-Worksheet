/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<stdio.h>

int findSingleOccurenceNumber(int *A, int len) {
	int i1, i2, j, l1, l2;
	if (A == NULL)
		return -1;

	for (i1 = 0, i2 = len - 1; i1 < i2; i1++, i2--)
	{
		l1 = l2 = 1;
		for (j = i1; j < i2; j++)
		{
			if (A[i1] == -1)
				l1 = -2;
			else if (A[j] != -1 && i1 != j&&A[i1] == A[j])
			{
				l1++;
				A[j] = -1;
			}
			if (A[i2] == -1)
				l2 = -2;
			else if (A[j] != -1 && i2 != j&&A[i2] == A[j])
			{
				l2++;
				A[j] = -1;
			}
		}
		if (l1 == 1)
			return A[i1];
		else if (l1==3)
			A[i1] = -1;
		if (l2 == 1)
			return A[i2];
		else if (l2==3)
			A[i2] = -1;
	}
	
}