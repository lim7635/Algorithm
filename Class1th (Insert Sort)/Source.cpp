#include <iostream>
#define SIZE 5
using namespace std;

int main()
{
#pragma region 거품 정렬(Bubble Sort)
	// 서로 인접한 두 원소를 검사하여 정렬하는 알고리즘입니다.
	// 거품 정렬의 시간 복잡도는 O(n^2)입니다. (n의 제곱)

	// 1회전 : (n - 1)번 만큼 반복
	// 2회전 : (n - 2)번 만큼 반복
	/*int buffer[SIZE] = { 7,4,3,5,1 };

	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - i - 1; j++)
		{
			if (buffer[j] > buffer[j + 1])
			{
				swap(buffer[j], buffer[j + 1]);
			}
		}

		cout << i + 1 << "회전 : ";
		for (const int& element : buffer)
		{
			cout << element << " ";
		}
		cout << endl;
	}*/

#pragma endregion

#pragma region 선택 정렬(Selection Sort)
	// 주어진 리스트 중에 최소값을 찾아서 맨 앞에 위치한 값과
	// 교체하는 방식으로 정렬하는 알고리즘입니다.
	// 선택 정렬의 시간 복잡도는 O(n^2)입니다. (n의 제곱)

	/*int list[SIZE] = { 9,6,8,3,4 };
	for (int i = 0; i < SIZE - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < SIZE; j++)
		{
			if (list[minIndex] > list[j])
			{
				minIndex = j;
			}
		}
		swap(list[minIndex], list[i]);

		cout << i + 1 << "회전 : ";
		for (const int& element : list)
		{
			cout << element << " ";
		}
		cout << endl;
	}*/

#pragma endregion

#pragma region 삽입 정렬(Insert Sort)
	// data를 하나씩 확인하면서 이미 정렬된 부분과 비교하여
	// 자신의 위치를 찾아 삽입하는 방식으로 정렬하는 알고리즘입니다.
	// 삽입 정렬의 시간 복잡도는 O(n^2)입니다. (n의 제곱)

	/*int list[SIZE] = { 9,6,8,1,3 };
	for (int i = 1; i < SIZE; i++)
	{
		int key = list[i];
		int j = i;
		while (j > 0)
		{
			if (key > list[j - 1])
			{
				break;
			}
			list[j] = list[j - 1];
			j--;
		}
		list[j] = key;

		cout << i << "회전 : ";
		for (const int& element : list)
		{
			cout << element << " ";
		}
		cout << endl;
	}*/

#pragma endregion

	return 0;
}