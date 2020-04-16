//[백준 2178번] 미로 탐색
//bfs
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int a[110][110];
int d[110][110];
int ans[110][110];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

//dfs보단 bfs로 풀어야 됨
//지나온 길의 누적합을 구함
//누적으로 구한다는 생각이 중요했던 문제!

void bfs(int x, int y) {

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = 1;
	
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 1 && d[nx][ny] == 0) {
					a[nx][ny] += a[x][y];  //지나온길의 합을 더 함
					d[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
			
		}
	}
}
int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 && d[i][j] == 0) {
				bfs(i, j);
			}
			
		}
	}
	printf("%d\n", a[n-1][m-1]);

	return 0;
}
