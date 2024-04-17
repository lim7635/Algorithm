#include <iostream>
#define SIZE 8
using namespace std;

void QuickSort(int list[], int start, int end)
{
	// 1. 종료 조건
	if (start >= end)
	{
		return;
	}

	// 2. pivot 변수의 값을 설정합니다.(pivot은 배열의 가운데에 있는 값이 가장 선호됨)
	int pivot = start;

	// 3. left 변수의 값을 설정합니다.
	int left = start + 1;

	// 4. right 변수의 값을 설정합니다.
	int right = end;

	// 5. left가 right보다 크거나 같을 때까지 반복합니다.
	while (left <= right)
	{
		// 6. left가 end보다 작거나 같고 list[left]가 list[pivot]보다 작거나 같을 때까지 반복합니다.
		while (left <= end && list[left] <= list[pivot])
		{
			left++;
		}

		// 6. right가 start보다 크고 list[right]가 list[pivot]보다 크거나 같을 때까지 반복합니다.
		while (right > start && list[right] >= list[pivot])
		{
			right--;
		}

		if (left > right)
		{
			swap(list[pivot], list[right]);
		}
		else
		{
			swap(list[left], list[right]);
		}
	}
	QuickSort(list, start, right - 1);
	QuickSort(list, right + 1, end);
}

int main()
{
#pragma region 퀵 정렬(분할 정복)
	// 기준점을 획득한 다음 해당 기준점을 기준으로 배열을 나누고
	// 한 쪽에는 기준점보다 작은 값들이 위치하고
	// 다른 한 쪽에는 기준점보다 큰 값들이 위치하도록 합니다.
	// 정렬되지 않은 배열 순서 정리할 때 용이

	// 나누어진 하위 배열에 대해 재귀적으로 퀵 정렬을 호출하여
	// 모든 배열이 기본 배열이 될 때까지 반복하면서 정렬하는 알고리즘입니다.
	// 시간 복잡도 : 평균(n X log(n)), 최악(n^2)

	int list[SIZE] = { 5,9,6,2,1,3,4,7 };

	QuickSort(list, 0, SIZE - 1);
	for (const int& element : list)
	{
		cout << element << " ";
	}

#pragma endregion

	return 0;
}