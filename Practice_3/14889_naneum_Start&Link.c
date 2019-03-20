#include <stdio.h>
#include <stdlib.h>

int N, ans = 1000;
int S[20][20], t[2][10], tcnt[2];

void MakeTeam(int cnt)
{
	if (ans == 0) 	return;
	if (t[0][0])	return;

	if (cnt == N) {
		int sum[2] = {0, };
		for (int i = 0; i <  N / 2; i++) {
			for (int j = i + 1; j <  N / 2; j++) {
				sum[0] += S[t[0][i]][t[0][j]] + S[t[0][j]][t[0][i]];
				sum[1] += S[t[1][i]][t[1][j]] + S[t[1][j]][t[1][i]];
			}	
		}
		int diff = abs(sum[0] - sum[1]);
		if (diff < ans) ans = diff;
	}
	else {
		for(int i = 0; i  < 2; i++){
			if(tcnt[i] < N/2)
			{
				t[i][(tcnt[i])++] = cnt;
				MakeTeam(cnt + 1);
				tcnt[i]--;
			}
		}
	}
}


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &S[i][j]);
		}
	}
	MakeTeam(0);
	printf("%d\n", ans);
}