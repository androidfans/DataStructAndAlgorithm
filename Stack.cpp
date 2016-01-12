#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class Stack {
private:
	int capacity;
	int top;
	T *data;
public:
	Stack(int _capacity) : top(-1),capacity(_capacity) {
		data = new T[_capacity];
	}
	bool push(T element) {
		if (top >= capacity - 1) {
			return false;
		}
		top++;
		data[top] = element;
		return true;
	}

	T top() {
		assert(top > -1);
		return data[top];
	}

	bool pop() {
		if (top < 0) {
			return false;
		}
		top--;
		return true;
	}
};

int main() {
	Stack<int> stack(200);





	return 0;
}