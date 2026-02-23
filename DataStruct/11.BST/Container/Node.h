#pragma once


#include <iostream>

//이전 트리에 사용할 노드 클래스
template <typename T>
class Node
{
public :
	template<typename T>
	friend class BinarySearchTree;

	Node(const T& data, Node<T>* const parent = nullptr) : data(data), parent(parent)
	{

	}

private :
	//데이터 변수
	T data = T();
	//부모 노드
	Node<T>* parent = nullptr;

	//왼쪽 자손 노드
	Node <T>* left = nullptr;

	//오른쪽 자손 노드
	Node <T>* right = nullptr;

};
