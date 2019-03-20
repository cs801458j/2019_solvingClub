#include <stdio.h>
#include <queue>
#include <memory.h>
#define H	12
#define W	6
using namespace std;
typedef struct puyoinfo {
	int r, c;
	puyoinfo(int r, int c) : r(r), c(c) {}
}puyoinfo;

int ans;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
char map[H][W];
int visited[H][W];
bool explosion_flag;

void VisitInitialize()
{
	memset(visited, 0, sizeof(visited));
}

void Relocate()
{
	for (int i = 0; i < W; i++) {
		for (int j = H - 1; j >= 0; j--) {
			if (map[j][i] != '.') continue;
			for (int k = j - 1; k >= 0; k--) {
				if (map[k][i] != '.') {
					map[j][i] = map[k][i];
					map[k][i] = '.';
					break;
				}
			}
		}
	}
}


void ChkExplosion(int cr, int cc, char color)
{
	queue<puyoinfo> q;
	queue<puyoinfo> explode;
	puyoinfo puyo(cr, cc);
	q.push(puyo);
	explode.push(puyo);

	int cnt = visited[cr][cc];
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nr >= H || nc < 0 || nc >= W)
				continue;

			if (!visited[nr][nc] && map[nr][nc] == color) {
				puyoinfo next(nr, nc);
				visited[nr][nc] = ++cnt;
				q.push(next);
				explode.push(next);
			}
		}
	}

	if (cnt < 4) return;

	explosion_flag = true;
	while (!explode.empty()) {
		int r = explode.front().r;
		int c = explode.front().c;
		explode.pop();
		map[r][c] = '.';
	}
}

int main()
{
	for (int i = 0; i < H; i++) {
		scanf("%s", map[i], sizeof(map));
	}
	VisitInitialize();
	explosion_flag = true;
	while (explosion_flag) {
		explosion_flag = false;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] != '.' && !visited[i][j]) {
					visited[i][j] = 1;
					ChkExplosion(i, j, map[i][j]);
				}
			}
		}
		if (!explosion_flag) break;
		ans++;
		Relocate();
		VisitInitialize();
	}
	printf("%d\n", ans);
}