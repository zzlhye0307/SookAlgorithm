#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    for(int i = 0 ; i < priorities.size() ; i++) q.push(i);

    int popped = -1;
    while(popped != location) {
        int max = *max_element(priorities.begin(), priorities.end());
        if(priorities[q.front()] < max) {
            q.push(q.front());
            q.pop();
        }else {
            popped = q.front();
            priorities[q.front()] = -1;
            q.pop();
            answer++;
        }
    }

    return answer;
}

//Ǯ�̹��
//queue�� �����Ͽ� ���� ��⿭�� �ִ� �����͵��� index�� �����Ѵ�.
//queue���� push�ϰ� pop�ϸ� �켱������� �����ϰ� �Ѵ�.