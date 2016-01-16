#define _CRT_SECURE_NO_WARNINGS
#include "DataStructAndAlgorithm.h"
#include "SeparateChainingHashTable.h"
#include <string>
using namespace std;


int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int n;
	cin >> n;
	SeparateChainingHashTable hashtable(n);
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		hashtable.insert(temp);
	}
	hashtable.output();
	return 0;
}