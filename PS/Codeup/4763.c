#include<stdio.h>
#include<stdlib.h>

typedef struct Monkey {
	int cage;
	int enemy_monkey_count;
	struct Monkey* enemy_monkies[3];
} Monkey;

int main(void) {
	int monkey_count;
	Monkey* monkies;

	scanf("%d", &monkey_count);
	monkies = (Monkey*)malloc(sizeof(Monkey) * (monkey_count + 1));

	for (int i = 1; i <= monkey_count; i++)
	{
		monkies[i].cage = 1;
		scanf(" %d", &monkies[i].enemy_monkey_count);
		for (int j = 0; j < monkies[i].enemy_monkey_count; j++)
		{
			int buf;
			scanf(" %d", &buf);
			monkies[i].enemy_monkies[j] = &monkies[buf];
		}
	}

	int is_all = 1;
	int i = 1;
	int is_moved = 0;
	while (i <= monkey_count)
	{
		int enemy_count = 0;
		for (int j = 0; j < monkies[i].enemy_monkey_count; j++)
		{
			if(monkies[i].cage == monkies[i].enemy_monkies[j]->cage)
			{
				enemy_count++;
			}
		}
		if(enemy_count > 1) {
			monkies[i].cage = !monkies[i].cage;
			is_all = 0;
			is_moved = 1;
		}
		i++;
		if (i > monkey_count) {
			if (is_moved) {
				is_moved = 0;
				i = 1;
			}
		}
	}

	for (int i = 1; i <= monkey_count - is_all; i++)
	{
		if (monkies[i].cage) {
			printf("%d ", i);
		}
	}
	printf("\n");
	for (int i = 1; i <= monkey_count; i++)
	{
		if (!monkies[i].cage) {
			printf("%d ", i);
		}
	}
	if (is_all) {
		printf("%d", monkey_count);
	}
}