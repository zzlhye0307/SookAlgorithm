// 풀이 방법
//재귀함수를 이용하여 문제를 해결합니다.
//
//이 문제는 팀 나누기, 각 팀의 능력치 구하기 두 기능을 수행해야 합니다.
//이를 위해 solve, calculateTA 함수를 만들어 각 기능을 구현했습니다.
//
//solve 함수에서는 특정 사람(idx)이 스타트팀인지 아닌지를 기준으로,
//재귀함수를 실행합니다.
//idx가 스타트팀일 때는 스타트팀원의 수를 뜻하는 startTeamNum을 하나 증가시켜 재귀함수를 실행하고,
//idx가 스타트팀이 아닐 때는 startTeamNum을 증가시키지 않은 채로 재귀함수를 실행합니다.
//
//모든 팀원을 다 검사했을 경우엔 재귀함수의 실행을 멈추고,
//팀원 배정이 1:1로 되었을 경우엔 각 팀을 능력치를 구한 뒤 재귀함수의 실행을 멈춥니다.
//
//calculateTA에선 각 팀의 능력치를 구하고,
//능력치의 차를 계산하여,
//두 팀의 능력치 차이의 최솟값을 계산하는 역할을 합니다.

//
//  main.cpp
//  14889
//
//  Created by Jihye on 2020/04/28.
//  Copyright © 2020 Jihye Han. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int n; // 인원 수
int ability[20][20]; // 능력치
int team[20]; // 각 인원이 속한 팀 - 0 : start, 1 : link
int minDiff = 2e9; // 차이의 최솟값

// 팀 나누기 - solve
// 스타트 팀, 링크 팀의 능력치 각각 구하기 - calculateTA

void calculateTA() {
    int startTeamAbility = 0; // startTeam 능력치
    int linkTeamAbility = 0; // linkTeam 능력치
    
    // 팀 능력치 구하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (team[i] == 0 && team[j] == 0) startTeamAbility += ability[i][j];
            else if (team[i] == 1 && team[j] == 1) linkTeamAbility += ability[i][j];
        }
    }
    
    // 팀 능력치 비교하기
    minDiff = min(minDiff, abs(startTeamAbility - linkTeamAbility));
}

void solve(int idx, int startTeamNum) {
    // 모든 인원 다 배정했을 때
    if (idx == n) return;
    
    // 팀원 배정 마치면
    if (startTeamNum == n/2) {
        calculateTA();
        return;
    }
    
    // idx가 startTeam일 때, startTeam 배정하기
    team[idx] = 0;
    solve(idx + 1, startTeamNum + 1);
    
    // idx가 startTeam 아닐 때, startTeam 배정하기
    team[idx] = 1;
    solve(idx + 1, startTeamNum);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &ability[i][j]);
        }
        team[i] = 1;
    }
    solve(0, 0);
    printf("%d\n", minDiff);
    return 0;
}
