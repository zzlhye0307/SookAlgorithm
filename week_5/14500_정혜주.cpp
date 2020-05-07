//[백준 14500번] 6번 테트로미노

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[501][501];
int block[19][3][2] = {
	{{0,1}, {0,2}, {0,3}},
	{{1,0}, {2,0}, {3,0}},
	{{1,0}, {1,1}, {1,2}},
	{{0,1}, {1,0}, {2,0}},
	{{0,1}, {0,2}, {1,2}},
	{{1,0}, {2,0}, {2,-1}},
	{{0,1}, {0,2}, {-1,2}},
	{{1,0}, {2,0}, {2,1}},
	{{0,1}, {0,2}, {1,0}},
	{{0,1}, {1,1}, {2,1}},
	{{0,1}, {1,0}, {1,1}},
	{{0,1}, {-1,1}, {-1,2}},
	{{1,0}, {1,1}, {2,1}},
	{{0,1}, {1,1}, {1,2}},
	{{1,0}, {1,-1}, {2,-1}},
	{{0,1}, {0,2}, {-1,1}},
	{{0,1}, {0,2}, {1,1}},
	{{1,0}, {2,0}, {1,1}},
	{{1,0}, {2,0}, {1,-1}},
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 19; k++) {
				int sum = a[i][j];
				int flag = 0;
				for (int l = 0; l < 3; l++) {
					int nx = i + block[k][l][0];
					int ny = j + block[k][l][1];
					if (0 <= nx && nx < n && 0 <= ny && ny < m) {
						sum += a[nx][ny];
					}
					else {
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					if (ans < sum) ans = sum;
				}
				
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
