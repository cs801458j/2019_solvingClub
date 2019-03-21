#include <stdio.h>
int n, l;
int map[100][100];
int main()
{
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int ans = 0;

	///horizontal line
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		bool fail_flag = false;
		for (int j = 1; j < n; j++) {
			int diff = map[i][j] - map[i][j - 1];
			
			if (diff == 0) {
				cnt++;
			}
			else if (diff == 1 && cnt >= l) {
				cnt = 1;
			}
			else if (diff == -1 && cnt >= 0) {
				cnt = 1 - l;
			}
			else {
				fail_flag = true;
				break;
			}
		}
		if (fail_flag) continue;
		if (cnt >= 0) {

			ans++;
		}
	}
	/// vertical line
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		bool fail_flag = false;
		for (int j = 1; j < n; j++) {
			int diff = map[j][i] - map[j - 1][i];

			if (diff == 0) {
				cnt++;
			}
			else if (diff == 1 && cnt >= l) {
				cnt = 1;
			}
			else if (diff == -1 && cnt >= 0) {
				cnt = 1 - l;
			}
			else {
				fail_flag = true;
				break;
			}
		}
		if (fail_flag) continue;
		if (cnt >= 0) {
			ans++;
		}
	}
	printf("%d\n", ans);
}