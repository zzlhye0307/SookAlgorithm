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
            if(arrangement[i-1] == '(') {       //�������� ���
                s.pop();
                l.pop_back();
                for(int j=0 ; j<l.size() ;j++) {
                    l[j]++;
                }
            }else {                               //������ ���
                answer += l.back()+1;
                l.pop_back();
                s.pop();
            }
        }
        
    }
   
    
    return answer;
}


//Ǯ�̹��
//(�̸� stack�� �ϳ��� �����ϰ�, )�� ���������� �������� ���������� Ȯ���ϸ� pop�ϸ鼭 answer�� ���ϴ� ���