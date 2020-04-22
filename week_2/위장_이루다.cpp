#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {

    map<string, int> hmap;
    int answer = 1;

    for(int i=0 ; i<clothes.size() ; i++) {
        hmap[clothes[i][1]]++;
    }

    map<string, int>::iterator iter;
    for(iter = hmap.begin(); iter != hmap.end(); iter++) {
        answer *= iter->second+1;		//���� �ʴ� ��� +1 �ؼ� �����ֱ�
    }

    answer--; //��� ������ �ƹ��͵� ���� �ʴ� ���� ����


    return answer;
}

//map.begin, map.end
//map<>::iterator
//map[]++


 