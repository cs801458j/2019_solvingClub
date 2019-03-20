#include <stdio.h>
#include <queue>
#include <vector>

#define SIZE	0
#define FEED	1
using namespace std;

typedef struct coord {
	int r, c, near;
}coord;

coord pos;
int bshk[2];
int N, ans = 0;
int sea[20][20];
bool visited[20][20];
int dr[4] = { -1, 0, 0, 1 };
int dc[4] = { 0, -1, 1, 0 };

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &sea[i][j]);
			if (sea[i][j] == 9) {
				sea[i][j] = 0;
				pos.r = i;
				pos.c = j;
				pos.near = 0;
				visited[i][j] = true;
			}
		}
	}

	bshk[SIZE] = 2;
	bshk[FEED]= bshk[SIZE];

	while (1) {
		int r_min = 20;
		int range = -1;
		vector<coord> f;
		queue<coord> q;
		q.push(pos);

		while (!q.empty()) {
			int r = q.front().r;
			int c = q.front().c;
			int near = q.front().near;

			if (range == near) break;

			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				coord nxt;
				nxt.r = r + dr[dir];
				nxt.c = c + dc[dir];
				nxt.near = near + 1;

				if (nxt.r < 0 || nxt.c < 0 || nxt.r >= N || nxt.c >= N)
					continue;
				else if (sea[nxt.r][nxt.c] > bshk[SIZE])
					continue;
				else if (sea[nxt.r][nxt.c] && sea[nxt.r][nxt.c] < bshk[SIZE]) {
					range = nxt.near;
					f.push_back(nxt);
					r_min = (nxt.r < r_min) ? nxt.r : r_min;
				}

				if (!visited[nxt.r][nxt.c]) {
					visited[nxt.r][nxt.c] = true;
					q.push(nxt);
				}
			}
		}

		if (range == -1) break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = false;
			}
		}

		int c_min = 20;
		for (int i = 0; i < f.size(); i++) {
			if (f[i].r == r_min) {
				c_min = (f[i].c < c_min) ? f[i].c : c_min;
			}
		}

		sea[r_min][c_min] = 0;
		visited[r_min][c_min] = true;
		pos.r = r_min;
		pos.c = c_min;

		bshk[FEED]--;
		if (!bshk[FEED]) {
			bshk[SIZE]++;
			bshk[FEED] = bshk[SIZE];
		}
		ans += range;
	}
	printf("%d\n", ans);
}
