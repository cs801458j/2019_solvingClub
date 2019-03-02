/// 60min

#include <stdio.h>
#include <queue>

using namespace std;

int N, M, ans;
int mr[4] = { -2, -1, 1, 2 };
int mc[4] = { 1, 2, 2, 1 };
typedef struct pos {
	int r, c, cnt, way_chk;
	pos(){}
	pos(int r, int c, int cnt, int way_chk)
		:r(r), c(c), cnt(cnt), way_chk(way_chk) {}
} pos;
queue<pos> q;

int main()
{
	scanf("%d %d", &N, &M);

	pos init_pos(N - 1, 0, 1, 0);
	q.push(init_pos);
	ans = 1;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int cnt = q.front().cnt;
		int way_chk = q.front().way_chk;

		q.pop();

		for (int i = 0; i < 4; i++) {
			pos next;
			next.r = r + mr[i];
			next.c = c + mc[i];
			next.cnt = cnt + 1;
			next.way_chk = way_chk | (1 << i);

			if (next.r < 0 || next.c < 0 || next.r >= N || next.c >= M)
				continue;

			if (next.cnt > 4) {
				if (next.way_chk == 0xF) {
					next.cnt += ((M - 1 - 6) > 0)? M - 7: 0;
					ans = (next.cnt > ans)? next.cnt : ans;
				}
			}
			else {
				ans = next.cnt;
				q.push(next);
			}
		}
	}
	printf("%d\n", ans);
}