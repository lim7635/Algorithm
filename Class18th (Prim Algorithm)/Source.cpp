#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define SIZE 7
#define INF 10000
using namespace std;

//class Graph
//{
//private:
//	int weight[SIZE][SIZE];
//
//	int sum;
//
//public:
//	Graph()
//	{
//		sum = 0;
//
//		for (int i = 0; i < SIZE; i++)
//		{
//			for (int j = 0; j < SIZE; j++)
//			{
//				if (i == j)
//				{
//					weight[i][j] = 0;
//				}
//				else
//				{
//					weight[i][j] = INF;
//				}
//			}
//		}
//	}
//
//	void CreateEdge(int x, int y, int count)
//	{
//		weight[x][y] = count;
//		weight[y][x] = count;
//	}
//	
//	void Prim()
//	{
//
//	}
//
//	int& Cost()
//	{
//		return sum;
//	}
//
//};

class Fruit
{
private:
	string name;
	int price;

public:
	Fruit(string name, int price)
	{
		this->name = name;
		this->price = price;
	}

	int Price()
	{
		return price;
	}

	string Name()
	{
		return name;
	}

	bool operator<(Fruit& a)
	{
		return this->price < a.price;
	}
};

struct cmp
{
	bool operator()(Fruit a, Fruit b)
	{
		return a.Price() > b.Price();
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

	/*Graph graph;

	graph.CreateEdge(1, 2, 15);
	graph.CreateEdge(1, 3, 5);
	graph.CreateEdge(2, 3, 25);
	graph.CreateEdge(2, 5, 36);
	graph.CreateEdge(3, 4, 55);
	graph.CreateEdge(4, 5, 24);
	graph.CreateEdge(4, 6, 28);
	graph.CreateEdge(5, 6, 31);

	graph.Prim();

	cout << "graph의 최소 비용 : " << graph.Cost() << endl;*/

#pragma endregion

#pragma region 우선순위 큐
	// 가장 큰 값이 Top을 유지하도록 우선순위가 설계되어 있는 컨테이너 어댑터

	priority_queue<Fruit, vector<Fruit>, cmp> pq;

	Fruit fruit1("Apple", 5000);
	Fruit fruit2("Banana", 4500);
	Fruit fruit3("Pear", 6000);

	pq.push(fruit1);
	pq.push(fruit2);
	pq.push(fruit3);

	while (pq.empty() == false)
	{
		Fruit A = pq.top();
		cout << A.Name() << " " << A.Price() << endl;
		pq.pop();
	}

#pragma endregion

	return 0;
}