#include <stdio.h>
int n, m, h, ans;
int ladder[30][10];
int result[10];

bool JudgeResult(int stop)
{
	for (int i = 0; i < n; i++) {
		result[i] = i;
	}

	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (ladder[i][j] == 1) {
				int tmp = result[j];
				result[j] = result[j + 1];
				result[j + 1] = tmp;
				cnt++;
				if (cnt == stop) {
					break;
				}
			}
		}
		if (cnt == stop) {
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		if (result[i] != i) {
			return false;
		}
	}
	return true;
}


void dfs(int cnt, int num, int r, int c)
{
	if (cnt == num) {
		if (JudgeResult(m + num)) {
			ans = num;
		}
		return;
	}

	for (int j = c; j < n - 1; j++) {
		if (!ladder[r][j] && !ladder[r][j + 1]) {
			ladder[r][j] = 1;
			ladder[r][j + 1] = 2;
			dfs(cnt + 1, num, r, j + 1);
			ladder[r][j] = 0;
			ladder[r][j + 1] = 0;
		}
	}
	
	for (int i = r + 1; i < h; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (!ladder[i][j] && !ladder[i][j + 1]) {
				ladder[i][j] = 1;
				ladder[i][j + 1] = 2;
				dfs(cnt + 1, num, i, j + 1);
				ladder[i][j] = 0;
				ladder[i][j + 1] = 0;
			}
		}
	}
	if (ans > 0) return;
}


int main()
{
	scanf("%d%d%d", &n, &m, &h);

	for (int i = 0; i < m; i++) {
		int tr, tc;
		scanf("%d%d", &tr, &tc);
		ladder[tr - 1][tc - 1] = 1;
		ladder[tr - 1][tc] = 2;
	}

	ans = 0;
	if (JudgeResult(m) == false) {
		ans = -1;
		for (int i = 0; i < 3; i++) {
			dfs(0, i + 1, 0, 0);
			if (ans > 0)
				break;
		}
	}
	printf("%d\n", ans);
}