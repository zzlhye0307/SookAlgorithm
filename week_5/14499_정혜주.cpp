//[백준 14499번] 5번 주사위 굴리기

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

//주사위 굴리는게 관건

int map[21][21];
int dice[7]; //초기 주사위
int ndice[7]; //바뀔 주사위
int n;
int m;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool go_ok(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return false;
	}
	else return true;
}
int main() {
	int x, y, k;
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		//주사위를 굴렸을때
		//1)이동한 칸이 0이면 주사위의 바닥면에 쓰여있는 수가 칸에 복사됨
		//2)0이 아니면 칸에 쓰여있는 수가 주사위의 바닥면으로 복사됨. 
		//칸은 0으로 바뀜.
		int direction = 0;
		cin >> direction;

		int nx = x + dx[direction - 1];
		int ny = y + dy[direction - 1];

		if (!go_ok(nx, ny)) continue;

		if (direction == 4) { //남쪽
			ndice[1] = dice[2];
			ndice[2] = dice[6];
			ndice[6] = dice[5];
			ndice[5] = dice[1];
			ndice[3] = dice[3];
			ndice[4] = dice[4];
		}
		else if (direction == 3) { //북쪽
			ndice[1] = dice[5];
			ndice[5] = dice[6];
			ndice[6] = dice[2];
			ndice[2] = dice[1];
			ndice[3] = dice[3];
			ndice[4] = dice[4];
		}
		else if (direction == 2) { //서쪽
			ndice[1] = dice[3];
			ndice[3] = dice[6];
			ndice[6] = dice[4];
			ndice[4] = dice[1];
			ndice[2] = dice[2];
			ndice[5] = dice[5];
		}
		else if (direction == 1) { //북쪽
			ndice[3] = dice[1];
			ndice[1] = dice[4];
			ndice[4] = dice[6];
			ndice[6] = dice[3];
			ndice[2] = dice[2];
			ndice[5] = dice[5];
		}

		if (map[nx][ny] == 0) {
			map[nx][ny] = ndice[6];
		}
		else {
			ndice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}
		cout << ndice[1] << '\n';

		//변경된 사항 저장
		for (int i = 0; i < 7; i++) {
			dice[i] = ndice[i];
		}
		x = nx;
		y = ny;
	}
	return 0;
}
