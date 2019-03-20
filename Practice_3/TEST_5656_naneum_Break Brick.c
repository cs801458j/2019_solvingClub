// ConsoleApplication4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
//#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
vector<int> v;
/// 1 쏜다 dfs
/// 2 숫자 확인 bfs
/// 3 터뜨린다
typedef struct block_info {
	int r, c, range;
}block_info;
queue<block_info> q;

int t, n, w, h, ans;
int block[15][12];
int block_height[12][5];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };


void ExplodeBlock(int cnt)
{
	int del_block[12][2] = { 0, };

	for (int i = 0; i < w; i++) {
		int h_tmp = block_height[i][cnt];
		for (int j = h - h_tmp; j < h; j++) {
			if (block[j][i] < 0) {
				block[j][i] = 0;
				del_block[i][0]++;
				del_block[i][1] = j;
			}
		}
	}


	for (int i = 0; i < w; i++) {
		int s_h = del_block[i][0] + del_block[i][1];
		for (int j = 0; j < del_block[i][0]; j++) {
			block[h - del_block[i][1]][i] = block[h - s_h][i];
			block[h - s_h][i] = 0;
			block_height[i][cnt + 1] = block_height[i][cnt] - del_block[i][0];
		}
	}

}


void CalRange(int cr, int cc, int crng)
{
	block[cr][cc] = -1;

	for (int d = 0; d < 4; d++) {
		int nr = cr;
		int nc = cc;

		while (--crng) {
			nr += dr[d];
			nc += dc[d];

			if (nr < 0 || nr >= h || nc < 0 || nc >= w)
				break;
			else if (block[nr][nc] <= 0)
				break;
			else if (block[nr][nc] > 1) {
				block_info add;
				add.r = nr;
				add.c = nc;
				add.range = block[nr][nc];

				q.push(add);
			}

			block[nr][nc] = -1;
		}
	}
}


void Shot(int idx, int cnt)
{
	while (!q.empty()) q.pop();

	block_info start;
	start.r = block_height[idx][cnt] - 1;
	start.c = idx;
	start.range = block[start.r][start.c];

	q.push(start);

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int rng = q.front().range;

		q.pop();

		CalRange(r, c, rng);
		ExplodeBlock(cnt);
	}


}


void dfs(int col, int cnt)
{
	if (cnt == n) {
		int remainder = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (block[i][j])
					remainder++;
			}
		}
		ans = (remainder < ans) ? remainder : ans;
		return;
	}

	for (int i = 0; i < w; i++) {
		Shot(i, cnt);
		dfs(i, cnt + 1);
	}


}

int main()
{
	FILE* fb;
	freopen_s(&fb, "sample_input.txt", "r", stdin);
	scanf_s("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		ans = 0;
		scanf_s("%d%d%d", &n, &w, &h);
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				scanf_s("%d", &block[i][j]);
				if (!block[i][j]) {
					block_height[j][0] = h - 1 - i;
				}
			}
		}

		dfs(0, 0);
		for (int i = 0; i < w; i++) {
			printf("%d ", block_height[i]);
		}
		printf("\n");
		printf("#%d\n", ans);
	}
}
