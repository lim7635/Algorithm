#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Graph
{
private:
	class Edge
	{
	private:
		int x;
		int y;
		int distance;

	public:
		Edge(int x, int y, int distance)
		{
			this->x = x;
			this->y = y;
			this->distance = distance;
		}

		int Distance()
		{
			return distance;
		}

		bool operator < (const Edge & edge)
		{
			return this->distance < edge.distance; // 오른쪽이 클 경우 true, 왼쪽이 클 경우 false
		}
		
	};

	vector<Edge> edgeList;

public:
	void CreateEdge(int x, int y, int distance)
	{
		edgeList.push_back(Edge(x, y, distance));
	}

	void Sort()
	{
		sort(edgeList.begin(), edgeList.end());
	}

	void Show()
	{
		for (int i = 0; i < edgeList.size(); i++)
		{
			cout << edgeList[i].Distance() << " ";
		}
	}

};

int main()
{
#pragma region 신장 트리(Spanning Tree)
	// 그래프의 모든 정점을 포함하면서 사이클이 존재하지 않는 부분 그래프
	// 그래프의 모든 정점을 최소 비용으로 연결하는 트리
	// 그래프의 정점의 수가 n개일 때 간선의 수는 n - 1개입니다.
	
	// 배열 [10]
	Graph graph;
	graph.CreateEdge(1, 7, 12);
	graph.CreateEdge(4, 7, 13);
	graph.CreateEdge(4, 2, 24);
	graph.CreateEdge(2, 1, 67);
	graph.CreateEdge(2, 5, 60);
	graph.CreateEdge(1, 4, 28);
	graph.CreateEdge(5, 1, 15);
	graph.CreateEdge(5, 7, 73);
	graph.CreateEdge(3, 6, 33);
	graph.CreateEdge(6, 5, 42);
	graph.CreateEdge(5, 3, 22);
	graph.Sort();

	graph.Show();
	
	// 최소 신장 트리(Minimum Spanning Tree, MST)
	// 그래프의 간선들의 가중치 합이 최소인 신장 트리

#pragma endregion

	return 0;
}