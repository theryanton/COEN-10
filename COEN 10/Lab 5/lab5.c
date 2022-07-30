/* Ryan
 * COEN 10
 * Lab 5
 * Tuesday 2:15pm
 */

#include <stdio.h>

int main()
{
	srand((int)time(NULL));
	int rand1;
	int rand2;
	int input;
	int answer;
	int score = 0;
	int i;

	for (i=0; i<10; i++)
	{
		rand1 = rand()%13;
		rand2 = rand()%13;
		printf("%d x %d = ?\n", rand1, rand2);
		scanf("%d", &input);
		{
			answer = rand1 * rand2;
			if (input == answer)
			{
				score++;
			}
		}
	}

	printf("Your final score is %d. Try again?\n", score);
	return 0;
}
