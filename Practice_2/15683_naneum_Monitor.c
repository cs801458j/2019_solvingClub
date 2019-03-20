/// 60min

#include <stdio.h>
#include <vector>

using namespace std;
typedef struct CCTV_INFO {
	int r, c, type;
	CCTV_INFO(int rr, int cc, int t): r(rr), c(cc), type(t){}
}CCTV_INFO;
vector<CCTV_INFO> cctv;

int N, M, ans = 64;
int map[8][8];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

void MonotorCCTV(int r, int c, int dir, bool chk)
{
	int nr = r; 
	int nc = c; 

	while (1)
	{
		nr += dr[dir];
		nc += dc[dir];

		if (nr < 0 || nc < 0 || nr >= N || nc >= M) break;
		else if (map[nr][nc] < 0) break;

		(chk)? (map[nr][nc]++):(map[nr][nc]--);
	}
}


void AddCCTV(int idx)
{
	if (idx == cctv.size()) {
		int no_mon = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!map[i][j])
					no_mon++;
			}
		}

		ans = (no_mon < ans) ? no_mon : ans;
	}
	else {
		int r = cctv[idx].r;
		int c = cctv[idx].c;

		switch (cctv[idx].type) {
		case 1:
			for (int d = 0; d < 4; d++) {
				MonotorCCTV(r, c, d, true);
				AddCCTV(idx + 1);
				MonotorCCTV(r, c, d, false);
			}
			break;
		case 2:
			for (int d = 0; d < 2; d++) {
				MonotorCCTV(r, c, d, true);
				MonotorCCTV(r, c, d+2, true);
				AddCCTV(idx + 1);
				MonotorCCTV(r, c, d, false);
				MonotorCCTV(r, c, d+2, false);
			}
			break;
		case 3:
			for (int d = 0; d < 4; d++) {
				MonotorCCTV(r, c, d, true);
				MonotorCCTV(r, c, (d + 1) % 4, true);
				AddCCTV(idx + 1);
				MonotorCCTV(r, c, d, false);
				MonotorCCTV(r, c, (d + 1) % 4, false);
			}
			break;
		case 4:
			for (int d = 0; d < 4; d++) {
				MonotorCCTV(r, c, d, true);
				MonotorCCTV(r, c, (d + 1) % 4, true);
				MonotorCCTV(r, c, (d + 3) % 4, true);
				AddCCTV(idx + 1);
				MonotorCCTV(r, c, d, false);
				MonotorCCTV(r, c, (d + 1) % 4, false);
				MonotorCCTV(r, c, (d + 3) % 4, false);
			}
			break;
		case 5:
			for (int d = 0; d < 4; d++) {
				MonotorCCTV(r, c, d, true);
			}
			AddCCTV(idx + 1);
			for (int d = 0; d < 4; d++) {
				MonotorCCTV(r, c, d, false);
			}
			break;
		}
	}
}


int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			scanf("%d", &input);
			if (input == 6) {
				map[i][j] = -1;
			}
			else if (input) {
				map[i][j] = 1;
				CCTV_INFO cam(i, j, input);
				cctv.push_back(cam);
			}
		}
	}

	AddCCTV(0);

	printf("%d\n", ans);
}

