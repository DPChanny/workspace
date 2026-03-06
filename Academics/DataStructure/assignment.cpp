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

  void heapify_up(int i) {
    while (i > 0 && heap[parent(i)] < heap[i]) {
      swap(heap[i], heap[parent(i)]);
      i = parent(i);
    }
  }

  void heapify_down(int i) {
    int maxIdx = i;
    int l = left(i);
    int r = right(i);

    if (l < heap.size() && heap[maxIdx] < heap[l]) {
      maxIdx = l;
    }
    if (r < heap.size() && heap[maxIdx] < heap[r]) {
      maxIdx = r;
    }

    if (i != maxIdx) {
      swap(heap[i], heap[maxIdx]);
      heapify_down(maxIdx);
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

    T maxValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    if (!heap.empty()) {
      heapify_down(0);
    }

    return maxValue;
  }

  bool empty() { return heap.empty(); }
};

struct job {
  string name;
  int burst_time;
  int arrival_time;
  int io_amount;
  int memory_amount;

  float get_priority() const {
    float priority = 0.0f;
    priority +=
        (100.f / (burst_time + 1)) * 2.f;
    priority +=
        (100.f / (arrival_time + 1)) * 1.5f;
    priority += (io_amount * .5f);
    priority += (memory_amount / 1024.f) * .3f;
    return priority;
  }

  bool operator<(const job& other) const {
    return get_priority() < other.get_priority();
  }

  bool operator>(const job& other) const {
    return get_priority() > other.get_priority();
  }

  void print() const {
    cout << fixed << setprecision(2);
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

  for (int i = 0; i < 3 && i < totalJobs; i++) {
    cout << "[PUSH]" << endl;
    js[jobIndex].print();
    cout << endl;

    scheduler.push(js[jobIndex++]);
  }

  while (processedCount < totalJobs) {
    if (!scheduler.empty()) {
      job current = scheduler.pop();

      cout << "[POP] Processing job #" << (processedCount++ + 1) << endl;
      current.print();
      cout << endl;
    }

    for (int i = 0; i < 2 && jobIndex < totalJobs; i++) {
      cout << "[PUSH]" << endl;
      js[jobIndex].print();
      cout << endl;

      scheduler.push(js[jobIndex++]);
    }
  }
}
