#include <iostream>
#include <queue>
#include <vector>
#define SIZE 7
using namespace std;

struct cmp
{
	bool operator() (pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second; // 오른쪽 int 값을 기준으로 오름차순으로 정렬
	}
};

class Graph
{
private:
	int sum;

	bool visited[SIZE];

	// 임의의 정점과 연결된 모든 정점과 간선의 가중치를 추가하는 2차원 배열(왼쪽 : 연결된 정점, 오른쪽 : 가중치)
	vector<pair<int, int>> distance[SIZE];

	// 구조체 cmp를 통해 간선의 가중치 기준 오름차순으로 정렬되어 있는 우선순위 큐
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> edgeList;

public:
	Graph()
	{
		sum = 0;

		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
	}

	// 간선 연결 함수
	void CreateEdge(int x, int y, int weight)
	{
		// 무방향 그래프이기 때문에 양쪽 모두 값 추가
		distance[x].push_back(make_pair(y, weight));
		distance[y].push_back(make_pair(x, weight));
	}

	void Prim(int x)
	{
		visited[x] = true;

		// 임의의 정점 선택 후 정점과 연결된 모든 정점과 간선의 가중치를 큐에 추가 (임의의 정점 : x로 정의)
		for (int i = 0; i < distance[x].size(); i++)
		{
			edgeList.push(distance[x][i]);
		}

		int i = 1;
		// 정점의 개수 - 1회만큼 반복
		while (i < SIZE - 1)
		{

			// 정점과 연결된 간선들 중 가중치 최솟값
			int weight = edgeList.top().second;

			// 가중치 최솟값인 간선이 연결된 정점
			int next = edgeList.top().first;

			edgeList.pop();

			// 만약 방문했다면 위에서부터 다시 진행
			if (visited[next] == true)
			{
				continue;
			}
			// 방문하지 않았다면 next를 방문 처리 후 가중치를 더함
			else
			{
				visited[next] = true;
				sum += weight;
			}

			// next와 연결된 모든 정점 탐색
			for (int j = 0; j < distance[next].size(); j++)
			{
				// 방문하지 않았다면 해당 값을 큐에 추가
				if (visited[distance[next][j].first] == false)
				{
					edgeList.push(distance[next][j]);
				}
			}

			i++;
		}
	}

	int& Cost()
	{
		return sum;
	}

};

int main()
{
#pragma region 신장 트리(Spanning Tree)
	// 그래프의 모든 정점을 포함하면서 사이클이 존재하지 않는 부분 그래프
	// 그래프의 모든 정점을 최소 비용으로 연결하는 트리
	// 그래프의 정점의 수가 n개일 때 간선의 수는 n - 1개입니다.

	// 최소 신장 트리(Minimum Spanning Tree, MST)
	// 그래프의 간선들의 가중치 합이 최소인 신장 트리

	// 프림 알고리즘(Prim Algorithm)
	// 임의의 정점 선택 후 정점 중 최소 비용으로 이동 가능하고 사이클이 생기지 않는 정점을 선택
	// 선택된 모든 정점을 큐에 추가 후 위 과정을 반복
	// 간선의 개수가 많을 때 사용

	Graph graph;

	graph.CreateEdge(1, 2, 15);
	graph.CreateEdge(1, 3, 5);
	graph.CreateEdge(2, 3, 25);
	graph.CreateEdge(2, 5, 36);
	graph.CreateEdge(3, 4, 55);
	graph.CreateEdge(4, 5, 24);
	graph.CreateEdge(4, 6, 28);
	graph.CreateEdge(5, 6, 31);

	graph.Prim(1);

	cout << "graph의 최소 비용 : " << graph.Cost() << endl;

#pragma endregion

#pragma endregion

	return 0;
}