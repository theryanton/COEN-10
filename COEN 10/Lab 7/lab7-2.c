/* Ryan Ton
 * COEN 10
 * Lab 7
 * Tuesday 2:15pm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i;
	int userinput;
	int sessions = 5;
	int counter = 0;
	int schedule[5] = {0, 0, 0, 0, 0};
	char name[5][20] = {'\0','\0','\0','\0','\0'};
	char searchname[20];
	char initial;
	int hasAppointment = 0; // Flag determines whether the name inputted has a scheduled appointment or not //
	int hasInitial = 0; // Flag determines if initial inputted by user is in any of the names //

	while (1)
	{
		printf("Welcome to the StinkyPetSpa Inc. Scheduling System!\n");
		printf("\n");
		printf("Input 1 to make an appointment.\n");
		printf("Input 2 to cancel an appointment.\n");
		printf("Input 3 to list the full schedule.\n");
		printf("Input 4 to show names starting with a letter.\n");
		printf("Input 9 to exit the program.\n");
		printf("Please enter a command:\n");
		scanf("%d", &userinput);

		switch (userinput)
		{
			case 1:
			{
				if (counter == 5)
				{
					printf("No more appointments available today. Come back tomorrow.\n");
				}
				else
				{
					printf("Enter your name:\n");
					scanf("%s", searchname);
					{
						for (i=0; i<sessions; i++)
						{
							if (schedule[i] == 0)
								{
									if (name[i][0] == '\0')
									{
										strcpy (name[i], searchname);
										schedule[i] = 1;
										counter++;
										printf("An appointment has been scheduled for %s at %d pm.\n", searchname, i+1);
										break;
									}
								}
						}
					}
				}
			}
			break;

			case 2:
			{
				if (counter == 0)
				{
					printf("The schedule is completely free.\n");
					break;
				}
				else
				{
					printf("Enter your name to cancel your appointment:\n");
					hasAppointment = 0;
					scanf("%s", searchname);
					{
						for (i=0; i<sessions; i++)
						{
							if (strcmp(name[i], searchname) == 0)
							{
								counter--;
								printf("Your appointment under %s at %d pm is canceled.\n", searchname, i+1);
								hasAppointment = 1;
							}
							if (hasAppointment == 1)
							{
								if (i < counter && name[i+1][0] != '\0')
								{
									strcpy (name[i], name[i+1]);
								}
								else
								{
									name[i][0] = '\0';
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
			}
			break;

			case 3:
			{
				if (counter == 0)
				{
					printf("The schedule is completely free.\n");
					break;
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
							printf("%d pm - %s\n", i+1, name[i]);
						}
					}
				}
			}
			break;

			case 4:
			{
				if (counter == 0)
				{
					printf("The schedule is completely free.\n");
					break;
				}
				else
				{
					printf("Input the first letter of your name:\n");
					hasInitial = 0;
					scanf(" %c", &initial);
					{
						for (i=0; i<sessions; i++)
						{
							if (initial == name[i][0])
							{
								hasInitial = 1;
							}
							if (hasInitial == 1)
							{
								printf("%s\n", name[i]);
							}
						}
						if (hasInitial != 1)
						{
							printf("Not found.\n");
						}
					}
				}
			}
			break;

			case 9:
			{
				return 1;
			}
			break;

			default:
			{
				printf("That command does not exist.\n");
			}
			break;
		}
	}
return 0;
}
