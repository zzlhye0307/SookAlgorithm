// 풀이방법
// 주어진 조건을 그대로 구현하는 시뮬레이션 문제입니다.
// 뱀의 좌표를 queue에 저장하는 것이 핵심입니다.
// 1초가 지날 때 마다,
// 뱀의 머리가 이동할 좌표를 queue에 push하고
// 사과의 여부에 따라 뱀의 꼬리 좌표를 queue에서 pop할지 결정합니다.
// 
// 뱀의 머리를 이동하기 전에, 이동할 좌표가
// 1) 벽을 넘어가는지
// 2) 뱀의 몸이 속한 좌표와 일치하는지
// 여부를 확인해서 게임이 몇 초 안에 끝나는지 출력합니다.

//
//  main.cpp
//  3190
//
//  Created by Jihye on 2020/04/24.
//  Copyright © 2020 Jihye Han. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct turn {
    int sec;
    char side;
};

struct location {
    int i;
    int j;
};

int n; // 보드의 크기
int k; // 사과의 개수
int l; // 뱀의 변환 횟수
int sec = 0; // 현재까지 지난 시간
int side; // 현재 뱀의 머리가 향하고 있는 방향
int i, j; // 머리 옮겨질 위치
queue<location> snake; // 뱀 몸
queue<turn> snakeTurn; // 뱀의 회전 정보
bool isApple[100][100] = { false }; // 해당 좌표에 사과가 위치하는지
bool isSnake[100][100] = { false }; // 해당 좌표에 뱀이 위치하는지

void move() {
    
    // 머리 옮기기
    switch (side) {
        case 0: // 상
            i = snake.back().i - 1;
            j = snake.back().j;
            break;
        
        case 1: // 우
            i = snake.back().i;
            j = snake.back().j + 1;
            break;
            
        case 2: // 하
            i = snake.back().i + 1;
            j = snake.back().j;
            break;
            
        case 3: // 좌
            i = snake.back().i;
            j = snake.back().j - 1;
            break;
    }
}

void checkApple() {
    if (isApple[i][j]) { // 사과 있으면 꼬리 안 옮김
        isApple[i][j] = false;
    } else { // 사과 없으면 꼬리 옮김
        location front = snake.front();
        isSnake[front.i][front.j] = false;
        snake.pop();
    }
}

void checkTurn() {
    if (snakeTurn.front().sec == sec) {
        if (snakeTurn.front().side == 'L') { // 왼쪽 회전
            side = (side == 0)? 3 : side - 1;
        } else { // 오른쪽 회전
            side = (side == 3)? 0 : side + 1;
        }
        snakeTurn.pop();
    }
}

void solve() {
    while (true) {
        // 1초씩 증가
        sec += 1;
        
        // 움직일 위치 확인
        move();
        
        // 제한 조건 확인 - 벽에 부딪혔는지, 자기 몸에 부딪혔는지
        if (i < 0 || i >= n || j < 0 || j >= n || isSnake[i][j]) {
            printf("%d\n", sec);
            return;
        }
        
        // 머리 옮기기
        snake.push({i, j});
        isSnake[i][j] = true;
        
        // 사과 확인
        checkApple();
        
        // 회전 정보 확인
        checkTurn();
    }
}

int main() {
    
    scanf("%d", &n);
    scanf("%d", &k);
    
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        isApple[x - 1][y - 1] = true;
    }
    
    scanf("%d", &l);
    
    for (int i = 0; i < l; i++) {
        int sec;
        char side;
        scanf("%d %c", &sec, &side);
        snakeTurn.push({sec, side});
    }
    
    // 뱀의 처음 위치와 방향 설정
    snake.push({0, 0});
    side = 1;
    isSnake[0][0] = true;
    
    solve();
    
    return 0;
}
