//[백준 13460번] 1번 구슬 탈출2
/*
	위위위위로 재귀로 구현하여 구슬을 이동시키지만,
	이전의 방향과 같은 방향은 보내지 않으며
	반대방향은 보내면 이전의 방향이니깐 역시 보내지 않는다.

	빨간공과 파란공이 같은 좌표에 위치한다면
	이동거리를 계산해서 더 많이 이동한 공이 한칸 이전으로 이동.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char a[11][11];
int ri, rj, bi, bj;
int cnt, ans = 987654321;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int inverse_dir(int d){

	if (d == 0) return 1;
	else if (d == 1) return 0;
	else if (d == 2) return 3;
	else if (d == 3) return 2;
}
int move_dist(int x, int y, int xx, int yy){
	return abs(x - xx) + abs(y - yy);
}
void go(int rx, int ry, int bx, int by, int cnt, int dir) {

	if (cnt >= ans) return;
	if (cnt > 10) return;

	bool rflag = false; //구멍에 빠졌는지
	bool bflag = false;

	//RED
	int nrx = rx + dx[dir];
	int nry = ry + dy[dir];

	while (1) {
		if (a[nrx][nry] == '#') break;
		if (a[nrx][nry] == 'O') {
			rflag = true;
			break;
		}
		nrx = nrx + dx[dir];
		nry = nry + dy[dir];

	}
	nrx = nrx - dx[dir];
	nry = nry - dy[dir];

	//BLUE
	int nbx = bx + dx[dir];
	int nby = by + dy[dir];

	while (1) {
		if (a[nbx][nby] == '#') break;
		if (a[nbx][nby] == 'O') {
			bflag = true;
			break;
		}
		nbx = nbx + dx[dir];
		nby = nby + dy[dir];
	}
	nbx = nbx - dx[dir];
	nby = nby - dy[dir];

	//RED, BLUE 이동 끝나고
	if (bflag == true) return;
	else {
		if (rflag == true) {
			if (ans > cnt) ans = cnt;
			return;
		}
	}

	if (nrx == nbx && nry == nby) { //둘의 위치가 같으면
		int rdist = move_dist(rx, ry, nrx, nry);
		int bdist = move_dist(bx, by, nbx, nby);
		if (rdist > bdist) { //파란색 공이 더 움직이는 시간이 짧았으면
			nrx = nrx - dx[dir];
			nry = nry - dy[dir];
		}
		else {
			nbx = nbx - dx[dir];
			nby = nby - dy[dir];
		}
	}

	for (int k = 0; k < 4; k++) {
		if (k == dir) continue; //같은방향 통과
		if (k == inverse_dir(dir)) continue; //반대방향으로 가면 그대로니깐
		go(nrx, nry, nbx, nby, cnt + 1, k);
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'R') {
				ri = i; rj = j;
				a[i][j] = '.';
			}
			else if (a[i][j] == 'B') {
				bi = i, bj = j;
				a[i][j] = '.';
			}
		}
	}

	for (int k = 0; k < 4; k++) {
		go(ri, rj, bi, bj, 1, k);
	}

	if (ans > 10 || ans == 987654321) ans = -1;

	cout << ans << '\n';
	return 0;
}
