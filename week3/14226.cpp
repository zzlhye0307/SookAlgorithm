//[백준 14226번] 이모티콘
//BFS와 DP가 섞인듯한 문제

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n;
int a[1001][1001]; //screen, clip
int d[1001][1001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	queue<pair<int, int>>q;

	q.push(make_pair(1, 0)); //s:화면 스티커 개수, c:클립보드 스티커 개수
	d[1][0] = 1; //방문

	while (!q.empty()) {
		int ns = q.front().first;
		int nc = q.front().second;
		q.pop();

		//클립보드 복사
		if (d[ns][ns] == 0) {
			q.push(make_pair(ns, ns));
			a[ns][ns] = a[ns][nc] + 1;
			d[ns][ns] = 1;
		}

		//화면에 붙여넣기
		if (ns + nc < 1001) {
			if (d[ns + nc][nc] == 0) {
				q.push(make_pair(ns + nc, nc));
				a[ns + nc][nc] = a[ns][nc] + 1;
				d[ns + nc][nc] = 1;
			}
		}
		//screen 1개 삭제
		if (ns - 1 > 0) {
			if (d[ns - 1][nc] == 0) {
				q.push(make_pair(ns - 1, nc));
				a[ns - 1][nc] = a[ns][nc] + 1;
				d[ns - 1][nc] = 1;
			}
		}
	}

	int ans = a[n][1];
	for (int i = 2; i <= n; i++) {
		if (ans > a[n][i]) { //a[n][i]중 가장 작은 값을 찾으면 됨.
			ans = a[n][i];
		}
	}
	cout << ans << '\n';
	return 0;
}
