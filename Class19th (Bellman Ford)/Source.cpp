#include <iostream>
#include <vector>
#define INF 10000
#define SIZE 5
using namespace std;

class Graph
{
private:
	int distance[SIZE];

	// {(간선을 잇는 출발점, 간선을 잇는 도착점), 간선의 가중치} 형태로 이루어진 vector
	vector<pair<pair<int, int>, int>> edgeList;

public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			distance[i] = INF;
		}
	}

	void CreateEdge(int x, int y, int weight)
	{
		edgeList.push_back(make_pair(make_pair(x, y), weight));
	}

	void BellmanFord(int start)
	{
		distance[start] = 0;

		// 정점의 개수 - 1회만큼 반복
		for (int i = 1; i <= SIZE - 1; i++)
		{
			// 모든 간선 탐색
			for (int j = 0; j < edgeList.size(); j++)
			{
				int from = edgeList[j].first.first;
				int to = edgeList[j].first.second;
				int weight = edgeList[j].second;

				if (distance[from] == INF)
				{
					continue;
				}

				if (distance[to] > distance[from] + weight)
				{
					distance[to] = distance[from] + weight;
				}
			}
		}

		// 음수 사이클이 존재하는지 다시 한 번 모든 간선 탐색
		for (int i = 0; i < edgeList.size(); i++)
		{
			int from = edgeList[i].first.first;
			int to = edgeList[i].first.second;
			int weight = edgeList[i].second;

			if (distance[from] == INF)
			{
				continue;
			}

			// 값이 줄어들면 사이클이 존재한다는 의미와 같음
			if (distance[to] > distance[from] + weight)
			{
				cout << "Negative weight cycle is exist" << endl;
				return;
			}
		}
		Show();
	}

	void Show()
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << distance[i] << " ";
		}
	}

};

int main()
{
#pragma region 벨만 포드 알고리즘(Bellman-Ford)
	// 시작점으로부터 모든 노드까지의 최소 거리를 구해주는 알고리즘입니다.(다익스트라와 공통점)
	// 간선의 가중치가 음수가 있을 경우 사용되며 시간 복잡도는 다익스트라보다 느립니다.(차이점)
	// 그리디 알고리즘이 아님

	// 음수 사이클
	// 음의 가중치로 인해 최소 비용이 제대로 계산되지 않고 음의 무한대까지 가는 사이클
	// 벨만 포드 알고리즘을 통해 그래프에 사이클이 존재하는지 판별할 수 있습니다.

	// 1. 임의의 정점 선택 후 시작점으로 정의합니다.

	// 2. distance[시작점 인덱스]를 0으로 변경합니다.

	// 3. 모든 간선들을 탐색하면서 각 간선의 시작점이 한 번이라도 계산된 정점(INF 보다 작을 경우)이라면
	// 해당 간선이 잇는 정점의 거리를 비교 후 최솟값을 업데이트 한다.

	// 4. 정점 개수 - 1회만큼 3번 과정을 반복합니다.

	// 5. 4번 과정이 끝났다면 음수 사이클 판별을 위해 3번 과정을 한 번 더 진행합니다.

	// 방문하지 않은 노드 중에서 가장 작은 distance를 가진 노드를 방문하고
	// 그 노드와 연결된 다른 노드까지의 거리를 계산합니다.

	Graph graph;

	// 음수 사이클이 존재할 경우
	graph.CreateEdge(1, 2, 3);
	graph.CreateEdge(1, 3, 2);
	graph.CreateEdge(1, 4, 5);
	graph.CreateEdge(2, 3, 3);
	graph.CreateEdge(3, 4, -4);
	graph.CreateEdge(4, 2, -4);
	graph.CreateEdge(0, 3, -2);

	// 음수 사이클이 존재하지 않을 경우
	/*graph.CreateEdge(0, 1, 7);
	graph.CreateEdge(0, 2, 4);
	graph.CreateEdge(0, 3, 6);
	graph.CreateEdge(0, 4, 1);
	graph.CreateEdge(2, 1, 2);
	graph.CreateEdge(2, 3, 5);
	graph.CreateEdge(3, 1, 3);
	graph.CreateEdge(4, 3, 1);*/

	graph.BellmanFord(0);

#pragma endregion

	return 0;
}