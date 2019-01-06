#include<iostream>
using namespace std;
/*3131. 100만 이하의 모든 소수*/
int main()
{
	bool res[1000000] = { 0, };
	
	// 배수는 소수가 아니니까 미리 계산해둬서 중복해서 계산하는 걸 방지함
	for (int i = 2; i < 1000000; i++) {
		if (res[i])continue;
		for (int j = 2; j*i < 1000000; j++) {
			res[j*i] = 1;
		}
	}

	for (int i = 2; i < 1000000; i++)
		if (!res[i]) printf("%d ", i);
	return 0;
}