//7. a. Read sequences of positive integer numbers (reading of each sequence ends by 0, reading of
//all the sequences ends by -1) and determine the maximum element of each sequence and the
//maxim element of the global sequence.
//b. Given a vector of numbers, find the longest contiguous subsequence such that all elements are
//in a given interval.

#include <stdio.h>
#include <stdlib.h>

void afisare(int *p1, int *p2)
{
	// function for displaying values between two pointers
	// Input: p1 - int pointer; p2 - int pointer;
	// Output: the values between them on the screen
	while (p1 <= p2)
	{
		printf("%d ", *p1);
		p1 += 1;
	}
	printf("\n");
}

void maximums(int *x, int *y)
{
	//function which solves the first task
	//Input: two pointers where the beginning and the ending of the array where the maximums are stored

	int c = 0, maxx_seq = -1, maxx_global = -1, i = 0;
	// the array is declared statically such that the values calculated remain in memory
	int static a[100];
	printf("Enter the sequences: ");
	scanf("%d", &c);
	while (c != -1)
	{
		//since the elements are natural numbers, we initialize the maximum of the current seq. with -1
		maxx_seq = -1;
		//sequential finding of the maximum of the sequence
		while (c != 0 && c != -1)
		{
			if (c > maxx_seq)
				maxx_seq = c;
			scanf("%d", &c);
		}
		//the maximum found is compared to the global maximum in order to determine the latter
		if (maxx_seq > maxx_global)
			maxx_global = maxx_seq;
		//the maximum of the current sequence is stored in the array
		i++;
		a[i] = maxx_seq;
		if (c == -1)
			break;
		scanf("%d", &c);
	}
	i++;
	a[i] = maxx_global;
	printf("The maximums are: ");
	//the beggining and ending of the sequence are stored as the values of the pointers given
	*x = &a[1];
	*y = &a[i];
}

void sequence(int *x, int *y)
{
	//function which solves the second task
	//Input: two pointers where the beginning and the ending of the array where the asked sequence is stored
	//Output: no return per se, but the values of the pointers are altered
	int n = 0, i = 0, c = 0, b = 0, len = 0, end_pos = 0, max_len = 0, aux = 0;
	int static a[100];

	//the length and the elements are read from the keyboard
	printf("The length of the array: ");
	scanf("%d", &n);
	printf("The elements: ");
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	//the interval bounds are read from the keyboard
	printf("Lower Bound: ");
	scanf("%d", &c);
	printf("Upper Bound: ");
	scanf("%d", &b);

	if (b < c)
	{
		aux = c;
		c = b;
		b = aux;
	}

	for (i = 1; i <= n; i++)
	{
		// if the current element is in the interval, the length of the sequence is increased, otherwise is set to 0 again
		if (a[i] >= c && a[i] <= b)
			len++;
		else
			len = 0;
		// we compare the length of the current sequence with maximum obatined till then
		// in the affirmative case, the max is updated, and the end-position is retained
		if (len > max_len)
		{
			max_len = len;
			end_pos = i;
		}
	}
	// the positions of the starting and ending elements are stored in the given pointers 
	*y = &a[end_pos];
	*x = &a[end_pos - max_len + 1];

}

int prime(int n)
{
	//function for checking if a number is prime;
	//Input: n type int
	//Output: 1- if prime, 0 otherwise;
	if (n <= 0 || n == 1)
		return 0;
	if (n == 2 || n == 3)
		return 1;
	int i = 2;
	while (i <= n/2)
	{
		if (n%i == 0)
			return 0;
		i++;
	}
	return 1;
}

void allprimes(int n, int *x, int *y)
{
	int i = 0, j = 0;
	int static a[10000];
	for (i = 0; i <= n; i++)
		if (prime(i) == 1)
		{
			a[j] = i;
			j++;
		}
	*x = &a[0];
	*y = &a[j - 1];
}


int main()
{
	int c;
	int b;
	c = 1;
	b = 2;
	
	while(1)
	{
		printf("1. Read sequences of positive integer numbers (reading of each sequence ends by 0, reading of \n");
		printf("all the sequences ends by -1) and determine the maximum element of each sequence and the maxim \n");
		printf("element of the global sequence.");
		printf("\n");
		printf("2. Given a vector of numbers, find the longest contiguous subsequence such that all elements are in a given interval. \n");
		printf("3. Generate all the prime numbers smaller than a given natural number n. \n");
		printf("0. Exit \n");
		int a;
		printf("Give your command: ");
		scanf("%d", &a);
		if (a == 1)
		{
			maximums(&c, &b);
			afisare(c, b);
		}
		else
			if (a == 2)
			{
				sequence(&c, &b);
				afisare(c, b);
			}
			else
				if (a == 3)
				{
					int n;
					printf("n = ");
					scanf("%d", &n);
					printf("The primes numbers smaller than n are: ");
					allprimes(n, &c, &b);
					afisare(c, b);

				}
				else
					if (a == 0)
						break;
					else
						printf("Wrong command! \n");
	}
	return 0;
}
