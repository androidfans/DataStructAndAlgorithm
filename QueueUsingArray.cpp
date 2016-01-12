#include "DataStructAndAlgorithm.h"
#include "QueueUsingArray.h"
using namespace std;


template<typename T>
QueueUsingArray<T>::QueueUsingArray(int queue_size) : head(0),tail(-1),count(0) {
	data = new T[queue_size];
	capacity = queue_size;
}

template<typename T>
QueueUsingArray<T>::~QueueUsingArray() {
	delete[] data;
}

template<typename T>
T QueueUsingArray<T>::front() {
	assert(count > 0);
	return data[head];
}

template<typename T>
bool QueueUsingArray<T>::push(T element) {
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

template<typename T>
void QueueUsingArray<T>::pop() {
	assert(count > 0);
	head = (head + 1) % capacity;
	count--;
}

template<typename T>
void QueueUsingArray<T>::output() {
	for (int i = head; i != tail + 1; i = (i + 1) % capacity) {
		cout << data[i] << " ";
	}
	cout << endl;
}



//int main() {
//	QueueUsingArray<int> queue(100);
//	for (int i = 1; i <= 10; i++) {
//		queue.push(i);
//	}
//	queue.output();
//	cout << queue.front() << endl;
//	queue.pop();
//	queue.output();
//	
//	system("pause");
//	return 0;
//}