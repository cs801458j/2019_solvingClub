#include <stdio.h>
#include <queue>
using namespace std;
typedef struct loc {
	int r, c, out, time;
}loc;
int t, n, m, l, ans;
int map[50][50];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int tunnel[8][4] = {
	{0, 0, 0, 0},
	{1, 1, 1, 1},
	{1, 0, 1, 0},
	{0, 1, 0, 1},
	{1, 1, 0, 0},
	{0, 1, 1, 0},
	{0, 0, 1, 1},
	{1, 0, 0, 1}
};

int main()
{
	//FILE* ff;
	//freopen_s(&ff, "sample_input.txt", "r", stdin);
	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		bool visited[50][50] = { false, };
		queue<loc> q;
		loc start;
		ans = 1;
		scanf("%d%d%d%d%d", &n, &m, &start.r, &start.c, &l);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		visited[start.r][start.c] = true;
		for (int i = 0; i < 4; i++) {
			if (tunnel[map[start.r][start.c]][i]) {
				start.out = i;
				start.time = 1;
				q.push(start);
			}
		}

		while (!q.empty()) {
			int r = q.front().r;
			int c = q.front().c;
			int out = q.front().out;
			int time = q.front().time;
			q.pop();

			int nr = r + dr[out];
			int nc = c + dc[out];

			if (nr < 0 || nc < 0 || nr >= n || nc >= m)
				continue;
			else if (!map[nr][nc] || visited[nr][nc] || !tunnel[map[nr][nc]][(out + 2) % 4])
				continue;
			else if (time >= l)
				continue;

			ans++;
			visited[nr][nc] = true;

			for (int i = 0; i < 4; i++) {
				if (tunnel[map[nr][nc]][i]) {
					loc next;
					next.r = nr;
					next.c = nc;
					next.out = i;
					next.time = time + 1;
					q.push(next);
				}
			}
		}
		printf("#%d %d\n", tc + 1, ans);
	}
}