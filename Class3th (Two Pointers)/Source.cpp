#include <iostream>
using namespace std;

int main()
{
#pragma region 투 포인터(Two Pointers)
	// 두 개의 포인터를 두고 값들을 비교하여 문제를 해결하는 알고리즘입니다.
	// 투 포인터의 시간 복잡도는 O(N)입니다.

	//int list[] = { 2,3,1,4,2,5 };
	//int M = 5;
	//int start = 0;
	//int end = 0;
	//int sum = 0;
	//int count = 0;
	//int size = sizeof(list) / sizeof(int);

	//while (start <= end)
	//{
	//	// 1-1. 현재 부분합이 M 이상이면 start를 1씩 증가시킵니다.
	//	if (sum >= M)
	//	{
	//		sum -= list[start++];
	//	}
	//	// 1-2. end가 size보다 크거나 같으면 반복문을 나옵니다.
	//	else if (end >= size)
	//	{
	//		break;
	//	}
	//	// 1-3. 현재 부분합이 M 미만이면 end를 1씩 증가시킵니다.
	//	else
	//	{
	//		sum += list[end++];
	//	}
	//	
	//	// 2. 현재 부분합이 M과 같으면 count를 증가시킵니다.
	//	if (sum == M)
	//	{
	//		count++;
	//	}
	//}
	//cout << "count의 값 : " << count << endl;

#pragma endregion

#pragma region 최소공배수
	/*int A, B;
	cout << "값을 입력하세요 : ";
	cin >> A >> B;

	int result = 1;
	int i = 2;
	while (i <= A || i <= B)
	{
		if (A % i == 0 && B % i == 0)
		{
			A /= i;
			B /= i;
			result *= i;
		}
		else
		{
			i++;
		}
	}
	cout << "최소공배수 : " << result * A * B << endl;*/

#pragma endregion

	return 0;
}