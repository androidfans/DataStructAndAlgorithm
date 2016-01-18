#include "DataStructAndAlgorithm.h"
#include "BinarySearchTree.h"

BinarySearchTreeNode::BinarySearchTreeNode(int _data) : data(_data), lchild(nullptr), rchild(nullptr) {}

BinarySearchTree::BinarySearchTree() : root(nullptr){}

bool BinarySearchTree::insert(int element) {
	if (root == nullptr) 
	{
		root = new BinarySearchTreeNode(element);
		root->father = nullptr;
		return true;
	}
	else
	{
		return root->insert(element);
	}
}

bool BinarySearchTreeNode::insert(int element) {
	if (element == data)
	{
		return false;
	}
	else if (element > data)
	{
		if (rchild == nullptr)
		{
			rchild = new BinarySearchTreeNode(element);
			rchild->father = this;
			return true;
		}
		else
		{
			return rchild->insert(element);
		}
	}
	else
	{
		if (lchild == nullptr)
		{
			lchild = new BinarySearchTreeNode(element);
			lchild->father = this;
			return lchild;
		}
		else
		{
			return lchild->insert(element);
		}
	}
}

void BinarySearchTree::in_order() {
	if (root != nullptr)
	{
		cout << "in_order : ";
		root->in_order();
		cout << endl;
	}
}

void BinarySearchTreeNode::in_order() {
	if (lchild != nullptr)
	{
		lchild->in_order();
	}
	cout << data << " ";
	if (rchild != nullptr)
	{
		rchild->in_order();
	}
}

void BinarySearchTree::pre_order() {
	if (root != nullptr)
	{
		cout << "pre_order : ";
		root->pre_order();
		cout << endl;
	}
}

void BinarySearchTreeNode::pre_order() {
	cout << data << " ";
	if (lchild != nullptr)
	{
		lchild->pre_order();
	}
	if (rchild != nullptr)
	{
		rchild->pre_order();
	}
}

void BinarySearchTree::post_order() {
	if (root != nullptr)
	{
		cout << "post_order : ";
		root->post_order();
		cout << endl;
	}
}

void BinarySearchTreeNode::post_order() {
	if (lchild != nullptr)
	{
		lchild->post_order();
	}
	if (rchild != nullptr)
	{
		rchild->post_order();
	}
	cout << data << " ";
}

BinarySearchTreeNode* BinarySearchTreeNode::predecessor()
{
	BinarySearchTreeNode *temp = lchild;
	while (temp != nullptr && temp -> rchild != nullptr)
	{
		temp = temp->rchild;
	}
	return temp;
}

BinarySearchTreeNode* BinarySearchTreeNode::successor()
{
	BinarySearchTreeNode *temp = rchild;
	while (temp != nullptr && temp->lchild != nullptr)
	{
		temp = temp->lchild;
	}
	return temp;
}

BinarySearchTreeNode* BinarySearchTree::predecessor(int element)
{
	BinarySearchTreeNode *temp = find(element);
	if (temp != nullptr)
	{
		return temp->predecessor();
	}
	return nullptr;
}

BinarySearchTreeNode* BinarySearchTree::successor(int element)
{
	BinarySearchTreeNode *temp = find(element);
	if (temp != nullptr)
	{
		return temp->successor();
	}
	return nullptr;
}

BinarySearchTreeNode* BinarySearchTreeNode::search(int element) 
{
	if (element == data)
	{
		return this;
	}
	else if (element > data)
	{
		if (rchild == nullptr)
		{
			return nullptr;
		}
		else
		{
			rchild->search(element);
		}
	}
	else
	{
		if (lchild == nullptr)
		{
			return nullptr;
		}
		else
		{
			lchild->search(element);
		}
	}
}

BinarySearchTreeNode* BinarySearchTree::find(int element)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	return root->search(element);
}

void BinarySearchTree::delete_node(int element)
{
	BinarySearchTreeNode *temp = find(element);
	if (!temp)
	{
		return;
	}
	if (!temp->father && !temp->lchild && !temp->rchild)
	{
		root = nullptr;
		delete temp;
		return;
	}
	if (temp ->lchild != nullptr)
	{
		BinarySearchTreeNode *predecessor = temp->predecessor();
		temp->data = predecessor->data;
		predecessor->remove_node();
	}
	else if (temp->rchild != nullptr)
	{
		BinarySearchTreeNode *successor = temp->successor();
		temp->data = successor->data;
		successor->remove_node();
	}
	else
	{
		temp->remove_node();
	}
}

void BinarySearchTreeNode::remove_node()
{
	BinarySearchTreeNode *temp = nullptr;
	if (lchild != nullptr)
	{
		temp = lchild;
		//这个操作一定要放到两个if里面做,防止空指针
		temp->father = father;
	}
	if (rchild != nullptr)
	{
		temp = rchild;
		//这个操作一定要放到两个if里面做,防止空指针
		temp->father = father;
	}

	if (father ->lchild == this)
	{
		father->lchild = temp;
	}
	if (father->rchild == this)
	{
		father->rchild = temp;
	}
	delete this;
}