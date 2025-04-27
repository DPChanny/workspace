#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int day_count;
	int room_count;
	char** room_status;
	int arrival_day;
	int departure_day;

	//입력
	scanf("%d %d", &day_count, &room_count);
	room_status = (char**)malloc(sizeof(char*) * day_count);
	for (int i = 0; i < day_count; i++)
	{
		room_status[i] = (char*)malloc(sizeof(char) * room_count);
		for (int j = 0; j < room_count; j++)
		{
			scanf(" %c", &room_status[i][j]);
		}
	}

	scanf(" %d %d", &arrival_day, &departure_day);

	arrival_day--;
	departure_day--;

	//처리
	int count = 0;
	int cur_day = arrival_day;

	while (cur_day != departure_day) {
		int max_room = -1;
		for (int i = 0; i < room_count; i++)
		{
			if (room_status[cur_day][i] == 'O') {
				int room = 0;
				for (int j = cur_day; j < departure_day; j++)
				{
					if (room_status[j][i] == 'O') {
						room++;
					}
					else {
						break;
					}
				}
				if (max_room < room) {
					max_room = room;
				}
			}
 		}
		if (max_room == -1) {
			printf("-1");
			return;
		}
		cur_day += max_room;
		count++;
	}

	//출력
	printf("%d", count - 1);
}