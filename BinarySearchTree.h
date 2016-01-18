#pragma once
class BinarySearchTreeNode {
public:
	BinarySearchTreeNode *lchild, *rchild,*father;
	int data;
	BinarySearchTreeNode(int _data);
	bool insert(int element);
	void delete_node(int element);
	void pre_order();
	void in_order();
	void post_order();
	void remove_node();
	BinarySearchTreeNode* search(int element);
	BinarySearchTreeNode *predecessor();
	BinarySearchTreeNode *successor();
};

class BinarySearchTree {
private:
	BinarySearchTreeNode *root;
public:
	BinarySearchTree();
	bool insert(int element);
	void delete_node(int element);
	void pre_order();
	void in_order();
	void post_order();
	BinarySearchTreeNode* find(int element);
	BinarySearchTreeNode *predecessor(int element);
	BinarySearchTreeNode *successor(int element);
};