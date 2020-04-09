#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int solution(string arrangement) {
    
    stack<char> s;
    int answer=0;
    
    for(int i=0; i<arrangement.size(); i++){
        //레이저인 경우
        if(arrangement[i] == '(' && i+1< arrangement.size() && arrangement[i+1] == ')' ){ 
            i++;
            answer += s.size();
        }
        //쇠막대기 시작
        else if(arrangement[i] == '(' && i+1< arrangement.size() && arrangement[i+1] != ')' ){ 
            s.push('(');
        }
        //쇠막대기 끝
        else if(arrangement[i] == ')'){ 
            s.pop();
            answer++;
        }
    }
    return answer;
}
