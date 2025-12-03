#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class max_heap {
 private:
  vector<T> heap;

  int parent(int i) { return (i - 1) / 2; }

  int left(int i) { return 2 * i + 1; }

  int right(int i) { return 2 * i + 2; }

  // 삽입 후 힙 속성 유지
  void heapify_up(int i) {
    while (i > 0 && heap[parent(i)] < heap[i]) {  // 부모보다 크면
      swap(heap[i], heap[parent(i)]);             // 교환
      i = parent(i);                              // 부모 위치로 이동
    }
  }

  // 삭제 후 힙 속성 유지
  void heapify_down(int i) {
    int maxIdx = i;
    int l = left(i);
    int r = right(i);

    if (l < heap.size() && heap[maxIdx] < heap[l]) {  // 왼쪽 자식이 더 크면
      maxIdx = l;
    }
    if (r < heap.size() && heap[maxIdx] < heap[r]) {  // 오른쪽 자식이 더 크면
      maxIdx = r;
    }

    if (i != maxIdx) {              // 최대값이 자식이면
      swap(heap[i], heap[maxIdx]);  // 교환
      heapify_down(maxIdx);         // 재귀적으로 힙 속성 유지
    }
  }

 public:
  void push(T value) {
    heap.push_back(value);
    heapify_up(heap.size() - 1);
  }

  T pop() {
    if (heap.empty()) {
      throw runtime_error("Heap is empty");
    }

    T maxValue = heap[0];   // 최대값 저장
    heap[0] = heap.back();  // 마지막 요소를 루트로 이동
    heap.pop_back();        // 마지막 요소 제거

    if (!heap.empty()) {  // 힙이 비어있지 않으면
      heapify_down(0);    // 힙 속성 복구
    }

    return maxValue;
  }

  bool empty() { return heap.empty(); }
};

struct job {
  string name;        // 작업 이름
  int burst_time;     // 실행 시간
  int arrival_time;   // 도착 시간
  int io_amount;      // I/O 양
  int memory_amount;  // 메모리 사용량

  float get_priority() const {
    float priority = 0.0f;
    priority +=
        (100.f / (burst_time + 1)) * 2.f;  // 실행 시간 짧을수록 높은 점수
    priority +=
        (100.f / (arrival_time + 1)) * 1.5f;     // 도착 시간 빠를수록 높은 점수
    priority += (io_amount * .5f);               // I/O 양이 많을수록 높은 점수
    priority += (memory_amount / 1024.f) * .3f;  // 메모리 사용량에 비례
    return priority;
  }

  bool operator<(const job& other) const {
    return get_priority() < other.get_priority();
  }

  bool operator>(const job& other) const {
    return get_priority() > other.get_priority();
  }

  void print() const {
    cout << fixed << setprecision(2);  // 소수점 둘째 자리까지 출력
    cout << name << endl;
    cout << "Burst Time: " << burst_time << "ms" << endl;
    cout << "Arrival Time: " << arrival_time << "ms" << endl;
    cout << "I/O Amount: " << io_amount << endl;
    cout << "Memory Amount: " << memory_amount << "KB" << endl;
    cout << "Priority: " << get_priority() << endl;
  }
};

int main() {
  max_heap<job> scheduler;
  job js[] = {{"Database Query Process", 5, 0, 15, 2048},
              {"Video Encoding Task", 50, 2, 3, 8192},
              {"Web Server Request", 2, 1, 25, 512},
              {"File Compression", 20, 5, 8, 4096},
              {"System Backup", 100, 10, 5, 16384},
              {"User Input Handler", 1, 0, 30, 256},
              {"Network Sync", 8, 3, 20, 1024},
              {"Audio Processing", 15, 7, 12, 3072},
              {"Cache Update", 3, 1, 18, 768},
              {"Log Writer", 10, 4, 22, 512}};

  int totalJobs = sizeof(js) / sizeof(js[0]);
  int jobIndex = 0;
  int processedCount = 0;

  // 초기에 3개 작업 추가
  for (int i = 0; i < 3 && i < totalJobs; i++) {
    cout << "[PUSH]" << endl;
    js[jobIndex].print();
    cout << endl;

    scheduler.push(js[jobIndex++]);
  }

  // pop과 push를 반복
  while (processedCount < totalJobs) {
    // 1개씩 pop
    if (!scheduler.empty()) {
      job current = scheduler.pop();

      cout << "[POP] Processing job #" << (processedCount++ + 1) << endl;
      current.print();
      cout << endl;
    }

    // 2개씩 push
    for (int i = 0; i < 2 && jobIndex < totalJobs; i++) {
      cout << "[PUSH]" << endl;
      js[jobIndex].print();
      cout << endl;

      scheduler.push(js[jobIndex++]);
    }
  }
}
