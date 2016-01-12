template <class T>
class StackUsingArray {
private:
	int capacity;
	int top_index;
	T *data;
public:
	StackUsingArray(int _capacity);
	bool push(T element);
	bool pop();
	bool empty();
	T top();
};