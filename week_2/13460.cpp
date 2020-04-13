//
//  main.cpp
//  13460
//
//  Created by Jihye on 2020/04/04.
//  Copyright © 2020 Jihye Han. All rights reserved.
//

//풀이방법
//bfs 알고리즘을 통해 해결
//bead 구조체를 선언한 이유는 queue에 넣기 위함이다.
//주의사항은 빨간 구슬과 파란 구슬이 같은 칸에 존재할 수 없기 때문에, 각 구슬이 이동한 거리를 계산하여 예외처리를 해줘야한다.

#include <iostream>
#include <queue>

using namespace std;

struct bead {
    int rx, ry, bx, by, d;
}; // rx, ry : 빨간 구슬 좌표 | bx, by : 파란 구슬 좌표 | d : 기울인 횟수

int m, n; // 열, 행의 개수
char map[10][10]; // 보드 모양 나타냄
bool check[10][10][10][10]; // 방문 여부 파악
queue<bead> q; // 빨간구슬, 파란구슬의 좌표 나타냄
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}; // dx : 좌우로 기울이기 | dy : 상하로 기울이기

void move(int &x, int &y, int &c, int dx, int dy) {
    // 구슬 굴리기 전에, 구슬의 다음 위치가 벽인지, 구슬의 현재 위치가 구멍인지 확인
    // c : 한 번 기울였을 때 구슬이 이동한 칸 수
    while (map[x+dx][y+dy] != '#' && map[x][y] != 'O') {
        x += dx;
        y += dy;
        c += 1;
    }
}

void bfs() {
    while (!q.empty()) {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int d = q.front().d;

        q.pop();

        if (d >= 10) break;

        for (int i = 0; i < 4; i++) {
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            int rc = 0, bc = 0, nd = d+1;

            move(nrx, nry, rc, dx[i], dy[i]); // 구슬 굴리기
            move(nbx, nby, bc, dx[i], dy[i]); // 구슬 굴리기

            if (map[nbx][nby] == 'O') continue; // 파란 공이 구멍에 들어갔을 경우
            if (map[nrx][nry] == 'O') { // 빨간 공이 구멍에 들어갔을 경우
                printf("%d\n", nd);
                return;
            }

            if (nrx == nbx && nry == nby) { // 구슬이 겹쳤을 경우
                // 굴릴 때, 이동 거리가 더 긴 구슬의 위치를 한 칸 이전으로 되돌림
                if (rc > bc) nrx -= dx[i], nry -= dy[i];
                else nbx -= dx[i], nby -= dx[i];
            }

            if (check[nrx][nry][nbx][nby]) continue; // 이미 방문 했던 칸일 경우
            check[nrx][nry][nbx][nby] = true;
            q.push({nrx, nry, nbx, nby, nd});
        }
    }

    printf("-1\n");
}

int main() {
    scanf("%d %d", &n, &m);
    int rx = 0, ry = 0, bx = 0, by = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%s", &map[i][j]);
            if (map[i][j] == 'R') rx = i, ry = j;
            else if (map[i][j] == 'B') bx = i, by = j;
        }
    }

    q.push({rx, ry, bx, by, 0});
    check[rx][ry][bx][by] = true;
    bfs();

    return 0;
}
