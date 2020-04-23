//[백준 1697번] 숨바꼭질

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int n, k;
int dx[] = { -1,1,2 };
int d[100001];
int t;
int ans=100001;

int bfs(int n, int k) {
	
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	d[n] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int sec = q.front().second;
		q.pop();

		if (x == k) return sec;

		if (x + 1 < 100001 && d[x + 1] == 0) {
			q.push(make_pair(x + 1, sec + 1));
			d[x + 1] = 1;
		}
		if (0 <= x - 1 && d[x - 1] == 0) {
			q.push(make_pair(x - 1, sec + 1));
			d[x - 1] = 1;
		}
		if (2 * x < 100001 && d[2 * x] == 0) {
			q.push(make_pair(2 * x, sec + 1));
			d[2 * x] = 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	cout << bfs(n, k) << '\n';
	return 0;
}
