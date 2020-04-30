#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int i = 0;
    priority_queue<int> q;
    
    while(stock < k) {
        while(stock-dates[i] >=0) {
            q.push(supplies[i]);
            i++;
        }
        
        stock += q.top();
        q.pop();
        answer++;
        
    }
    
    return answer;
}

/*
������ stock���� �а��縦 ���� �� �ִ� ��¥ dates[i]���� �ߵ� �� �ִ� 
�ִ� ��¥�� �ö����� ��� queue�� ���޷��� push �Ѵ�.

�а��簡 ���������� ��¥�� �Ǿ��� ��, �а��縦 ���� ���� ���� �� �ִ� ����
�а��縦 ���޹ް� �Ѵ�.

stock�� 30���� �ߵ� �� �ְ� �ɶ����� �ݺ��Ѵ�.
*/