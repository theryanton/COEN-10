/* Ryan Ton
 * COEN 10
 * Lab 6
 * Tuesday 2:15pm
 */

#include <stdio.h>
int main()
{
	int i;
	int schedule[5] = {0,0,0,0,0};
	int userinput;
	int sessions = 5;
	int time;
	int counter1 = 0;
	int counter2 = 0;

	while(1)
	{
		printf("Welcome to the StinkyPetSpa Inc. Scheduling System!\n");
		printf("\n");
		printf("Input 1 if you'd like to make an appointment.\n");
		printf("Input 2 if you'd like to cancel an appointment.\n");
		printf("Input 3 if you'd like to list the schedule.\n");
		printf("Input 9 if you'd like to exit the program.\n");
		printf("Please enter a command:\n");
		scanf("%d", &userinput);

		if (userinput == 1)
		{
			for (i=0; i<sessions; i++)
			{
				if (schedule[i] == 0)
				{
					schedule[i] = 1;
					counter1++;
					printf("An appointment has been scheduled for you at %d pm.\n", i+1);
					break;
				}
			}
			if (counter1 == 5)
			{
				printf("No more appointments available today. Come back tomorrow.\n");
			}
		}

		else if (userinput == 2)
		{
			if (counter1 == 0)
			{
				printf("The schedule is completely free.\n");
			}
			else
			{
				printf("What appointment would you like to cancel?\n");
				scanf("%d", &time);
				{
					for (i=0; i<sessions; i++)
					{
						if (schedule[i] == 0)
						{
							counter2++;
						}
					}
					if (schedule[time-1] == 1)
					{
						schedule[time-1] = 0;
						counter2--;
						counter1--;
						printf("Your appointment at %d pm is cancelled.\n", time);
					}
					else if (schedule[time-1] == 0)
					{
						printf("%d pm is currently free.\n", time);
					}	
				}
			}
		}

		else if (userinput == 3)
		{
			if (counter1 == 0)
			{
				printf("The schedule is completely free.\n");
			}
			else
			{
				for (i=0; i<sessions; i++)
				{
					if (schedule[i] == 0)
					{
						printf("%d pm - free\n", i+1);
					}
					else if (schedule[i] == 1)
					{
						printf("%d pm - busy\n", i+1);
					}
				}
			}
		}

		else if (userinput == 9)
		{
			return 1;
		}

		else
		{
			printf("Bad choice!\n");
		}
	}
return 0;
}
