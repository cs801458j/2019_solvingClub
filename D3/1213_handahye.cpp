#include <iostream>
#include<string.h>
#include<string>
using namespace std;
int T;
int main() {
	for (int t = 1; t <= 10; t++) {
		cin >> T;
		int res = 0;
		char find[1001], str[1001];
		cin >> find >> str;
		char *ptr = strstr(str, find);
		while (ptr != NULL) {
			res++;
			ptr = strstr(ptr + 1, find);
		}

		printf("#%d %d\n", t, res);
	}
	return 0;
}