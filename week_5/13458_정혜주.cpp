//[백준 13458번] 4번 시험 감독
/*
	총감독관은 한반에 1명만 가능
	그럼 부감독관이 나머지를 메꿔야 됨.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {


	int n; //시험장 개수
	cin >> n;
	vector<int> a(n + 1); //응시자 수
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int b, c;
	long long cnt = 0;
	cin >> b >> c;
	for (int i = 0; i < n; i++) {
		int temp;
		temp = a[i] - b;
		cnt++;
		if (temp > 0) {  //이 경우 생각 잘하기..
			if ((temp%c) == 0) {
				cnt += (temp / c);
			}
			else {
				cnt += (temp / c) + 1;
			}
		}

	}
	cout << cnt << '\n';

	return 0;
}
