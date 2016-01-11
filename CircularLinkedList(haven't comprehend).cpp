#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next = NULL;
	Node(int _data) {
		data = _data;
	}
};

class LinkList {
public:
	Node* find(int index) {
		if (head == NULL) {
			return NULL;
		}
		Node *current_node = head->next;
		int count = 0;
		while (current_node != head&&count != index) {
			current_node = current_node->next;
			count++;
		}
		if (count == index) {
			return current_node;
		}
		return NULL;
	}

	void insert(Node *node, int index) {
		if (head == NULL) {
			head = node;
			head->next = head;
			return;
		}
		if (index == 0) {
			node->next = head->next;
			head->next = node;
			return;
		}
		Node *pre_node = find(index - 1);
		if (pre_node != NULL) {
			node->next = pre_node->next;
			pre_node->next = node;
		}
		if (node == head->next) {
			head = node;
		}
	}

	void remove(int index) {
		if (head == NULL) {
			return;
		}
		Node *delete_node = NULL;
		if (index == 0) {
			delete_node = head->next;
			head->next = delete_node->next;
			delete delete_node;
			return;
		}
		Node *pre_node = find(index - 1);
		if (!pre_node) {
			return;
		}
		if (pre_node == head) {
			return;
		}
		delete_node = pre_node->next;
		pre_node->next = delete_node->next;
		if (delete_node == head) {
			head = pre_node;
		}
		delete delete_node;
	}

	void reverse() {
		if (head == NULL) {
			return;
		}
		Node *current_node = head->next;
		Node *next_node = NULL;
		Node *origin_head = head;
		Node *origin_next = head->next;
		do {
			next_node = current_node->next;
			current_node->next = head;
			head = current_node;
			current_node = next_node;
		} while (head != origin_head);
		head = origin_next;
	}

	void output() {
		if (head == NULL) {
			cout << "Linked List is NULL" << endl;
		}
		Node *current_node = head->next;
		do {
			cout << current_node->data << " ";
			current_node = current_node->next;
		} while (current_node != head->next);
		cout << endl;
	}
private:
	Node *head = NULL;
};

//int	main() {
//	LinkList linklist;
//	for (int i = 0; i < 10; i++)
//	{
//		Node *node = new Node(i);
//		linklist.insert(node, i);
//	}
//	linklist.output();
//	linklist.reverse();
//	linklist.output();
//	linklist.remove(0);
//	linklist.output();
//	linklist.remove(1);
//	linklist.output();
//	system("pause");
//	return 0;
//}