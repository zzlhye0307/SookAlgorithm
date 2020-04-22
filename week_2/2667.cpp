#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int a[30][30];
int d[30][30];  //단지 숫자 번호 1단지, 2단지, 3단지
int dx[] = { 0,0,1,-1 }; 
int dy[] = { 1,-1,0,0 }; 
int n;
int ans[25 * 25];

//dfs를 통한 구현
void dfs(int x, int y, int cnt) {
	
	d[x][y] = cnt;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (a[nx][ny] == 1 && d[nx][ny] == 0) {
				dfs(nx, ny, cnt);
			}
		}
	}
}
int main() {

	//입력받는거 왜 이렇게 밖에 안되나
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//d는 방문한 적 있으면 1 없으면 0
			if (a[i][j] == 1 && d[i][j] == 0) {
				dfs(i, j, ++cnt);
			}
		}
	}
	cout << cnt << '\n';
	
	//같은 단지개수 세기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[d[i][j]] += 1;
		}
	}

	sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << '\n';
	}
	
	return 0;
}
