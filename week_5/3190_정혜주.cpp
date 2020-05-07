//[백준 3190번] 3번 뱀
/*
	사과를 먹으면 뱀 길이가 늘어남
	처음 뱀은 오른쪽 방향
	1)뱀은 몸길이를 늘려 머리를 다음칸에 위치시킴
	2)만약 이동한 칸에 사과가 있다면, 사과가 없어지고 꼬리는 움직이지x
	3)사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워줌.

	x초가 끝난뒤에 L왼쪽으로 90도, D오른쪽으로 90도
	queue를 활용해서 꼬리 지우는 거 구현
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, k, l;
int cnt, ans;
int r, c;
int a[101][101];
vector<pair<int, char>> v;

//오른쪽 아래쪽 왼쪽 위쪽
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	cin >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 0; //지도 초기화
		}
	}
	a[0][0] = 2; //뱀 초기위치

	int row, col;
	for (int i = 0; i < k; i++) {
		cin >> row >> col;
		a[row - 1][col - 1] = 1; //사과 표시
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int num; char ch;
		cin >> num >> ch;
		v.push_back(make_pair(num, ch));
	}

	/*
		queue로 꼬리....머리 순으로 좌표를 쌓음.
		head는 계속 갱신해서 움직이는 뱀 머리 좌표를 넣음.
	*/
	queue<pair<int, int>> snake;
	pair<int, int> head = { 0, 0 };
	snake.push(make_pair(0, 0)); //초기값
	
	int idx = 0; //처음 오른쪽 방향이므로 1
	int vidx = 0; //vector의 인덱스
	while (true) {

		cnt++;

		int nx = head.first + dx[idx]; //뱀의 머리가 이동
		int ny = head.second + dy[idx];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) break; //벽이면 게임끝
		else if (a[nx][ny] == 2) break;  //뱀이면 게임끝
		
		else if (a[nx][ny] == 1) { //사과면
			a[nx][ny] = 2; //뱀으로 늘리고
			snake.push(make_pair(nx, ny));
		}
		else if (a[nx][ny] == 0) { //아무것도 아니면
			a[snake.front().first][snake.front().second] = 0; //꼬리 짜르고
			snake.pop();  //큐에서 꼬리 빼기
			a[nx][ny] = 2; //뱀으로 늘리고
			snake.push(make_pair(nx, ny));
		}
		head = { nx, ny }; //뱀머리 갱신

		//진행방향 찾기
		if (vidx < l && v[vidx].first == cnt) { //시간이 같아지면
			//오른쪽 아래쪽 왼쪽 위쪽
			char ch = v[vidx].second;
			if (ch == 'D') {
				idx = (idx + 1) % 4;
			}
			else if (ch == 'L') {
				idx = (idx + 3) % 4;
			}
			vidx++;

		}
		
		
	}
	cout << cnt << '\n';
	return 0;
}
