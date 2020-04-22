#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> s;
    vector<int> l;
    char c;
    
    
    for(int i=0 ; i<arrangement.length() ; i++ ) {
        if(arrangement[i] == '(') {
            s.push('(');
            l.push_back(0);
        }else {
            if(arrangement[i-1] == '(') {       //레이저인 경우
                s.pop();
                l.pop_back();
                for(int j=0 ; j<l.size() ;j++) {
                    l[j]++;
                }
            }else {                               //막대인 경우
                answer += l.back()+1;
                l.pop_back();
                s.pop();
            }
        }
        
    }
   
    
    return answer;
}


//풀이방법
//(이면 stack에 하나씩 저장하고, )를 만날때마다 막대인지 레이저인지 확인하며 pop하면서 answer에 더하는 방식