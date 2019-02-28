//75min

#include <stdio.h>
#include <queue>

using namespace std;

typedef struct coord {
	int r, c, n, cnt;
	coord(int x, int y) : r(x), c(y) {}
	coord(int x, int y, int z, int a) : r(x), c(y), n(z), cnt(a) {}
}coord;

int N;
int map[100][100];
int visited[100][100];
int cntmap[100][100];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int main()
{
    int idx = 0;
    int complete = 0;
    int ans = 10000;
    
	queue<coord> q;
	queue<coord> coast;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !visited[i][j]) {
				coord land(i, j);
				q.push(land);

				visited[i][j] = ++idx;
				
				while (!q.empty()) {
					int r = q.front().r;
					int c = q.front().c;
					q.pop();
					
					bool coast_chk = false;

					for (int i = 0; i < 4; i++) {
						coord n(r + dr[i], c + dc[i]);

						if (n.r < 0 || n.c < 0 || n.r >= N || n.c >= N)
							continue;
						if (!visited[n.r][n.c] && map[n.r][n.c]) {
							visited[n.r][n.c] = idx;
							q.push(n);
						}
						else if (!map[n.r][n.c])
							coast_chk = true;
					}

					if (coast_chk) {
						coord coa(r, c, idx, 0);
						coast.push(coa);
					}
				}
			}
		}
	}
	
	while (!coast.empty()) {
		coord cur(coast.front().r, coast.front().c, coast.front().n, coast.front().cnt);
		coast.pop();

		if (complete && complete != cur.cnt) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			coord next(cur.r + dr[i], cur.c + dc[i], cur.n, cur.cnt + 1);

			if (next.r < 0 || next.c < 0 || next.r >= N || next.c >= N)
				continue;
			if (!visited[next.r][next.c] && !map[next.r][next.c]) {
				visited[next.r][next.c] = next.n;
				if (cntmap[next.r][next.c])
					cntmap[next.r][next.c] = (cntmap[next.r][next.c] > next.cnt) ? next.cnt : cntmap[next.r][next.c];
				else
					cntmap[next.r][next.c] = next.cnt;
				coast.push(next);
			}
			else if (next.n != visited[next.r][next.c] && !map[next.r][next.c]) {
				int bridge = cur.cnt + cntmap[next.r][next.c];
				if (bridge < ans)
					ans = bridge;
				complete = cur.cnt;
				break;
			}
		}
	}

	printf("%d\n", ans);
}

