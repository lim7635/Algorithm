#include <iostream>
#define SIZE 7
using namespace std;

class Graph
{
private:
	int parent[SIZE];

public:
	Graph()
	{
		for (int i = 1; i < SIZE; i++)
		{
			parent[i] = i;
		}
	}

	int Find(int x)
	{
		if (x == parent[x])
		{
			return x;
		}
		else
		{
			return parent[x] = Find(parent[x]);
		}
	}

	void Union(int x, int y)
	{
		x = Find(x);
		y = Find(y);

		if (x < y)
		{
			parent[y] = x;
		}
		else
		{
			parent[x] = y;
		}
	}

	bool Same(int x, int y)
	{
		x = Find(x);
		y = Find(y);

		if (x == y)
		{
			return true;
		}
		return false;
	}

	void Show()
	{
		for (int i = 1; i < SIZE; i++)
		{
			cout << parent[i] << " ";
		}
	}
};


int main()
{
#pragma region 유니온 파인드(Union-Find)
	// 여러 노드가 존재할 때 어떤 노드가 다른 노드와 연결되어 있는지 확인하는 알고리즘입니다.
	// 시간 복잡도 : O(M x logN) M : 연산 횟수, N : 노드 갯수

	Graph graph;

	graph.Union(2, 3);
	graph.Union(1, 3);
	graph.Union(4, 5);
	graph.Union(5, 6);
	graph.Same(1, 3);

	graph.Show();

#pragma endregion

	return 0;
}