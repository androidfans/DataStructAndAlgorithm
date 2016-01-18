#define _CRT_SECURE_NO_WARNINGS
#include "DataStructAndAlgorithm.h"
#include "DisjointSet.h"
#include <string>
using namespace std;


int main() {
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	DisjointSet dsu(100);
	int m, x, y;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		bool ans = dsu.merge(x, y);
		if (ans) {
			cout << "success" << endl;
		}
		else {
			cout << "failed" << endl;
		}
	}
	return 0;
}