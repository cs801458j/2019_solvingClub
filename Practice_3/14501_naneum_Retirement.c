#include <stdio.h>
#define max(x, y)	(x>y)?x:y
int N, ans;
int t[15], p[15];

void dfs(int day, int profit)
{
	if (day == N) {
		ans = max(ans, profit);
	}
	else {
		dfs(day + 1, profit);
		if (day + t[day] <= N) {
			dfs(day + t[day], profit + p[day]);
		}
	}
}


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &t[i], &p[i]);
	}

	dfs(0, 0);
	printf("%d\n", ans);
}
