#include<stdio.h>
#include<queue> 
//cpp only for queue

int main(void) {
	unsigned long long n;
	std::queue<unsigned long long> queue;

	if (scanf("%llu", &n)) {
		unsigned long long num = 0;
		queue.push(1);
		while (queue.size()) {
			unsigned long long cur = queue.front();
			queue.pop();
			if (!(cur % n)) {
				num = cur;
				break;
			}
			if (cur >= 10000000000000000000) continue;
			queue.push(cur * 10);
			queue.push((cur * 10) + 1);
		}
		printf("%llu", num);
	}

	return 0;
}
