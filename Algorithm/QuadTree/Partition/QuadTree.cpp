#include "QuadTree.h"

QuadTree::QuadTree(const Bounds& bounds)
{
	// 루트 노드 생성
	root = new Node(bounds);
}

QuadTree::~QuadTree()
{
	SafeDelete(root);
}


void QuadTree::Insert(Node* node)
{
	// 예외처리
	if (!node) return;

	root->Insert(node);
}

// 질의 함수
std::vector<Node*> QuadTree::Query(Node* queryNode)
{
	// 예외 처리
	if (!queryNode) return{ };

	// 겹침 가능성 있는 영역 확인
	std::vector<Node*> possivleNodes;

	root->Query(queryNode->GetBounds(), possivleNodes);

	// 실제 겹치는 노드들만 확인
	std::vector<Node*> intersects;
	for (Node* const node : possivleNodes)
	{
		for (Node* const point : node->Points())
		{
			if (point->GetBounds().Intersects(queryNode->GetBounds()))
			{
				intersects.emplace_back(point);
				continue;

			}
		}
	}

	// 결과 최종 반환
	return intersects;
}