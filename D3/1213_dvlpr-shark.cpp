#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE 1001
#define MAX_STRING 11

void input(char*, char*);
void ClearBuffer(void);
int findStr(char*, char*);
int Solve(char*, char*);

int main(void)
{
	int T = 10;
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	for(int i=1; i<=T; i++){
		/* Algorithm */
		char str[MAX_STRING] = {0, };
		char sentence[MAX_SENTENCE] = {0, };
		int ans;
		ClearBuffer();
		input(str, sentence);
		ans = Solve(str, sentence);
		printf("#%d %d\n", i, ans);
	}

	return 0;
}

void input(char* str, char* stc)
{
	scanf("%s", str);
	scanf("%s", stc);
}

void ClearBuffer(void)
{
	int temp;
	scanf("%d", &temp);
}

int findStr(char* str, char* stc)
{
	int len = strlen(str);
	for(int i=0; i<len; i++){
		if(str[i] != stc[i])
			return false;
	}
	return true;
}

int Solve(char* str, char* stc)
{
	int n = strlen(stc);
	int result = 0;
	for(int i=0; i<n ;i++){
		if(findStr(str, stc+i))
			result++;
	}
	return result;
}
