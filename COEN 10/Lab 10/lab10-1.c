/* Ryan Ton
 * COEN 10
 * Lab 10
 * Tuesday 2:15pm
 */

char name[5][20] = {'\0','\0','\0','\0','\0'};
char pets[5][5] = {'\0','\0','\0','\0','\0'};
char phone[5][10] = {'\0','\0','\0','\0','\0'};
int schedule[5] = {0,0,0,0,0};
int counter = 0;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void request();
void cancel();
void list();
void show_firstInitial();
void show_pets();
void priority();
int countLetter(char letter);

int main()
{
	int userinput, hasPriority = 0, number = 0;
	char letter;

	while (1)
	{
		printf("Welcome to the StinkyPetSpa Inc. Scheduling System!\n");
		printf("\n");
		printf("Input 1 to make an appointment.\n");
		printf("Input 2 to cancel an appointment.\n");
		printf("Input 3 to list the full schedule.\n");
		printf("Input 4 to show names starting with a letter.\n");
		printf("Input 5 to show names with a number of pets.\n");
		printf("Input 6 to schedule a priority appointment.\n");
		printf("Input 7 to count the number of occurrences of a letter.\n");
		printf("Input 9 to exit the program.\n");
		printf("Please enter a command:\n");
		scanf("%d", &userinput);

		switch (userinput)
		{
			case 1:
				request();
				break;

			case 2:
				cancel();
				break;

			case 3:
				list();
				break;

			case 4:
				show_firstInitial();
				break;

			case 5:
				show_pets();
				break;

			case 6:
				if (hasPriority == 0)
					priority();
					hasPriority = 1;
				if (hasPriority == 1)
					printf("No more priortity appointments available today.\n");
				break;

			case 7:
				printf("Please enter a letter:\n");
				scanf(" %c", &letter);
				number = countLetter(letter);
				printf("There are %d occurrences of %c.\n", number, letter);
				break;

			case 9:
				return 1;
				break;

			default:
				printf("Error, try a different command.\n");
				break;

			return 0;
		}
	}
}

void request()
{
	int i;
	char inputpets[5], inputname[20], inputphone[10];

	if (counter == 5)
	{
		printf("No more appointments available today. Come back tomorrow.\n");
	}
	else
	{
		printf("Enter your name:\n");
		scanf("%s", inputname);
		{
			if (strcmp(name[i], inputname) == 0)
			{
				printf("Name already exists, try another.\n");
			}
			else
			{
				printf("Enter number of pets:\n");
				scanf("%s", inputpets);
				{
					printf("Enter your phone number:\n");
					scanf("%s", inputphone);
					{
						for (i=0; i<5; i++)
						{
							if (schedule[i] == 0)
							{
								if (name[i][0] == '\0' && pets[i][0] == '\0' && phone[i][0] == '\0')
								{
									strcpy (name[i], inputname);
									strcpy (pets[i], inputpets);
									strcpy (phone[i], inputphone);
									schedule[i] = 1;
									counter++;
									printf("An appointment has been scheduled for %s at %d pm.\n", inputname, i+1);
									break;
								}
							}
						}
					}
				}	
			}
		}
	}
	return;
}

void cancel()
{
	int i, hasAppointment = 0;
	char inputname[20];

	if (counter == 0)
	{
		printf("The schedule is completely free.\n");
	}
	else
	{
		printf("Enter your name to cancel your appointment:\n");
		hasAppointment = 0;
		scanf("%s", inputname);
		{
			for (i=0; i<5; i++)
			{
				if (strcmp(name[i], inputname) == 0)
				{
					counter--;
					printf("Your appointment under %s at %d pm is canceled.\n", inputname, i+1);
					hasAppointment = 1;
				}
				if (hasAppointment == 1)
				{
					if (i < counter && name[i+1][0] != '\0' && pets[i+1][0] != '\0'  && phone[i+1][0] != '\0')
					{
						strcpy (name[i], name[i+1]);
						strcpy (pets[i], pets[i+1]);
						strcpy (phone[i], phone[i+1]);
						printf("%s's (%s) appointment has been moved up to %d pm.\n", name[i], phone[i], i+1);
					}
					else
					{
						name[i][0] = '\0';
						pets[i][0] = '\0';
						phone[i][0] = '\0';
						schedule[i] = 0;
					}
				}
			}
			if (hasAppointment == 0)
			{
				printf("Not found.\n");
			}
		}
	}
	return;
}

void list()
{
	int i;

	if (counter == 0)
	{
		printf("The schedule is completely free.\n");
	}
	else
	{
		printf("Time	Name    Phone    Pets\n");
		printf("------------------------------\n");
		{
			for (i=0; i<5; i++)
			{
				if (schedule[i] == 0)
				{
					printf("%d pm    free\n", i+1);
				}
				else if (schedule[i] == 1)
				{
					printf("%d pm    %s     %s      %s\n", i+1, name[i], phone[i], pets[i]);
				}
			}
		}
	}
	return;
}

void show_firstInitial()
{
	int i, hasInitial = 0;
	char initial;

	if (counter == 0)
	{
		printf("The schedule is completely free.\n");
	}
	else
	{
		printf("Enter the first letter of a name you'd like to search for:\n");
		hasInitial = 0;
		scanf(" %c", &initial);
		{
			for (i=0; name[i][0] != '\0'; i++)
			{
				if (initial == name[i][0])
				{
					hasInitial = 1;
					printf("%s - %d pm\n", name[i], i+1);
				}
			}
			if (hasInitial != 1)
			{
				printf("Not found.\n");
			}
		}
	}
	return;
}

void show_pets()
{
	int i, hasPets = 0;
	char petAmount;

	if (counter == 0)
	{
		printf("The schedule is completely free.\n");
	}
	else
	{
		printf("Enter the number of pets you'd like to search for:\n");
		hasPets = 0;
		scanf(" %c", &petAmount);
		{
			for (i=0; pets[i][0] != '\0'; i++)
			{
				if (petAmount == pets[i][0])
				{
					hasPets = 1;
					printf("%s - %d pm\n", name[i], i+1);
				}
			}
			if (hasPets != 1)
			{
				printf("Not found.\n");
			}
		}
	}
	return;
}

void priority()
{
	int i;
	char inputpets[5], inputname[20], inputphone[10];

	printf("Enter your name:\n");
	scanf("%s", inputname);
	{
		printf("Enter number of pets:\n");
		scanf("%s", inputpets);
		{
			printf("Enter your phone number:\n");
			scanf("%s", inputphone);
			{
				if (counter > 0)
				{
					if (name[4][0]!='\0')
					{
						printf("%s's (%s) appointment has been canceled.\n", name[4], phone[4]);
					}
					for (i=4; i >0; i--)
					{
						if (name[i][0]!= '\0')
						{
							strcpy (name[i], name[i-1]);
							strcpy (pets[i], pets[i-1]);
							strcpy (phone[i], phone[i-1]);
							printf("%s's (%s) appointment has been moved from %d pm to %d pm.\n", name[i-1], phone[i-1], i, i+1);
						}
					}
				}
				strcpy(name[0], inputname);
				strcpy(pets[0], inputpets);
				strcpy(phone[0], inputphone);
				printf("An appointment has been scheduled for %s at 1 pm.\n", inputname);
				counter++;
			}
		}
	}
	return;
}

int countLetter(char letter)
{
	int i, number = 0;
	char *str;

	for (i=0; i<counter; i++)
	{
		str = name[i];
		while (*str != '\0')
		{
			if (*str == letter)
			{
				number++;
			}
			str++;
		}
	}
	return number;
}
