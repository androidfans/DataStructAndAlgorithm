#include "DataStructAndAlgorithm.h"
#include "StackUsingArray.h"
#define MAX 1000

bool precede(char a, char b) {
	if (a == '*') {
		return true;
	}
	else {
		return false;
	}
}

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


int valuesOfExpressions() {
	string buffer;
	cin >> buffer;
	StackUsingArray<int> numbers(MAX);
	StackUsingArray<char> operators(MAX);
	int i = 0;
	while (i < buffer.length()) {
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
	return numbers.top();
}

int main() {
	cout << valuesOfExpressions();
	system("pause");
	return 0;
}