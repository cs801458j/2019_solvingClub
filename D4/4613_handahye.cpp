#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
/*4613. 러시아 국기 같은 깃발*/
int T, N, M, minN;
char map[51][51];
int cal[51][3];
void dfs(int r, int cnt, int curType, int beforeType) {
	if (minN < cnt) return;
	if ((curType == 3 && beforeType == 1)|| (r==N-1 && curType==1)) return;
	if (r == N - 1) {
		minN = min(minN, cnt);
		return;
	}
	for (int type = curType; type <= 3; type++) {
		int change = M - cal[r][type - 1]; //바꿔야 하는 개수
		dfs(r + 1, cnt + change, type, curType);
	}
}
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(map, 0, sizeof(map));
		memset(cal, 0, sizeof(cal));
		minN = 987654321;
		int cnt = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			scanf("%s", map[i]);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				//맨 첫줄과 마지막줄 변경 (W,R로)
				if (i == 0 && map[0][j] != 'W') cnt++;
				else if (i == N - 1 && map[N - 1][j] != 'R') cnt++;
				//각 행마다 W, B, R이 몇개씩 있는지 개수세기
				if (map[i][j] == 'W') cal[i][0]++;
				else if (map[i][j] == 'B') cal[i][1]++;
				else if (map[i][j] == 'R')cal[i][2]++;
			}
		}
		dfs(1, cnt, 1, 1); // r=1이 흰색(1)으로 시작하는 경우
		dfs(1, cnt, 2, 1); // r=1이 파란색(2)으로 시작하는 경우
						   //빨간색인 경우는 고려하지 않아도 됨	
		printf("#%d %d\n", t, minN);
	}
	return 0;
}