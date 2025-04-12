#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define USED -1

int main(void) {
	int dough_price;
	int dough_calorie;

	int topping_count;
	int topping_price;
	int* topping_calories;

	scanf("%d", &topping_count);
	scanf(" %d %d", &dough_price, &topping_price);
	scanf(" %d", &dough_calorie);

	topping_calories = (int*)malloc(sizeof(int) * topping_count);
	for (int i = 0; i < topping_count; i++)
	{
		scanf(" %d", &topping_calories[i]);
	}

	int cur_calorie = dough_calorie;
	int cur_price = dough_price;
	int cur_ratio = cur_calorie / cur_price;
	int cur_max_ratio = cur_ratio;
	for (int i = 0; i < topping_count; i++)
	{
		int max_id = 0;
		for (int j = 0; j < topping_count; j++)
		{
			if (topping_calories[j] != USED) {
				if (topping_calories[j] > topping_calories[max_id]) {
					max_id = j;
				}
			}
		}
		
		cur_calorie += topping_calories[max_id];
		cur_price += topping_price;
		cur_ratio = (float)cur_calorie / (float)cur_price;
		topping_calories[max_id] = USED;
		if(cur_max_ratio > cur_ratio){
			break;
		}
		cur_max_ratio = cur_ratio;
	}

	printf("%d", cur_max_ratio);
}