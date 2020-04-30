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
현재의 stock으로 밀가루를 받을 수 있는 날짜 dates[i]까지 견딜 수 있는 
최대 날짜가 올때까지 계속 queue에 공급량을 push 한다.

밀가루가 부족해지는 날짜가 되었을 때, 밀가루를 가장 많이 받을 수 있는 날에
밀가루를 공급받게 한다.

stock이 30일을 견딜 수 있게 될때까지 반복한다.
*/