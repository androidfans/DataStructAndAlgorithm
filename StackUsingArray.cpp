#include "DataStructAndAlgorithm.h"
#include "StackUsingArray.h"
using namespace std;

template <class T>
StackUsingArray<T>::StackUsingArray(int _capacity) : top_index(-1), capacity(_capacity) {
	data = new T[_capacity];
}

template <class T>
bool StackUsingArray<T>::push(T element) {
	if (top_index >= capacity - 1) {
		return false;
	}
	top_index++;
	data[top_index] = element;
	return true;
}

template <class T>
T StackUsingArray<T>::top() {
	assert(top_index > -1);
	return data[top_index];
}

template <class T>
bool StackUsingArray<T>::pop() {
	if (top_index < 0) {
		return false;
	}
	top_index--;
	return true;
}

template <class	T>
bool StackUsingArray<T>::empty() {
	if (top_index < 0) {
		return true;
	}
	return false;
}