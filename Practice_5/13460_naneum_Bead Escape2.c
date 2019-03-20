#include <stdio.h>
#include <queue>
#define RED		0
#define BLUE	1
using namespace std;
typedef struct bead {
	int rr, rc, br, bc, cnt;
	bead() {}
	bead(int rr, int rc, int br, int bc, int cnt)
		: rr(rr), rc(rc), br(br), bc(bc), cnt(cnt){}
}bead;
queue<bead> q;
int n, m;
char map[10][10];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int main()
{
	bead start;
	int gr, gc;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", map[i], sizeof(map));
		for (int j = 0; map[i][j] != NULL; j++) {
			if (map[i][j] == 'R') {
				start.rr = i;
				start.rc = j;
			}
			else if (map[i][j] == 'B') {
				start.br = i;
				start.bc = j;
			}
			else if (map[i][j] == 'O') {
				gr = i;
				gc = j;
			}
		}
	}
	start.cnt = 0;
	q.push(start);
	int ans = -1;
	while (!q.empty()) {
		int rr = q.front().rr;
		int rc = q.front().rc;
		int br = q.front().br;
		int bc = q.front().bc;
		int cnt = q.front().cnt;
		q.pop();

		if (cnt == 10) break;
		
		for (int d = 0; d < 4; d++) {
			int nrr = rr + dr[d];
			int nrc = rc + dc[d];
			int nbr = br + dr[d];
			int nbc = bc + dc[d];

			int move_red = 0;
			int move_blue = 0;
			bool flag_RB = false;
			bool flag_BR = false;
			bool endflag_R = false;
			bool endflag_B = false;

			/// Move Red
			while (map[nrr][nrc] != '#') {
				move_red++;
				if (nrr == br && nrc == bc) {
					flag_RB = true;
				}
				else if (nrr == gr && nrc == gc) {
					endflag_R = true;
					break;
				}
				nrr += dr[d];
				nrc += dc[d];
			}

			/// Move Blue
			while (map[nbr][nbc] != '#') {
				move_blue++;
				if (nbr == rr && nbc == rc) {
					flag_BR = true;
				}
				else if (nbr == gr && nbc == gc) {
					endflag_B = true;
					break;
				}
				nbr += dr[d];
				nbc += dc[d];
			}

			if (!endflag_R && !endflag_B) {
				if (flag_RB) {
					move_red--;
				}
				else if (flag_BR) {
					move_blue--;
				}
                
				int loc_rr = rr + (move_red * dr[d]);
				int loc_rc = rc + (move_red * dc[d]);
				int loc_br = br + (move_blue * dr[d]);
				int loc_bc = bc + (move_blue * dc[d]);
				if (loc_rr == rr && loc_rc == rc && loc_br == br && loc_bc == bc)
					continue;
                
				bead next(loc_rr, loc_rc, loc_br, loc_bc, cnt + 1);
				q.push(next);
			}
			else if (endflag_R && !endflag_B) {
				while (!q.empty()) q.pop();
				ans = cnt + 1;
				break;
			}
		}
	}
	printf("%d\n", ans);
}