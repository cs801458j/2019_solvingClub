#include <stdio.h>
#include <queue>

using namespace std;

typedef struct pipe
{
	int r, c, dir;
}pipe;
queue<pipe> q;

int n, ans;
int map[16][16];
int dr[3] = { 1, 1, 0 };
int dc[3] = { 0, 1, 1 };


bool isGoal(int r, int c, int dir)
{
	return (r == n - 1 && c == n - 1);
}


void QueuePush(int r, int c, int dir)
{
	pipe tmp;
	tmp.r = r;
	tmp.c = c;
	tmp.dir = dir;
	q.push(tmp);
}


void Init()
{
	ans = 0;
	pipe start;
	/*if (!map[1][0]) {
		start.r = 1;
		start.c = 0;
		start.dir = 0;
		q.push(start);
	}*/
	if (!map[0][1]) {
		start.r = 0;
		start.c = 1;
		start.dir = 2;
		q.push(start);
	}
}


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	Init();

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int dir = q.front().dir;
		q.pop();

		if (isGoal(r, c, dir)) {
			ans++;
			continue;
		}

		for (int d = -1; d <= 1; d++) {
			int ndir = dir + d;
			if (ndir < 0 || ndir > 2) continue;

			int nr = r + dr[ndir];
			int nc = c + dc[ndir];

			if (nr < 0 || nr >= n || nc < 0 || nc >= n) 
				continue;
			else if (map[nr][nc]) 
				continue;
			else if (ndir == 1 && (map[nr][nc - 1] || map[nr - 1][nc]))
				continue;

			QueuePush(nr, nc, ndir);
		}
	}
	printf("%d\n", ans);
}