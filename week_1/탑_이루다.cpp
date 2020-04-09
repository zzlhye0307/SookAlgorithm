#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> s;
    
   
    for (int i = heights.size() -1 ; i>=0 ; i-- ) {
        int num = heights[i];
        int flag = 0;
        for(int j = i-1; j>=0 ; j--) {
            if(heights[j] > num)  {
                s.push(j+1);
                flag = 1;
                break;
            }
        }
        if(flag == 0) s.push(0);
    }
    
    while(s.empty()==0) {
        answer.push_back(s.top());
        s.pop();
    }
        
    return answer;

//Ǯ�̹��
//�ش� �ε����� ž �Ʒ��� �� ���� ž�� ������ stack�� �� index�� �߰��ϰ�
//������ ���ϸ� stack�� 0�� �߰��Ѵ�.