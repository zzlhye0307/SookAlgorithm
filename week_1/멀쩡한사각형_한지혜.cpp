// 풀이 방법
// 1. W, H와 result에서의 규칙을 찾고 관계식을 성립한다.
// 2. 식에 필요한 연산(최대공약수 구하기)을 수행하는 함수(calculateGcd)를 생성한다.
// 3. calculateGcd에는 유클리드 알고리즘을 적용하여 Gcd를 계산한다.

#include <cstdio>

using namespace std;

int calculateGcd(int w, int h) {
    int temp;
    
    while (h != 0) {
        temp = w % h;
        w = h;
        h = temp;
    }
    
    return w;
}

long long solution(int w,int h)
{
	long long answer = 0;
    int gcd = 0;
    long long trash = 0;
    
    // w, h의 최대공약수 찾기
    gcd = calculateGcd(w, h);
    
    // trash 구하기
    trash = w + h - gcd;
    
    // answer 구하기
    answer = ((long long)w * (long long)h) - trash;
    
	return answer;
}
