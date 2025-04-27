#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <string>

#define DEBUG

using namespace std;

typedef struct Code {
	int value; //코드 값
	int order; //입력 순서
	vector<Code*> codes; //이동 가능 코드
	bool visit;
	Code* before;
} Code;

bool compare(Code* a, Code* b) {
	return a->value < b->value;
}

int main(void) {
	//코드 개수, 코드 길이
	int n, k;
	cin >> n >> k;

	//코드 십진수 변환 입력
	Code** codes = new Code * [n];
	for (int _n = 0; _n < n; _n++)
	{
		Code* code = new Code;

		getchar();
		int value = 0;
		for (int l = 0; l < k; l++) {
			value = value << 1;
			value += getchar() - '0';
		}
		code->value = value;
		code->order = _n;
		code->visit = false;
		code->before = NULL;
		codes[_n] = code;
	}

	int buf1, buf2;
	cin >> buf1 >> buf2;
	buf1--;
	buf2--;
	Code* start_code = codes[buf1];
	Code* end_code = codes[buf2];

	queue<Code*> queue;
	start_code->visit = true;
	queue.push(start_code);

	//코드 오름차순 정렬
	sort(codes, codes + n, compare);

#ifdef DEBUG
	for (int _n = 0; _n < n; _n++)
	{
		cout << "order: " << codes[_n]->order << endl;
		cout << "value: " << codes[_n]->value << endl;
	}
#endif

	for (int _n = 0; _n < n; _n++)
	{
		//중복 이동 가능 코드 제거를 위한 temp
		int temp = codes[_n]->value;
		for (int _k = 0; _k < k; _k++)
		{
			//_k번째 비트가 1 이면 연산
			if (temp & 1) {
				//현재 코드에서 _k 번째 비트를 0으로 바꿈
				int target = codes[_n]->value - (1 << _k);
				//이분탐색으로 target 코드 탐색
				int _start = 0;
				int _end = _n - 1;
				while (_start != _end)
				{
					int middle = (_start + _end) / 2;

					if (codes[middle]->value >= target) {
						_end = middle;
					}
					else {
						_start = middle + 1;
					}
				}
				if (codes[_start]->value == target) {
					codes[_n]->codes.push_back(codes[_start]);
					codes[_start]->codes.push_back(codes[_n]);
				}
			}
			temp = temp >> 1;
		}
	}

#ifdef DEBUG
	cout << endl;
	for (int _n = 0; _n < n; _n++)
	{
		cout << "order: " << codes[_n]->order << endl;
		for (int i = 0; i < codes[_n]->codes.size(); i++)
		{
			cout << "connection: " << codes[_n]->codes[i]->order << endl;
		}
	}
#endif

	//BFS로 before 포인터 연결 및 visit 업데이트
	while (queue.size()) {
		Code* code = queue.front();
		queue.pop();

#ifdef DEBUG
		cout << endl;
		cout << "order: " << code->order << endl;
		cout << "value: " << code->value << endl;
#endif

		for (int i = 0; i < code->codes.size(); i++)
		{
#ifdef DEBUG
			cout << "push connection: " << code->codes[i]->order << endl;
#endif
			if (!code->codes[i]->visit) {
				code->codes[i]->before = code;
				code->codes[i]->visit = true;
				queue.push(code->codes[i]);
			}
		}
	}

	if (end_code->visit) {
		string out = "";
		Code* code = end_code;
#ifdef DEBUG
		cout << endl;
		cout << "order: " << code->order << endl;
#endif
		while (code->before != NULL) {
			out = to_string(code->order + 1) + " " + out;
#ifdef DEBUG
			cout << "before connection: " << code->before->order << endl;
			cout << "out: " << out << endl;
#endif
			code = code->before;
		}
		cout << start_code->order + 1 << " " << out;
	}
	else {
		cout << "-1";
	}

	for (int _n = 0; _n < n; _n++)
	{
		delete codes[_n];
	}
	delete[] codes;
}