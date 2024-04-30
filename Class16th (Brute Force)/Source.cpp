#include <iostream>
using namespace std;

int main()
{
#pragma region 브루트 포스(Brute Force)
	// 가능한 모든 경우의 수를 모두 탐색하면서 결과를 도출하는 알고리즘입니다.

	int password[3] = { 3,5,7 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (i == password[0] && j == password[1] && k == password[2])
				{
					cout << "비밀번호 : " << i << " " << j << " " << k;
					return 0;
				}
			}
		}
	}

#pragma endregion

	return 0;
}