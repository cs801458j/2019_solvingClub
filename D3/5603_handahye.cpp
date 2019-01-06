#include<iostream>
#include<algorithm>
using namespace std;
/*5603. [Professional] 건초더미*/
//우선 건초더미 크기 순서로 정렬
//가장 크기가 큰 애부터 가장 작은 애한테 배분하는 방식으로
int T,N;
int S[10001];
int main(){
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int cnt = 0, total = 0, avg =0;
		int chk[10001] = { 0, };
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> S[i];
			total += S[i];
		}
		sort(S, S + N);//정렬
		avg = total / N;
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (S[i] <= avg)break;//나눠줄 건초가 없으면 다음으로 큰 건초로 넘어감
				if (chk[j]) continue; //이미 건초가 다 옮겨진 경우
				if (S[j] == avg) {//옮기지 않아도 되는 경우
					chk[j] = 1;
					continue;
				} 
				if (S[j] < avg) {
					int tmp = avg - S[j]; //필요한 횟수
						if (avg <= S[i] - tmp) { //한번에 줄 수 있는 경우
							cnt += tmp;
							S[j] += tmp, S[i] -= tmp;
							chk[j] = 1;
						}
						else if (avg > S[i] - tmp) {//한번에 줄 수 없는 경우
							cnt += (S[i] - avg);
							S[j] += (S[i] - avg);
							S[i] -= (S[i] - avg);
							break;
						}
				}
			}
		}
		printf("#%d %d\n", t, cnt);
	}
	return 0;
}