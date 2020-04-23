// 풀이방법
// 게임 '2048'을 구현하는 문제입니다.
// 이 문제를 구현할 때,
// 1. 상하좌우로 움직이기 (move 함수 생성)
// 2. 숫자 블록 합치기 (merge 함수 생성)
// 두 단계로 나눠서 생각하면 좋습니다.

// 상하좌우로 움직이는 것은 dfs 알고리즘을 사용합니다.
// 이 때, 백트래킹을 할 때 사용하기 위하여 temp라는 배열을 두었고 memcpy라는 함수를 활용했습니다.
// move 함수에서는 각 행 또는 각 열을 queue에 넣는 작업을 수행합니다.
    
// 그 다음으로 숫자 블록을 합칠 때는 move 함수에서 만든 queue를 이용합니다.
// queue에서 합쳐지거나 빠져나온 숫자 블록들은 board에 반영됩니다.

//
//  main.cpp
//  12100
//
//  Created by Jihye on 2020/04/15.
//  Copyright © 2020 Jihye Han. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int n = 0;
int ans = 0;
int board[20][20];
int temp[20][20];
queue<int> q;

void get(int i, int j) {
    if (temp[i][j] != 0)
        q.push(temp[i][j]);
    
    temp[i][j] = 0;
}

void merge(int i, int j, int side) {
    int index = 0, front;
    
    while (!q.empty()) {
        front = q.front();
        q.pop();
        
        if (front == q.front()) {
            switch (side) {
                case 0: // 상
                    temp[index][j] = front * 2; break;
                case 1: // 하
                    temp[19 - index][j] = front * 2; break;
                case 2: // 좌
                    temp[i][index] = front * 2; break;
                case 3: // 우
                    temp[i][19 - index] = front * 2; break;
            }
            
            q.pop();
            index++;
        }
    }
}

void move(int side) {
    switch (side) {
        case 0: // 상
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < n; i++) {
                    get(i, j);
                }
                merge(0, j, side);
            }
            break;
            
        case 1: // 하
            for (int j = 19; j > 19 - n; j--) {
                for (int i = 19; i > 19 - n; i--) {
                    get(i, j);
                }
                merge(0, j, side);
            }
            break;
            
        case 2: // 좌
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    get(i, j);
                }
                merge(i, 0, side);
            }
            break;
            
        case 3: // 우
            for (int i = 19; i < 19 - n; i--) {
                for (int j = 19; j < 19 - n; j--) {
                    get(i, j);
                }
                merge(i, 0, side);
            }
            break;
    }
}

void sync() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = board[i][j];
        }
    }
}

int find() {
    int max = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (temp[i][j] > max) max = temp[i][j];
        }
    }
    
    return max;
}

void dfs(int count) {
    if (count == 4) {
        sync();
        ans = max(ans, find());
        return;
    }

    for (int i = 0; i < 4; i++) {
        printf("count : %d, i : %d\n",  count, i);
        move(i);
        dfs(count + 1);
    }
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    
    sync();
    dfs(0);
    printf("%d", ans);
    
    return 0;
}
