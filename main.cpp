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
  string result;
  int burst_time;
  int arrival_time;
  int io_amount;
  int memory_amount;

  float get_priority() const {
    float priority = 0.0f;
    priority += (100.0f / (burst_time + 1)) * 2.0f;
    priority += (100.0f / (arrival_time + 1)) * 1.5f;
    priority += (io_amount * 0.5f);
    priority += (memory_amount / 1024.0f) * 0.3f;
    return priority;
  }

  bool operator<(const job& other) const {
    return get_priority() < other.get_priority();
  }

  bool operator>(const job& other) const {
    return get_priority() > other.get_priority();
  }
};

void print_job(const job& j) {
  cout << fixed << setprecision(2);
  cout << "Result: " << j.result << endl;
  cout << "Burst Time: " << j.burst_time << "ms" << endl;
  cout << "Arrival Time: " << j.arrival_time << "ms" << endl;
  cout << "I/O Operations: " << j.io_amount << endl;
  cout << "Memory: " << j.memory_amount << "KB" << endl;
  cout << "Calculated Priority: " << j.get_priority() << endl;
  cout << "----------------------------------------" << endl;
}

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
              {"Log Writer", 10, 4, 22, 512}

  };

  for (const auto& j : js) {
    scheduler.push(j);
  }

  int count = 1;
  while (!scheduler.empty()) {
    cout << "Executing Job #" << count++ << ":" << endl;
    job current = scheduler.pop();
    print_job(current);
    cout << endl;
  }

  cout << "=== All Jobs Completed ===" << endl;

  return 0;
}
