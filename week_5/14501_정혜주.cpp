//[백준 14501번] 7번 퇴사

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int n;
int t[20];
int p[20];
int ans;

void solve(int day, int sum) {
	
	if (day == n) {
		if (ans < sum) ans = sum;
		return;
	}

	if (day > n) {
		return;
	}
	solve(day + 1, sum); //선택안하고
	solve(day + t[day], sum + p[day]); //선택하곤
	

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}
	solve(0, 0); //초기값 day=0, sum=0;
	
	cout << ans << '\n';

	return 0;
}
