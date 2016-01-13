template <class T>
class StackUsingArray {
private:
	int capacity;
	int top_index;
	T *data;
public:
	StackUsingArray(int _capacity);
	~StackUsingArray();
	bool push(T element);
	bool pop();
	bool empty();
	T top();
};

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

template <class T>
StackUsingArray<T>::~StackUsingArray() {
	delete[] data;
}