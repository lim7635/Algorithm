#include <iostream>
#include <math.h>
using namespace std;

int Euclid(int x, int y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return Euclid(y, x % y);
	}
}

int main()
{
#pragma region 유클리드 호제법
	// 2개의 자연수 또는 정식의 최대 공약수를 구하는 알고리즘으로
	// 두 수가 서로 상대방 수를 나누어서 원하는 수를 얻어내는 알고리즘입니다.
	// 시간 복잡도 : O(Log N)

	int A = 150;
	int B = 108;
	
	cout << "두 수의 최대 공약수 : " << Euclid(max(A, B), min(A, B)) << endl;

#pragma endregion

	return 0;
}