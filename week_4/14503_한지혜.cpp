//풀이 방법
//주어진 조건을 그대로 구현하는 시뮬레이션 문제입니다.
//
//로봇청소기가 청소한 영역과 청소하지 않은 영역을 구분하기 위해 isClean 배열을 사용합니다.
//청소한 영역은 true가, 청소하지 않은 영역은 false가 return 됩니다.
//단, 벽이 위치하는 영역은 true가 return 되도록 합니다.
//
//clean이라는 재귀함수를 이용하여 로봇청소기의 방향과 좌표를 조절합니다.

//
//  main.cpp
//  14503
//
//  Created by Jihye on 2020/04/26.
//  Copyright © 2020 Jihye Han. All rights reserved.
//

#include <iostream>

using namespace std;

int n, m; // 행, 열의 크기
int x, y; // 로봇청소기의 위치
int side; // 로봇청소기가 바라보는 방향 - 0 : 상, 1 : 우, 2 : 하, 3 : 좌
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int map[50][50];
int ans = 1; // 청소 횟수
int turn = 0; // 한 자리에서의 회전 횟수
bool isClean[50][50];

void clean() {
    // 네 방향 모두 청소가 되어있거나 벽일 때
    if (turn == 4) {
        // 후진 좌표 탐색
        int nside = (side <= 1)? side + 2 : side - 2;
        x += dx[nside];
        y += dy[nside];
        
        // 후진이 가능할 때
        if (0 <= x && x < n && 0 <= y && y < m && map[x][y] == 0) {
            turn = 0;
            clean();
        }
        
        return;
    }
    
    // 현재 위치 청소
    isClean[x][y] = true;
    
    // 왼쪽 방향으로 회전하고, 좌표 확인
    side = (side == 0)? 3 : side - 1;
    int nx = x + dx[side];
    int ny = y + dy[side];
    
    // 왼쪽 방향에 아직 청소하지 않은 공간 존재
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && isClean[nx][ny] == false) {
        x = nx;
        y = ny;
        turn = 0;
        ans++;
    } else { // 왼쪽 방향이 청소되었을 때
        turn++;
    }
    clean();
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &x, &y, &side);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 0) isClean[i][j] = false;
            else isClean[i][j] = true;
        }
    }
    clean();
    printf("%d\n", ans);
    
    return 0;
}
