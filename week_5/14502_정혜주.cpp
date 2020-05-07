//[백준 14502번] 8번 연구소

/*
	벽은 꼭 3개를 세워야 함.
	마지막에 0의 개수를 카운트하면 되는디..
	임의로 벽을 다 세우고, 카운트해서 가장 큰 값이 정답
*/
/*
	1)임의로 3개의 벽 설치
	2)바이러스 퍼뜨리기
	3)퍼진 후 0의 개수 세기->최대값으로 갱신

	벽을 세우고 허물고 하는 생각이 중요!!
*/


#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int lab[10][10];
int templab[10][10]; //굳이 쓸 필요x.
int spreadlab[10][10];
int ans = 0;

void virusSpread() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			spreadlab[i][j] = lab[i][j];
		}
	}

	queue<pair<int, int>>q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (spreadlab[i][j] == 2) { //퍼트릴 최초 근원지들
				q.push(make_pair(i, j));
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
				if (spreadlab[nx][ny] == 0) { //빈칸이라면
					spreadlab[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	//안전구역 구하기
	int empty = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (spreadlab[i][j] == 0) {
				empty++;
			}
		}
	}

	if (ans < empty) ans = empty;
}

void go(int cnt) {

	if (cnt == 3) { //벽은 꼭 3개 세워야됨.
		virusSpread();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 0) {
				lab[i][j] = 1; //마찬가지로 세우고
				go(cnt + 1);
				lab[i][j] = 0; //다시 허문다
			}
		}
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];
		}
	}
	go(0); //재귀 호출
	
  cout << ans << '\n';
	return 0;
}
