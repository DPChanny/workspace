#include<stdio.h>
#include<stdlib.h>

typedef struct Person
{
	int weight;
	int height;
} Person;

int main(void)
{
	int people_count = 0;

	scanf("%d", &people_count);

	Person* people = (Person*) malloc(sizeof(Person) * people_count);

	for (int i = 0; i < people_count; i++)
	{
		scanf("%d %d", &people[i].weight, &people[i].height);
	}

	for (int i = 0; i < people_count; i++)
	{
		int cur_rank = 1;

		for (int j = 0; j < people_count; j++)
		{
			if (j == i)
			{
				continue;
			}

			if (people[i].weight < people[j].weight && people[i].height < people[j].height)
			{
				cur_rank++;
			}
		}

		printf("%d ", cur_rank);
	}

	return 0;
}
