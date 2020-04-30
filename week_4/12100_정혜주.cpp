//[백준 12100번] 2번 2048 (Easy)
/*
	4x4크기의 보드
	전체 보드의 블록이 움직이며
	같은 값을 가진 두 블록이 충돌하면 하나로 합쳐짐
	이미 합쳐진 블록은 또 다른 블록과 합쳐질 수 없음
	최대 5번 이동해서 만들수 있는 가장 큰 블록의 값을 구하는 프로그램.

	0인 경우도 고려해야 함.
	쭉 끝까지 이동함.
	똑같은 수가 세개 있으면 이동하려는 쪽의 칸이 먼저 합쳐진다.
*/
	//중복순열을 통해 방향 설정

/*
	dfs를 통해서 완전탐색을 하는 경우임.
	!!이미 합쳐진 블록은 다시 합쳐지지 않는다는 조건을 생각해야함!!
*/

//테스트케이스: https://www.acmicpc.net/board/view/14579
//또다른 tc: https://www.acmicpc.net/board/view/30217

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 21
int n;
int ans;
int a[MAX][MAX];
bool visit[MAX][MAX];

void move(int dir){

	queue<int> q;

	//row:i(세로로 커짐), col:j(가로로 커짐)
	if (dir == 0) { //up
		for (int j = 0; j < n; j++) { //차근히 늘어나는 행
			for (int i = 0; i < n; i++) { //늘어나는 열(0,0)(1,0)..
				if (a[i][j] != 0) {
					q.push(a[i][j]);
					a[i][j] = 0;
				}
			} //한 행만 보고 큐를 쓴다.
			int idx = 0; //늘어나는 인덱스
			while (!q.empty()) {
				int block = q.front();
				q.pop();
				if (a[idx][j] == 0) { //j는 고정.
					//여기서 배열에 한번 값을 넣음.
					a[idx][j] = block;
				}
				else if (visit[idx][j] == false && a[idx][j] == block) {
					a[idx][j] *= 2; //다시 넣은 배열값하고 큐가 같으면 2배
					visit[idx][j] = true;
					idx++;
				}
				else {
					a[++idx][j] = block;
				}

			}
		}
		memset(visit, false, sizeof(visit)); //한 방향 다 하고나면 초기화
	}
	else if (dir == 1) { //down 
		for (int j = 0; j < n; j++) {
			for (int i = n - 1; i >= 0; i--) {
				if (a[i][j] != 0) {
					q.push(a[i][j]);
					a[i][j] = 0;
				}
			}
			int idx = n - 1;
			while (!q.empty()) {
				int block = q.front();
				q.pop();
				if (a[idx][j] == 0) {
					a[idx][j] = block;
				}
				else if (visit[idx][j] == false && a[idx][j] == block) {
					a[idx][j] *= 2;
					visit[idx][j] = true;
					idx--;
				}
				else {
					a[--idx][j] = block;
				}
			}
		}
		memset(visit, false, sizeof(visit));
	}
	else if (dir == 2) { //left
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) { //(0,0),(0,1)
				if (a[i][j] != 0) {
					q.push(a[i][j]);
					a[i][j] = 0;
				}
			}
			int idx = 0;
			while (!q.empty()) {
				int block = q.front();
				q.pop();
				if (a[i][idx] == 0) {
					a[i][idx] = block;
				}
				else if (visit[i][idx] == false && a[i][idx] == block) {
					a[i][idx] *= 2;
					visit[i][idx] = true;
					idx++;
				}
				else {
					a[i][++idx] = block;
				}
			}
		}
		memset(visit, false, sizeof(visit));
	}
	else if (dir == 3) {  //right
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (a[i][j] != 0) {
					q.push(a[i][j]);
					a[i][j] = 0;
				}
			}
			int idx = n - 1;
			while (!q.empty()) {
				int block = q.front();
				q.pop();
				if (a[i][idx] == 0) {
					a[i][idx] = block;
				}
				else if (visit[i][idx] == false && a[i][idx] == block) {
					a[i][idx] *= 2;
					visit[i][idx] = true;
					idx--;
				}
				else {
					a[i][--idx] = block;
				}
			}
		}
		memset(visit, false, sizeof(visit));
	}
}

void dfs(int cnt) { //중복순열

	if (cnt == 5) { //최대 5번
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ans < a[i][j]) ans = a[i][j];
			}
		}
		return;
	}

	
	int temp[MAX][MAX]; //여기에 선언
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = a[i][j]; //temp에 원본 담아줌.
		}
	}
	
	for (int k = 0; k < 4; k++) {

		move(k); //모든 방향으로 바꾼 경우 탐색
		dfs(cnt + 1); //위위위위위... 중복순열 완전탐색 cnt가 5가 될때까지 감.
		//총 5번 다 돌고나서 담아놨던 원본 다시 a배열로.
		for (int i = 0; i < n; i++) { 
			for (int j = 0; j < n; j++) {
				a[i][j] = temp[i][j]; 
			}
		}
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	dfs(0);

	cout << ans << '\n';
	
	return 0;
}
