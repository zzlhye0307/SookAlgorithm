//[백준 7576번] 토마토

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m; //세로 가로
int a[1001][1001];
int d[1001][1001];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int cnt;
int day;
//여기도 누적합으로 구하는 기분
//근데 시작은 1부터 시작해야 함
//해결)처음부터 1인 곳은 q에 넣고 시작하면 됨.

int main() {
	cin >> m >> n;
	queue<pair<int, int>>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) { //토마토가 있으면 큐에 넣기
				q.push(make_pair(i, j));
				d[i][j] = 1; //방문했다고 바로 표시
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 0 && d[nx][ny] == 0) {
					a[nx][ny] += (a[x][y] + 1);
					d[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	day = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && d[i][j] == 0) {
				cout << "-1\n";
				return 0;
			}
			else if (day < a[i][j]) {
				day = a[i][j];
			}
		}
	}
	cout << (day - 1) << '\n';
	return 0;
}
