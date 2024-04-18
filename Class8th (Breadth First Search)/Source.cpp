#include <iostream>
#include <queue>
#include <vector>
#define SIZE 9
using namespace std;

class Graph
{
private:
	queue<int> queue;

	vector<int> graph[SIZE];

	bool visited[SIZE];

public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
	}

	void InsertEdge(int vertex, int edge)
	{
		graph[vertex].push_back(edge);
	}

	void BFS(int start)
	{
		queue.push(start);

		visited[start] = true;

		while (queue.empty() == false)
		{
			int x = queue.front();

			queue.pop();

			cout << x << " ";

			for (int i = 0; i < graph[x].size(); i++)
			{
				if (visited[graph[x][i]] == false)
				{
					queue.push(graph[x][i]);
					visited[graph[x][i]] = true;
				}
			}
		}
	}
};

int main()
{
#pragma region 너비 우선 탐색(Breadth First Search) BFS
	// root 노드에서 시작한 다음 인접한 노드를 먼저 탐색하는 방법입니다.
	// 시간 복잡도 : O(V + E)
	// 길 찾기 알고리즘에 용이

	Graph graph;

	graph.InsertEdge(1, 2);
	graph.InsertEdge(1, 3);
	graph.InsertEdge(1, 8);

	graph.InsertEdge(2, 1);
	graph.InsertEdge(2, 7);

	graph.InsertEdge(3, 1);
	graph.InsertEdge(3, 4);
	graph.InsertEdge(3, 5);

	graph.InsertEdge(4, 3);
	graph.InsertEdge(4, 5);

	graph.InsertEdge(5, 3);
	graph.InsertEdge(5, 4);

	graph.InsertEdge(6, 7);

	graph.InsertEdge(7, 2);
	graph.InsertEdge(7, 6);
	graph.InsertEdge(7, 8);

	graph.InsertEdge(8, 1);
	graph.InsertEdge(8, 7);

	graph.BFS(1); // EX) 1이 root 노드일 경우

#pragma endregion

	return 0;
}