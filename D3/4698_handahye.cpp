#include<iostream>
using namespace std;
/*4698. 테네스의 특별한 소수*/
int T;
bool res[1000001] = { 0, };
int map[1000001][10] = { 0, };
int main(){
	cin >> T;
	//소수 구하는 부분
	for (int i = 2; i < 1000001; i++) {
		if (res[i])continue;
		for (int j = 2; j*i < 1000001; j++) {
			res[j*i] = 1;
		}
	}
	//2~1000000사이의 숫자가 각 자리에서 어떤 숫자를 가지고 있는지
	for (int i = 2; i < 1000001; i++) {
		if (!res[i]) {
			int tmp = i;
			while (tmp > 0) {
				int n = tmp % 10;
				tmp /= 10;
				map[i][n]++;
			}
		}
	}
	/*실수한 부분: 이 위의 소수 구하는 부분을 밑 for문으로 넣어서 코드를 짰다가 시간 초과가 발생했다*/
	for(int t = 1; t <= T; t++) {
		int D, A, B;
		cin >> D >> A >> B;
		int cnt = 0;
		for (int i = A; i <= B; i++)
			if (map[i][D] > 0) cnt++;

		printf("#%d %d\n", t, cnt);
	}
	return 0;
}