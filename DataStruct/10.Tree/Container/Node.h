#pragma once

#include <vector>

//노드 삭제 편의 함수
template <typename T>
void SafeDelete(T*& t)
{
	if (t)
	{
		delete t;
		t = nullptr;
	}
}

//트리의 구성요소가 될 노드 클래스
template<typename T>
class Node
{
public :

private :
	//노드에 저장할 데이터
	T data;

	//부모 참조 노드
	Node<T>* parent = nullptr;

	//자손 노드 리스트(동적 배열)
	std::vector<Node<T>*> children;
};