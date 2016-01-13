#include "DataStructAndAlgorithm.h"
#include "OpenAdressingHashTable.h"

int main() {
	OpenAdressingHashTable hashtable(3);
	int buffer;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> buffer;
		int ans = hashtable.insert(buffer);
		if (ans == 0) {
			cout << "insert failed!" << endl;
		}
		else if (ans == 1) {
			cout << "insert success!" << endl;
		}
		else if (ans == 2) {
			cout << "It already exists!" << endl;
		}
	}
	int temp_pos, temp_times;
	for (int i = 0; i < 100; i++) {
		cin >> buffer;
		if (hashtable.search(buffer, temp_pos, temp_times)) {
			cout << "search success!" << endl;
		}
		else {
			cout << "search failed!" << endl;
		}
	}
	system("pause");
	return 0;
}