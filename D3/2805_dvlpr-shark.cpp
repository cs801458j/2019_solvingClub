
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAX_CHAR_PER_LINE 100

int solve_per_line(int*, int, int);
int solve(char [MAX_CHAR_PER_LINE][MAX_CHAR_PER_LINE], int);

int main(void)
{
	setbuf(stdout, NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++){
		/* algorithm */
		int N;
		scanf("%d\n", &N);
		char table[MAX_CHAR_PER_LINE][MAX_CHAR_PER_LINE] = {0, };
		for(int i=0; i<N; i++){
			scanf("%s", table[i]);
		}

		int ans = solve(table, N);
		printf("#%d %d\n", tc, ans);
	}

	return 0;
}

int solve_per_line(char* list, int size, int rm)
{
	int result = 0;
	int start = rm, limit = size-rm;
	for(int i=rm; i<limit; i++){
		result += list[i] - '0';
	}
	return result;
}

int solve(char table[MAX_CHAR_PER_LINE][MAX_CHAR_PER_LINE], int size)
{
	int center = size/2;
	int rm = center;
	int res = 0;
	for(int i=0; i<center; i++){
		res += solve_per_line(table[i], size, rm--);
	}
	res += solve_per_line(table[center], size, 0);
	rm = center;
	for(int i=size-1; i>center; i--){
		res += solve_per_line(table[i], size, rm--);
	}
	return res;
}
