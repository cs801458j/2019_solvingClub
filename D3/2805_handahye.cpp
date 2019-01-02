#include <iostream>
#include<string.h>
#include<queue>
using namespace std;
struct que {
	int x;
	int y;
	int cnt;
};
int T, N, x, y;
int map[50][50], visit[50][50];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int res = 0;
		queue<que> que;
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));
		cin >> N;
		x = N / 2, y = N / 2; //중점 찾기

		for (int i = 0; i < N; i++)
			for (int j = 0; j<N; j++)
				scanf("%1d", &map[i][j]);

		que.push({ x,y,0 });
		res += map[x][y];
		visit[x][y] = 1;

		while (!que.empty()) {
			int curX = que.front().x;
			int curY = que.front().y;
			int cnt = que.front().cnt;

			que.pop();
			for (int i = 0; i < 4; i++) {
				int nx = curX + dx[i];
				int ny = curY + dy[i];
				if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[nx][ny]) {
					res += map[nx][ny];
					visit[nx][ny] = 1;
					if (cnt + 1 == N / 2) continue; //이때 더 증가하면 마름모꼴이 아님
					que.push({ nx,ny,cnt + 1 });
				}
			}

		}
		printf("#%d %d\n", t, res);
	}
	return 0;
}