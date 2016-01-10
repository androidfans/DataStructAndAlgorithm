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
		Node *current_node = head;
		int count = 0;
		while (current_node != NULL&&count != index) {
			current_node = current_node->next;
			count++;
		}
		if (count == index){
			return current_node;
		}
		return NULL;
	}

	void insert(Node *node, int index) {
		if (head == NULL) {
			head = node;
			return;
		}
		if (index == 0) {
			node->next = head;
			head = node;
		}
		Node *pre_node = find(index - 1);
		if (pre_node != NULL) {
			node->next = pre_node->next;
			pre_node->next = node;
		}
	}

	void remove(int index) {
		if (head == NULL) {
			return;
		}
		Node *delete_node = NULL;
		if (index == 0) {
			delete_node = head;
			head = head->next;
			delete delete_node;
			return;
		}
		Node *pre_node = find(index - 1);
		delete_node = pre_node->next;
		pre_node->next = delete_node->next;
		delete delete_node;
	}

	void reverse() {
		if (head == NULL) {
			return;
		}
		Node *current_node = head->next;
		Node *next_node = NULL;
		head->next = NULL;
		while (current_node != NULL) {
			next_node = current_node->next;
			current_node->next = head;
			head = current_node;
			current_node = next_node;
		}
	}

	void output() {
		if (head == NULL) {
			cout << "Linked List is NULL" << endl;
		}
		Node *current_node = head;
		while (current_node != NULL) {
			cout << current_node->data << " ";
			current_node = current_node->next;
		}
		cout << endl;
	}
private:
	Node *head = NULL;
};

int	main() {
	LinkList linklist;
	for (int i = 0; i < 5; i++)
	{
		Node *node = new Node(i);
		linklist.insert(node, i);
	}
	linklist.output();
	linklist.reverse();
	linklist.output();
	linklist.remove(0);
	linklist.output();
	linklist.remove(1);
	linklist.output();
	system("pause");
	return 0;
}