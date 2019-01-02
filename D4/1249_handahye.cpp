#include<iostream>
#include<queue>
using namespace std;
struct pq {
	int r, c, cost;
};
bool operator<(pq a, pq b) {
	return a.cost < b.cost;
}
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
int T, n;
int map[101][101] = { 0, }, dist[101][101] = { 0, };
void bfs() {
	//다익스트라 알고리즘
	priority_queue<pq>que;
	dist[0][0] = 0;
	que.push({ 0,0,-dist[0][0] }); //시작점의 정보

	while (!que.empty()) {
		int r = que.top().r;
		int c = que.top().c;
		int cost = -que.top().cost;
		que.pop();

		if (dist[r][c] < cost) continue; // 더 짧은 거리를 알고 있으면 무시함

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			int nextCost = map[nr][nc];
			if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
				if (dist[nr][nc] > nextCost + cost) { //더 짧은 경로를 안다면
					dist[nr][nc] = nextCost + cost;
					que.push({nr,nc,-dist[nr][nc]});//작은 값부터 꺼내기 위해서 - 붙임
				}
			}
		}
	}
}
int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> n;
		for (int i = 0; i<n; i++){
			for (int j = 0; j<n; j++){
				scanf("%1d", &map[i][j]);
				dist[i][j] = 987654321; //무한대의 거리로 초기화
			}
		}
		bfs();
		printf("#%d %d\n", t, dist[n - 1][n - 1]);
	}
	return 0;
}