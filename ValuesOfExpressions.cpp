#include "DataStructAndAlgorithm.h"
#include "StackUsingArray.h"


int operate(char theta, int a, int b) {
	if (theta == '+') {
		return a + b;
	}
	else {
		return a * b;
	}
}
void calc(StackUsingArray<int> &numbers, StackUsingArray<char> &operators) {
	int a = numbers.top();
	numbers.pop();
	int b = numbers.top();
	numbers.pop();
	numbers.push(operate(operators.top(), a, b));
	operators.pop();
}
bool precede(char a, char b) {
	if (a == '*') {
		return true;
	}
	else {
		return false;
	}
}

void valuesOfExpressions() {
	string buffer;
	int n;
	cin >> n;
	StackUsingArray<int> numbers(n);
	StackUsingArray<char> operators(n);
	cin >> buffer;
	int i = 0;
	while (i < n) {
		if (isdigit(buffer[i])) {
			numbers.push(buffer[i] - '0');
			i++;
		}
		else {
			if (operators.empty() || precede(buffer[i], operators.top())) {
				operators.push(buffer[i]);
				i++;
			}
			else {
				calc(numbers, operators);
			}
		}
	}
	while (!operators.empty()) {
		calc(numbers, operators);
	}
	cout << numbers.top() << endl;
}

int main() {
	valuesOfExpressions();
	system("pause");
	return 0;
}