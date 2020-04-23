//[백준 16929번] Two Dots

#include <iostream>
#include <algorithm>
#include <queue>
#include<cstring>

using namespace std;

int n, m;
int start_x, start_y;
char a[60][60];
int d[60][60];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool flag = false;

void dfs(int x, int y, int line_cnt,int sx, int sy) { 
	//line_cnt: 사각형이 되려면 4 이상
	
	if (flag == true) return;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (d[nx][ny] == 0) { //방문하지 않았다면
				if (a[nx][ny] == a[x][y]) { //같은색이면 탐색
					d[nx][ny] = 1; //방문하고
					dfs(nx, ny, line_cnt + 1, sx, sy);
				}

			}
			else {  //방문한 곳인데 현재 위치랑 스타트가 같고 선분이 4이상이면 사이클
				if (nx == sx && ny == sy && line_cnt >= 4) {
					flag = true;
					return;
				}
			}
		}
	}
}
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	//이것은 dfs로 풀어야 하는 문제 같다
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			memset(d, 0, sizeof(d)); //초기화
			start_x = i;
			start_y = j;
			d[i][j] = 1; //방문
			dfs(i, j, 1, start_x, start_y);
			if (flag == true) {
				cout << "Yes" << '\n';
				return 0;
			}
		}
	}
	
	cout << "No" << '\n';  //완전 다 돌고서도 만족하는게 없으면
	return 0;
}
