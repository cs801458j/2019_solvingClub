#include <iostream>
using namespace std;
int T, N;
int arr[1000001];
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		long long totalSum = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		int max = arr[N - 1]; //제일 마지막 값을 max로 지정
		for (int i = N - 1; i >= 0; i--) {//n-1부터 for문 돌아서 
			if (max >= arr[i]) totalSum += max - arr[i]; //현재 max값보다 작을 경우 물건 삼(totalSum에 값 더해줌)
			else max = arr[i];//현재 max값보다 큰 경우, 현재 index의 값으로 max값 변경해줌
		}
		printf("#%d %lld\n", t, totalSum);
	}
	return 0;
}