#include "Container/Tree.h"

int main()
{
	Tree<int> tree(10);
	tree.AddChild(10, 9);
	tree.AddChild(10, 8);
	tree.AddChild(10, 1);
	tree.AddChild(10, 2);
	tree.AddChild(10, 3);

	tree.AddChild(9, 7);
	tree.AddChild(9, 6);

	//검색 테스트
	Node<int>* outNode = nullptr;
	if (tree.Find(6, outNode))
	{
		int number2 = 30;
	}
	tree.PreorderTraversal(0);

	//삭제 테스트
	if (tree.Remove(9))
	{
		int number3 = 30;
	}

	//전위 순회 테스트
	
	int number = 0;

}