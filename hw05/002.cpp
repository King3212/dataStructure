#pragma once
#include<stack>
#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>
template <class T>
struct TreeNode
{
	TreeNode<T>* parents;
	TreeNode<T>* leftChild;
	TreeNode<T>* rightChild;
	T data;
	TreeNode(TreeNode<T>* parents,T data) {
		this->parents = parents;
		this->data = data;
		this->leftChild = nullptr;
		this->rightChild = nullptr;
	}
};

template <class T>
class BST {
private:
	int size;
	int height;
	std::string sign;
	TreeNode<T> *root;
	static void print(TreeNode<T>* node);
	void exPrint(TreeNode<T>* node);
	int getHeight(TreeNode<T>* node);
	void preOrder(void (*visit)(TreeNode<T>* node));
	void preOrderRec(void (*visit)(TreeNode<T>* node),TreeNode<T>* node);
	void inOrder(void (*visit)(TreeNode<T>* node));
	void inOrderRec(void (*visit)(TreeNode<T>* node),TreeNode<T>* node);
	void postOrder(void (*visit)(TreeNode<T>* node));
	void postOrderRec(void (*visit)(TreeNode<T>* node),TreeNode<T>* node);
public:
	void setSign(std::string sign);
	bool insert(T data);
	int getSize();
	int getHeight();
	void preOrderPrint();
	void preOrderRecPrint();
	void inOrderPrint();
	void inOrderRecPrint();
	void postOrderPrint();
	void postOrderRecPrint();
	void exOut(std::string sign);
	BST();
};


template<class T>
inline void BST<T>::setSign(std::string sign)
{
	this->sign = sign;
}

template<class T>
inline bool BST<T>::insert(T data)
{
	if (root) {
		int depth = 0;
		TreeNode<T>* temp = root,*tt = root,*newNode;
		while (temp)
		{
			depth += 1;
			if (temp->data == data) {
				return false;
			}
			tt = temp;
			if (temp->data < data) {
				temp = temp->rightChild;
			}
			else {
				temp = temp->leftChild;
			}
		}
		newNode = new TreeNode<T>(tt, data);
		if (tt->data < data) {
			tt->rightChild = newNode;
		}
		else {
			tt->leftChild = newNode;
		}
		if (height != -1 && depth > height) height = depth;
		size++;
		return true;
	}
	root = new TreeNode<T>(nullptr, data);
	size++;
	height = 1;
	return true;
}

template<class T>
inline void BST<T>::print(TreeNode<T>* node)
{
	if (node) std::cout << node->data << " ";
}

template<class T>
inline void BST<T>::exPrint(TreeNode<T>* node)
{
	if (node) {
		std::cout << node->data << " ";
		exPrint(node->leftChild);
		exPrint(node->rightChild);
	}
	else {
		std::cout << this->sign << " ";
	}
}

template<class T>
inline int BST<T>::getHeight(TreeNode<T>* node)
{
	if (node) return 0;
	else return 1 + std::max(getHeight(node->leftChild), getHeight(node->rightChild));
}

template<class T>
inline void BST<T>::preOrder(void(*visit)(TreeNode<T>* node))
{
	if (!root) return;
	std::stack<TreeNode<T>*> nodes;
	nodes.push(root);
	TreeNode<T>* temp = root;
	while (!nodes.empty())
	{
		temp = nodes.top();
		nodes.pop();
		if (temp) {
			visit(temp);
			if (temp->rightChild) 
				nodes.push(temp->rightChild);
			if (temp->leftChild) 
				nodes.push(temp->leftChild);
		}
	}
}

template<class T>
void BST<T>::preOrderRec(void(*visit)(TreeNode<T>* node),TreeNode<T>* node)
{
	if (node) {
		visit(node);
		if(node->leftChild)
		preOrderRec(visit, node->leftChild);
		if(node->rightChild)
		preOrderRec(visit, node->rightChild);
	}
	return;
}

template<class T>
inline void BST<T>::inOrder(void(*visit)(TreeNode<T>* node))
{
	if (!root) return;
	std::stack<TreeNode<T>*> nodes;
	TreeNode<T>* temp = root;
	while (temp || !nodes.empty())
	{
		if (temp) {
			nodes.push(temp);
			temp = temp->leftChild;
		}
		else {
			temp = nodes.top();
			nodes.pop();
			if (temp) {
				visit(temp);
				temp = temp->rightChild;
			}
		}
	}
	return;
}

template<class T>
void BST<T>::inOrderRec(void(*visit)(TreeNode<T>* node), TreeNode<T>* node)
{
	if (node) {
		if (node->leftChild)
		preOrderRec(visit, node->leftChild);
		visit(node);
		if (node->rightChild)
		preOrderRec(visit, node->rightChild);
	}
	return;
}

template<class T>
inline void BST<T>::postOrder(void(*visit)(TreeNode<T>* node))
{
	std::vector<TreeNode<T>*> getNodes;
	if (!root) return;
	std::stack<TreeNode<T>*> nodes;
	nodes.push(root);
	TreeNode<T>* temp = root;
	while (!nodes.empty())
	{
		temp = nodes.top();
		getNodes.push_back(temp);
		nodes.pop();
		if (temp->rightChild) nodes.push(temp->rightChild);
		if (temp->leftChild) nodes.push(temp->leftChild);
	}
	reverse(getNodes.begin(), getNodes.end());
	for (auto i : getNodes) {
		visit(i);
	}
}

template<class T>
void BST<T>::postOrderRec(void(*visit)(TreeNode<T>* node), TreeNode<T>* node)
{
	if (node) {
		if (node->leftChild)
		preOrderRec(visit, node->leftChild);
		if (node->rightChild)
		preOrderRec(visit, node->rightChild);
		visit(node);
	}
	return;
}

template<class T>
inline int BST<T>::getSize()
{
	return size;
}

template<class T>
inline int BST<T>::getHeight()
{
	if (height == -1) height = getHeight(root);
	return height;
}

template<class T>
inline void BST<T>::preOrderPrint()
{
	void (*funcPtr)(TreeNode<T>*node) = print;
	preOrder(funcPtr);
	std::cout << "\n";
}

template<class T>
inline void BST<T>::preOrderRecPrint()
{
	void (*funcPtr)(TreeNode<T>*node) = print;
	preOrderRec(funcPtr, root);
	std::cout << "\n";
}

template<class T>
inline void BST<T>::inOrderPrint()
{
	void (*funcPtr)(TreeNode<T>*node) = print;
	inOrder(funcPtr);
	std::cout << "\n";
}

template<class T>
inline void BST<T>::inOrderRecPrint()
{
	void (*funcPtr)(TreeNode<T>*node) = print;
	inOrderRec(funcPtr, root);
	std::cout << "\n";
}

template<class T>
inline void BST<T>::postOrderPrint()
{
	void (*funcPtr)(TreeNode<T>*node) = print;
	postOrder(funcPtr);
	std::cout << "\n";
}

template<class T>
inline void BST<T>::postOrderRecPrint()
{
	void (*funcPtr)(TreeNode<T>*node) = print;
	postOrderRec(funcPtr, root);
	std::cout << "\n";
}

template<class T>
inline void BST<T>::exOut(std::string sign)
{
	this->sign = sign;
	exPrint(root);
	std::cout << std::endl;
}

template<class T>
inline BST<T>::BST()
{
	size = 0;
	height = 0;
	root = 0;
	sign = "";
}
