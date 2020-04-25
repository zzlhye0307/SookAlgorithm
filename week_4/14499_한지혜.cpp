//풀이 방법
//주어진 조건을 그대로 구현하는 시뮬레이션 문제입니다.
//주어진 명령들에 따라서 지도 위에 있는 주사위를 굴립니다.
//
//- 명령에 의해 주사위가 위치할 x, y 좌표 구하기
//- 주사위가 지도에서 넘어가는 명령인지 확인하기
//- 주사위 굴려 주사위 숫자 변경하기
//- 지도, 주사위 숫자 변경하기
//
//위 네가지 기능을 명령 개수만큼 반복합니다.
//
//주사위를 굴려 주사위 숫자를 변경할 때, dice와 temp라는 배열을 사용합니다.
//dice 배열은 주사위 6면에 적힌 숫자들을 저장합니다.
//temp 배열은 주사위 굴리기 직전의 dice 배열을 저장합니다.
//dice[0]은 주사위 윗면에 적힌 숫자를,
//dice[1]은 주사위 앞면에 적힌 숫자를,
//dice[2]은 주사위 오른쪽면에 적힌 숫자를,
//dice[3]은 주사위 뒷면에 적힌 숫자를,
//dice[4]은 주사위 왼쪽면에 적힌 숫자를,
//dice[5]은 주사위 아랫면에 적힌 숫자를 의미합니다.
//
//만약 주사위가 위쪽으로 굴러갔을 경우,
//주사위 윗면에 적힌 숫자는 굴러가기 전 주사위의 앞면에 적힌 숫자가 될 것입니다.
//따라서 dice[0] = temp[1] 가 되어야합니다.
//이처럼 윗면을 포함한 6개의 면의 숫자들을 변경해줘야합니다.
//주사위가 굴러가는 방향에 따라서 주사위 숫자 변경 방식이 달라지므로,
//direction이라는 2차원 배열에 주사위 숫자 변경 방식을 저장하여 사용합니다.

//
//  main.cpp
//  14499
//
//  Created by Jihye on 2020/04/25.
//  Copyright © 2020 Jihye Han. All rights reserved.
//

#include <iostream>

using namespace std;

int n, m; // 지도의 행, 열 크기
int x, y; // 주사위 놓은 곳의 좌표
int k; // 명령의 개수
int board[20][20]; // 지도에 쓰여 있는 수
int dice[6], temp[6]; // 주사위 숫자 저장

const int direction[4][6] = {
    {4, 1, 0, 3, 5, 2}, // 우
    {2, 1, 5, 3, 0, 4}, // 좌
    {1, 5, 2, 0, 4, 3}, // 상
    {3, 0, 2, 5, 4, 1} // 하
};

const int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

void solve() {
    while (k--) {
        // 명령 하나씩 수행
        int command; // 상하좌우
        scanf("%d", &command); command--;

        // x, y 이동
        x += dx[command]; y += dy[command];

        // 지도에서 넘어가는 명령인지 확인
        if ( x < 0 || x >= n || y < 0 || y >= m) {
            x -= dx[command]; y -= dy[command];
            continue;
        }

        // 주사위 굴리기 이전의 주사위 숫자 저장
        for (int i = 0; i < 6; i++) {
            temp[i] = dice[i];
        }
        
        // 주사위굴린 후의 주사위 숫자 저장
        for (int i = 0; i < 6; i++) {
            dice[i] = temp[direction[command][i]];
        }
        
        // 지도 정보 저장, 주사위 숫자 변경
        if (board[x][y]) { // 주사위 놓은 칸에 쓰여있는 숫자가 0이 아닐 때
            dice[5] = board[x][y];
            board[x][y] = 0;
        } else { // 주사위 놓은 칸에 쓰여있는 숫자가 0일 때
            board[x][y] = dice[5];
        }
        
        // 주사위 윗 면에 쓰여있는 숫자 출력
        printf("%d\n", dice[0]);
    }
}

int main() {
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    solve();

    return 0;
}
