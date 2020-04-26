풀이 방법
//dfs 알고리즘을 사용합니다.
//
//이 문제를 풀 때는
//- 벽 3개 세우기
//- 안전 영역 크기 구하기
//이 두 가지 기능을 수행해야합니다.
//두 기능 모두 dfs 알고리즘을 사용해 구현했습니다.
//
//먼저 벽을 3개 세우는 기능은,
//순차적으로 0인 칸에 대하여 벽을 세우고
//내가 세운 벽이 3개가 되었을 때
//안전 영역의 크기를 구하도록 합니다.
//이때, makeWall 함수에서 빠져나왔을 때
//세웠던 벽을 다시 빈 칸으로 만들어주는 작업을 수행해야합니다.
//
//안전 영역의 크기를 구하는 기능은,
//바이러스를 확산시키는 작업이 선행되어야 합니다.
//모든 칸을 순회하면서 바이러스가 있는 칸을 만났을 때,
//해당 칸의 상하좌우에 위치한 칸에도 바이러스를 전파하기 위해서,
//재귀함수를 실행합니다.
//
//  main.cpp
//  14502
//
//  Created by Jihye on 2020/04/26.
//  Copyright © 2020 Jihye Han. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m; // 행, 열의 크기
int map[8][8]; // 지도 - 0 : 빈 칸, 1 : 벽, 2 : 바이러스
int temp[8][8];
int ans = 0; // 안전 영역의 최대 크기
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void copyMap() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = map[i][j];
        }
    }
}

void spreadVirus(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];

        if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
            if (temp[tx][ty] == 0) {
                temp[tx][ty] = 2;
                spreadVirus(tx, ty);
            }
        }
    }
}

void countSafetyZone() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) count++;
        }
    }
    if (count > ans) ans = count;
}

void makeWall(int x, int y, int cnt) {
    // 벽을 3개 세웠을 때
    if (cnt == 3) {
        copyMap();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (temp[i][j] == 2) spreadVirus(i, j);
            }
        }
        countSafetyZone();
        return;
    }
    
    // 벽 세우기
    for (int i = x; i < n; i++) {
        for (int j = (i == x)? y : 0; j < m; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                makeWall(i, j, cnt + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    makeWall(0, 0, 0);
    printf("%d\n", ans);
    
    return 0;
}
