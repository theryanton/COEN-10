/* Ryan Ton
 * COEN 10
 * Lab 9
 * Tuesday 2:15pm
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10
#define SIZE 20

int main();
void input();
void reverse();
void uppercase();
void info();
void output();

char words[MAX][SIZE] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
int length[MAX] = {0,0,0,0,0,0,0,0,0,0};
int counter = 0;

int main()
{
	input();
	reverse();
	uppercase();
	info();
	return 1;
}

void input()
{
	int i, j, k, x;
	char temp[SIZE];

	printf("Input 10 strings below:\n");
	for (i=0; i<MAX; i++)
	{
		x = scanf("%s", words[i]);
		if (words[i][0] != '\0')
			counter++;
		if (x<1)
			break;
	}
	fflush(stdin);
	for (i=0; i<counter; i++)
	{
		for (j=i+1; j<counter; j++)
		{
			strcpy (temp, words[j]);
			if (strcasecmp(words[i], words[j]) > 0)
			{
				for (k=j; k>i; k--)
				{
					strcpy (words[k], words[k-1]);
				}
				strcpy (words[i], temp);
			}
		}
	}
	printf("Your strings in ABC order:\n");
	output();
	return;
}

void reverse()
{
	int i;
	int j = counter-1;
	char temp[SIZE];

	for (i=0; i<j; i++, j--)
	{
		strcpy (temp, words[i]);
		strcpy (words[i], words[j]);	
		strcpy (words[j], temp);
	}
	printf("Your strings in reverse ABC order:\n");
	output();
	return;
}

void uppercase()
{
	int i, currentlength = 0;
	char *p;
	
	for (i=0; i<counter; i++)
	{
		currentlength = 0;
		p = words[i];
		while (*p != '\0')
		{
			currentlength++;
			if (islower(*p))
			{
				*p = toupper(*p);
			}
			p++;
		}
		length[i] = currentlength;
	}
	printf("Your strings in all caps:\n");
	output();
	return;
}

void info()
{
	int i, sum = 0, longest = 0, shortest = 0;

	for (i=0; i<counter; i++)
	{
		sum += length[i];
		if (length[i] > length[longest])
		{
			longest = i;
		}
		else if (length[i] < length[shortest])
		{
			shortest = i;
		}
	}
	printf("Shortest string: %s\n", words[shortest]);
	printf("Longest string: %s\n", words[longest]);
	printf("Average length of strings: %d\n", sum/counter);
	printf("Strings that don't start with letters:\n");
	for (i=0; i<counter; i++)
		if (!isalpha(words[i][0]))
			printf("%s\n", words[i]);
	return;
}

void output()
{
	int i;

	for (i=0; i<counter; i++)
	{
		printf("%s\n", words[i]);
	}
	return;
}
