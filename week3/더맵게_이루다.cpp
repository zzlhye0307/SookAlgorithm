#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int n, m;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 0; i<scoville.size(); i++){
        q.push(scoville[i]);
    }
    
    while(q.top() < K && q.size() > 1) {
        n = q.top(); q.pop();
        m = q.top(); q.pop();
        q.push(n+2*m);
        answer++;
    }
    if(q.top()<K) return -1;
    return answer;
}



//priority_queue사용의 이해