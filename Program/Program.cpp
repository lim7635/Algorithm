#include <iostream>
#define SIZE 7
using namespace std;

void BinarySearch(int list[], int key)
{
	int left = 0;
	int right = SIZE - 1;

	while (left <= right)
	{
		// 1. 배열의 가운데 요소의 인덱스를 pivot으로 설정합니다.
		int pivot = (left + right) / 2;

		// 2. list[pivot]의 값이 찾고자하는 값과 같다면 검색을 종료합니다.
		if (list[pivot] == key)
		{
			cout << "Key is Found : " << list[pivot] << endl;
			return;
		}

		// 3. list[pivot]의 값이 찾고자하는 값보다 크다면 left ~ pivot 사이의 값을 검색합니다.
		else if (list[pivot] > key)
		{
			right = pivot - 1;
		}

		// 4. list[pivot]의 값이 찾고자하는 값보다 크다면 right ~ pivot 사이의 값을 검색합니다.
		else if (list[pivot] < key)
		{
			left = pivot + 1;
		}
	}

	cout << "Key isn't Found" << endl;
}

int main()
{
#pragma region 이진 탐색(Binary Search)
	// 순서가 정렬된 리스트에서 특정한 값의 위치를 찾는 알고리즘입니다.
	// 이진 탐색의 시간 복잡도는 O(log N)입니다.

	/*int list[SIZE] = { 5,6,11,13,27,55,88 };

	BinarySearch(list, 11);*/
	
#pragma endregion

#pragma region 소프트웨어 개발 원칙(SOLID)

#pragma region 단일 책임 원칙(Single Responsibility Principle) SRP
	// 하나의 객체는 반드시 하나의 책임만을 가지고 있도록 해야합니다.
	// 하나의 클래스가 여러 책임을 가지고 있다면 클래스를 분리해야 합니다.

#pragma endregion

#pragma region 개방 폐쇄 원칙(Open Closed Principle) OCP
	// 클래스는 확장에 대해서는 열러 있어야 하지만 수정에 대해서는 닫혀 있어야 합니다.

#pragma endregion

#pragma region 리스코프 치환 원칙(Liskov Substitution Principle) LSP
	// 하위 클래스는 상위 클래스에서 가능한 행위를 수행할 수 있어야 하며
	// 하위 클래스는 상위 클래스의 행위를 변경하지 않고 확장할 수 있어야 합니다.

#pragma endregion

#pragma region 인터페이스 분리 원칙(Interface Segregation Principle) ISP


#pragma endregion

#pragma region 의존성 역전 원칙(Dependency Inversion Principle) DIP


#pragma endregion

#pragma endregion

	return 0;
}