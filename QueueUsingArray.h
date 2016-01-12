#pragma once
template<typename T>
class QueueUsingArray {
private:
	int head, tail, count, capacity;
	T* data;
public:
	QueueUsingArray(int queue_size);
	~QueueUsingArray();
	T front();

	bool push(T element);

	void pop();

	void output();
};