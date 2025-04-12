#include<stdio.h>
#include<stdlib.h>

typedef struct HeliportInfo {
	int time;
	int count;
} HeliportInfo;

const HeliportInfo NULL_INFO = { NULL, NULL };
const HeliportInfo MAX_INFO = { 2147483647, 2147483647 };

HeliportInfo* infos;

//헬기가 최대로 갈수있는 거리
int max_distance;
//정류장의 개수
int heliport_count;
//정류장 사이의 거리
int* distances;
//정류장을 경유하는데 걸리는 시간
int* times;

HeliportInfo get_min_time(int _n);

int main(void) {
	//입력
	scanf("%d", &max_distance);
	scanf(" %d", &heliport_count);

	infos = (HeliportInfo*)malloc(sizeof(HeliportInfo) * heliport_count);
	for (int i = 0; i < heliport_count; i++)
	{
		infos[i] = NULL_INFO;
	}

	distances = (int*)malloc(sizeof(int) * (heliport_count + 1));
	for (int i = 0; i < (heliport_count + 1); i++)
	{
		scanf(" %d", &distances[i]);
	}

	times = (int*)malloc(sizeof(int) * (heliport_count));
	for (int i = 0; i < heliport_count; i++)
	{
		scanf(" %d", &times[i]);
	}

	//처리
	int cur_distance = 0;
	HeliportInfo min_info = MAX_INFO;
	for (int i = heliport_count; i >= 0; i--)
	{
		cur_distance += distances[i];
		if (cur_distance > max_distance) {
			break;
		}
		else {
			HeliportInfo info = get_min_time(i - 1);
			if (info.time == min_info.time) {
				if (info.count < min_info.count) {
					min_info = info;
				}
			}
			else if (info.time < min_info.time) {
				min_info = info;
			}
		}
	}

	printf("%d %d", min_info.time, min_info.count);
}

HeliportInfo get_min_time(int _n) {
	if (_n < 0) {
		return NULL_INFO;
	}

	if (infos[_n].time == NULL) {
		int cur_distance = 0;
		HeliportInfo min_info = MAX_INFO;
		for (int i = _n; i >= 0; i--)
		{
			cur_distance += distances[i];
			if (cur_distance > max_distance) {
				break;
			}
			else {
				HeliportInfo info = get_min_time(i - 1);
				if (info.time == min_info.time) {
					if (info.count < min_info.count) {
						min_info = info;
					}
				}
				else if (info.time < min_info.time) {
					min_info = info;
				}
			}
		}

		min_info.count++;
		min_info.time += times[_n];

		infos[_n] = min_info;
	}

	return infos[_n];
}