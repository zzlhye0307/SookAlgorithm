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

//풀이방법
//queue를 생성하여 현재 대기열에 있는 프린터들의 index를 저장한다.
//queue에서 push하고 pop하며 우선순위대로 진행하게 한다.