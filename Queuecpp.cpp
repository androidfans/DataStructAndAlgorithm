#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class Queue {
private:
	int head, tail,count,capacity;
	T* data;
public:
	Queue(int queue_size) : head(0),tail(-1),count(0) {
		data = new T[queue_size];
		capacity = queue_size;
	}
	~Queue() {
		delete[] data;
	}
	T front() {
		assert(count > 0);
		return data[head];
	}

	bool push(T element) {
		if (count < capacity) {
			tail = (tail + 1) % capacity;
			data[tail] = element;
			count++;
			return true;
		}
		else{
			return false;
		}
	}

	void pop() {
		assert(count > 0);
		head = (head + 1) % capacity;
		count--;
	}
	
	void output() {
		for (int i = head; i != tail + 1; i = (i + 1) % capacity) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
};



int main() {
	Queue<int> queue(100);
	for (int i = 1; i <= 10; i++) {
		queue.push(i);
	}
	queue.output();
	cout << queue.front() << endl;
	queue.pop();
	queue.output();
	system("pause");
	return 0;
}