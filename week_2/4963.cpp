//[백준 4963번] 섬의 개수
//bfs, dfs 2가지 방법으로 다 풀어보기

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int h, w;
int a[55][55]; //입력받는 섬 배열
int d[55][55]; //방문했는지 안했는지 판단 배열

//대각선까지 총 8방향.
// 우,하,좌,상,우상,우하,좌상,좌하
int dx[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
int dy[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };

void dfs(int x, int y) {
	d[x][y] = 1;

	for (int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		//지도를 벗어나지 않고
		if (0 <= nx && nx < h  && 0 <= ny && ny < w) {
			//섬이면서 방문하지 않았다면
			if (a[nx][ny] == 1 && d[nx][ny] == 0) {
				d[nx][ny] = 1;
				dfs(nx, ny);
			}
		}
	}
}
void bfs(int x, int y) {

	//큐를 이용해서 지금 위치에서 갈 수 있는 것을 모두 큐에 넣는 방식
	//큐에 넣을 때 방문했다고 체크해야 한다.
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = 1;

	//큐 안에 인접된 곳들이 다 들어있으므로
	//큐가 empty가 될때까지 탐색해야 너비 우선이 됨.
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < h && 0 <= ny && ny < w) {
				if (a[nx][ny] == 1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = 1;
				}
			}
		}
	}                  
}
int main() {

	int cnt;
	//마지막 줄에 0 0이 입력 될 때까지
	while (true) {
		
		cin >> w >> h;
		if (h == 0 && w == 0) break;
	

		//그래프 입력
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];
			}
		}
		
		//초기화
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				d[i][j] = 0;
			}
		}
		cnt = 0;

		//그래프 dfs, bfs통해 탐색
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				//땅이 존재하고(1), 방문하지 않았으면(0)
				if (a[i][j] == 1 && d[i][j] == 0) {
					cnt++;
					//dfs(i, j);
					bfs(i, j);
					
				}
			}
		}
		cout << cnt << '\n';		
	}
	return 0;
}
