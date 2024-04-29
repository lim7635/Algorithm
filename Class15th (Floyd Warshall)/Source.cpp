#include <iostream>
#define SIZE 4
#define INF 1000000
using namespace std;

class Graph
{
private:
	int weight[SIZE][SIZE] =
	{
		{0, 5, INF, 8},
		{7, 0, 9, INF},
		{2, INF, 0, 4},
		{INF, INF, 3, 0}
	};

public:
	void FloydWarshall()
	{
		// 경유하는 노드
		for (int i = 0; i < SIZE; i++)
		{
			// 출발점 노드
			for (int j = 0; j < SIZE; j++)
			{
				// 도착점 노드
				for (int k = 0; k < SIZE; k++)
				{
					if (weight[j][k] > weight[j][i] + weight[i][k])
					{
						weight[j][k] = weight[j][i] + weight[i][k];
					}
				}
			}
		}
	}

	void Show()
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				cout << weight[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
#pragma region 플로이드 워셜(Floyd Warshall)
	// 모든 지점에서 다른 모드 지점까지의 최단 경로를 모두 구해야 하는 경우 사용하는 알고리즘입니다.
	// 시간 복잡도 : O(n^3) 3중 반복

	Graph graph;

	graph.FloydWarshall();

	graph.Show();

#pragma endregion

	return 0;
}