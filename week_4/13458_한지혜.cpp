//풀이방법
//주어진 조건을 그대로 구현하는 시뮬레이션 문제입니다.
//각 시험장에 필요한 감독관 수를 ans 변수에 더하여,
//전체 시험장에 필요한 최소 감독관 수를 출력합니다.
//
//for loop을 통해 각 시험장에 필요한 감독관 수를 계산합니다.
//총감독관과 부감독관을 나눠서 계산합니다.
//총감독관은 시험장마다 무조건 한 명씩 필요합니다.
//부감독관은 총감독관이 관찰하는 응시자들을 제외한 응시자들을 대상으로, 필요한 부감독관 명수를 계산합니다.
//
//이때, ans 변수의 데이터 타입을 int로 하면 오버플로우가 발생하므로 long 혹은 long long으로 지정해야 합니다.

//
//  main.cpp
//  13458
//
//  Created by Jihye on 2020/04/25.
//  Copyright © 2020 Jihye Han. All rights reserved.
//

#include <iostream>

using namespace std;

int n; // 시험장의 개수
int a[1000000]; // 응시자의 수
int b; // 총감독관이 한 시험장에서 감시할 수 있는 응시자의 수
int c; // 부감독관이 한 시험장에서 감시할 수 있는 응시자의 수
long ans = 0;

void solve() {
    for (int i = 0; i < n; i++) { // 각 시험장마다 감독관 배치하기
        // 총감독관 배치
        a[i] -= b;
        ans += 1;

        // 부감독관 배치
        if (a[i] > 0) {
            ans += (a[i] % c == 0)? a[i] / c : a[i] / c + 1;
        }
    }
    printf("%ld\n", ans);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d ", &a[i]);
    scanf("%d %d", &b, &c);

    solve();

    return 0;
}
