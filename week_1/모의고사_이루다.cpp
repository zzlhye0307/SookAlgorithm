#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int count[3] ={0, 0 ,0};
    
    int one[5] = {1, 2, 3, 4, 5};
    int two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i = 0 ; i < answers.size() ; i++) {
        if(answers[i] == one[i%5]) count[0]++;
        if(answers[i] == two[i%8]) count[1]++;
        if(answers[i] == three[i%10]) count[2]++;
    }
    
    int max = *std::max_element(count,count+3);
    
    for(int i = 0 ; i<3 ; i++) {
        if(count[i] == max) answer.push_back(i+1);
    }
    return answer;
}

//Ǯ�̹��
//���� ������ ��Ŀ� �Է��Ͽ� ��� ����
//max_element : ���ڷ� �����ּҿ� ���ּ� ���� �ִ밪 return


