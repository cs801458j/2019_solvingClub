#include <stdio.h>

int N;
int mon[100][100];
bool visited[100][100];
int ans = 20000;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };


void MarkFlower(int rr, int cc, bool mark)
{
	for (int i = 0; i < 4; i++) {
		int nr = rr + dr[i];
		int nc = cc + dc[i];

		visited[nr][nc] = mark;
	}
	visited[rr][cc] = mark;
}


bool isFlower(int rr, int cc)
{
	if (visited[rr][cc])	return true;
	for (int i = 0; i < 4; i++) {
		int nr = rr + dr[i];
		int nc = cc + dc[i];

		if (nr < 0 || nc < 0 || nr >= N || nc >= N) 
			return true;
		if (visited[nr][nc]) 
			return true;
	}
	return false;
}


int CalCost(int rr, int cc)
{
	int sum = mon[rr][cc];
	for (int i = 0; i < 4; i++) {
		int nr = rr + dr[i];
		int nc = cc + dc[i];

		sum += mon[nr][nc];
	}
	return sum;
}


void dfs(int flower, int cost)
{

	if (flower == 3) {
		if (cost < ans) {
			ans = cost;
		}
	}
	else {
		for (int i = 0; i < N*N; i++) {
			int r = i / N;
			int c = i % N;

			if (!isFlower(r,c)) {
				int tmp_cost = CalCost(r, c);
				if (cost + tmp_cost > ans) continue;
				MarkFlower(r, c, true);
				dfs(flower + 1, cost + tmp_cost);
				MarkFlower(r, c, false);
				
			}
		}
		
	}
}


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &mon[i][j]);
		}
	}

	dfs(0, 0);

	printf("%d\n", ans);
}

