#pragma once

#include <queue>
#include <vector>
#include <iostream>

template<class T>
class BSTNode
{
public:
	BSTNode(T key) 
		: m_nKey(key), m_pLeft(nullptr), m_pRight(nullptr)
	{

	}

	BSTNode<T> *left() { return m_pLeft; }
	void setLeft(BSTNode<T>* left) { m_pLeft = left; }

	BSTNode<T> *right() { return m_pRight; }
	void setRight(BSTNode<T>* right) { m_pRight = right; }

	const T& key() { return m_nKey; }

private:
	BSTNode<T> *m_pLeft;
	BSTNode<T> *m_pRight;
	T m_nKey;
};

template<class T>
class BST
{
public:
	BST();
	virtual ~BST();

public:
	void insert(T key);
	void remove(T key);
	BSTNode<T>* search(T key);
	std::vector<T> print();

	int length() { return m_nLength; }

private:
	void visitNode(std::vector<T> &keys, BSTNode<T> *pNode);

private:
	BSTNode<T> *m_pRoot;
	int m_nLength = 0;
};

template<class T>
inline BST<T>::BST()
{
	m_pRoot = nullptr;
}

template<class T>
inline BST<T>::~BST()
{
}

template<class T>
inline void BST<T>::insert(T key)
{
	if (m_pRoot == nullptr)
	{
		m_pRoot = new BSTNode<T>(key);
		m_nLength++;
	}
	else
	{
		BSTNode<T> *parent = m_pRoot;
		BSTNode<T> *child = nullptr;
		while (true) {
			if (key > parent->key()) {
				child = parent->right();
				if (child == nullptr) {
					parent->setRight(new BSTNode<T>(key));
					m_nLength++;
					break;
				}
				else {
					parent = child;
				}
			} 
			else if (key < parent->key()) {
				child = parent->left();
				if (child == nullptr) {
					parent->setLeft(new BSTNode<T>(key));
					m_nLength++;
					break;
				}
				else {
					parent = child;
				}
			}
			else {
				std::cout << "same Node" << std::endl;
				return;
			}
		}
	}
}

template<class T>
inline void BST<T>::remove(T key)
{
	if (m_pRoot == nullptr)
	{
		return;
	}
	else
	{
		BSTNode<T> *parent = m_pRoot;
		BSTNode<T> *child = m_pRoot;

		BSTNode<T> *node = nullptr;
		while (true) {
			if (child == nullptr){
				break;
			}

			if (key < child->key()){
				parent = child;
				child = child->left();
			}
			else if (key > child->key()) {
				parent = child;
				child = child->right();
			}
			else {
				node = child;
				break;
			}
		}

		if (node == nullptr) {
			return;
		}
		else {
			m_nLength--;
			if (node->left() == nullptr && node->right() == nullptr) {
				parent->left() == node ? parent->setLeft(nullptr) : parent->setRight(nullptr);
				delete node;
			}
			else if (node->left() == nullptr && node->right() != nullptr){
				parent->left() == node ? parent->setLeft(node->right()) : parent->setRight(node->right());
				delete node;
			}
			else if (node->right() == nullptr && node->left() != nullptr){
				parent->left() == node ? parent->setLeft(node->left()) : parent->setRight(node->left());
				delete node;
			}
			else {
				BSTNode<T> *subParent = node;
				BSTNode<T> *subChild = subParent->left();
				while (true) {
					if (subChild->right() != nullptr) {
						subParent = subChild;
						subChild = subChild->right();
					}
					else {
						break;
					}
				}
				if (subChild == subParent->left())
				{
					subChild->setRight(node->right());

					subParent->setLeft(nullptr);
					parent->left() == node ? parent->setLeft(subChild) : parent->setRight(subChild);
					delete node;
				}
				else {
					if (subChild->left() == nullptr) {
						subParent->setRight(nullptr);

						subChild->setLeft(node->left());
						subChild->setRight(node->right());

						parent->left() == node ? parent->setLeft(subChild) : parent->setRight(subChild);
						delete node;
					}
					else {
						subParent->setRight(subChild->left());

						subChild->setLeft(node->left());
						subChild->setRight(node->right());

						parent->left() == node ? parent->setLeft(subChild) : parent->setRight(subChild);
						delete node;
					}

				}
			}
		}

	}
}

template<class T>
inline BSTNode<T>* BST<T>::search(T key)
{
	if (m_pRoot == nullptr)
	{
		return nullptr;
	}
	else
	{
		BSTNode<T> *parent = m_pRoot;

		while (true)
		{
			if (parent == nullptr)
			{
				return nullptr;
			}
			if (key > parent->key())
			{
				parent = parent->right();
			}
			else if (key < parent->key())
			{
				parent = parent->left();
			}
			else
			{
				return parent;
			}
		}
	}

}

template<class T>
inline std::vector<T> BST<T>::print()
{
	std::vector<T> oKeys;
	if (m_pRoot == nullptr) {
		std::cout << "Empt Tree" << std::endl;
	} 
	else {
		visitNode(oKeys, m_pRoot);
	}

	return oKeys;
}

template<class T>
inline void BST<T>::visitNode(std::vector<T>& keys, BSTNode<T>* node)
{
	if (node != nullptr) {
		if (node->left() != nullptr) {
			visitNode(keys, node->left());
		}

		keys.push_back(node->key());
		std::cout << node->key() << std::endl;

		if (node->right() != nullptr) {
			visitNode(keys, node->right());
		}
	}
}
