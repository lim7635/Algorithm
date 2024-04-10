#include <iostream>
#define SIZE 5
using namespace std;

int main()
{
#pragma region 계수 정렬(Counting Sort)
	// 데이터의 값을 직접 비교하지 않고 단순하게 각 숫자가 몇 개 있는지
	// 개수를 세어 저장한 다음 정렬하는 알고리즘입니다.

	/*int list[] = { 1,4,5,2,3,1,1 };
	int count[SIZE] = { 0, };
	int size = sizeof(list) / sizeof(list[0]);

	for (int i = 0; i < size; i++)
	{
		count[list[i] - 1]++;
	}

	for (const int& element : count)
	{
		cout << element << " ";
	}*/

#pragma endregion

#pragma region 문자열 뒤집기

	/*char str[] = "Hello World";
	for (int i = 0; i < strlen(str) / 2; i++)
	{
		swap(str[i], str[strlen(str) - i - 1]);
	}

	for (const char & element : str)
	{
		cout << element;
	}*/

#pragma endregion

	return 0;
}