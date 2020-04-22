//[백준 7562번] 나이트의 이동
//요것도 그냥 누적합으로 품/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int c;
int n;
int dx[] = { -1,1,-2,2,-2,2,-1,1 };
int dy[] = { -2,-2,-1,-1,1,1,2,2 };
int a[301][301];
int d[301][301];
int cnt;

int main() {
	int x1, y1;
	int x2, y2;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = 0;
			}
		}
		cin >> x1 >> y1;
		a[x1][y1] = 1;
		cin >> x2 >> y2;

		queue<pair<int, int>>q;
		q.push(make_pair(x1, y1));

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == x2 && y == y2) {
				cout << a[x][y] - 1 << '\n';
				break;
			}
			for (int k = 0; k < 8; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (a[nx][ny] == 0) {
						a[nx][ny] += (a[x][y] + 1);
						q.push(make_pair(nx, ny));
					}
				}
			}
		}

		
	}
	return 0;
}
