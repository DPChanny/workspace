#include<stdio.h>
#include<stdlib.h>

#define WRONG_DWARF_COUNT 9
#define DWARF_COUNT 7
#define DWARF_SUM 100

int main(void)
{
	int dwarfs[WRONG_DWARF_COUNT] = {0, };

	for (int i = 0; i < WRONG_DWARF_COUNT; i++)
	{
		scanf("%d", &dwarfs[i]);
	}

	for (int i = 0; i < WRONG_DWARF_COUNT; i++)
	{
		for (int j = i + 1; j < WRONG_DWARF_COUNT; j++)
		{
			int sum = 0;

			int dwarfs_contained[DWARF_COUNT] = { 0, };

			int excepted_count = 0;

			for (int k = 0; k < WRONG_DWARF_COUNT; k++)
			{
				if (k != i && k != j)
				{
					sum += dwarfs[k];
					dwarfs_contained[k - excepted_count] = dwarfs[k];
				}
				else
				{
					excepted_count++;
				}
			}

			if (sum == DWARF_SUM)
			{
				int min_id;
				int min_val;
				for (int i = 0; i < DWARF_COUNT; i++)
				{
					min_id = i;
					min_val = dwarfs_contained[min_id];
					for (int j = i + 1; j < DWARF_COUNT; j++)
					{
						if (dwarfs_contained[j] < min_val)
						{
							min_id = j;
							min_val = dwarfs_contained[min_id];
						}
					}
					dwarfs_contained[min_id] = dwarfs_contained[i];
					dwarfs_contained[i] = min_val;
				}

				for (int i = 0; i < DWARF_COUNT; i++)
				{
					printf("%d\n", dwarfs_contained[i]);
				}

				return 0;
			}
		}
	}

	return 1;
}