// 풀이방법
//다이나믹 프로그래밍 기법을 사용해 문제를 해결합니다.
//DP 문제를 풀 때에는 점화식을 세우는 게 좋습니다.
//
//이 문제의 점화식은 solve 함수의 for loop에 해당합니다.
//수익이 상담이 마쳐진 다음날 들어온다고 가정했을 때,
//dp[i]은 i번째 날에 가질 수 있는 최대 금액입니다.
//
//각 loop은 먼저 i번째 날에 일을 했을 경우를 계산합니다.
//i번째 날에 일을 했을 경우엔 i + t[i] 날에 수익이 들어옵니다.
//따라서 dp[i + t[i]]을 새롭게 계산해줍니다.
//그리고 다음 loop으로 넘어가기 전에,
//i번째 날에 가진 수익이 i+1번째 날에 가진 수익보다 많을 수 있으므로,
//dp[i + 1]을 새롭게 계산해줍니다.

//  main.cpp
//  14501
//
//  Created by Jihye on 2020/04/26.
//  Copyright © 2020 Jihye Han. All rights reserved.
//

#include <iostream>

using namespace std;

int n; // 주어진 날짜
int t[16]; // 상담을 완료하는데 걸리는 기간
int p[16]; // 상담을 했을 때 받을 수 있는 금액
int dp[16]; // 해당 날짜에 가질 수 있는 최대 금액
int ans = 0; // 최대 수익

void solve() {
    // dp 수행
    for (int i = 1; i <= n; i++) {
        // i번째 날에 일할 때
        if (dp[i + t[i]] <= n + 1) {
            dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
            ans = max(ans, dp[i + t[i]]);
        }
        
        // i번째 날에 일하지 않을 때
        dp[i + 1] = max(dp[i + 1], d[i]);
        ans = max(ans, dp[i + 1]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &t[i], &p[i]);
    }
    solve();
    printf("%d\n", ans);
    return 0;
}
