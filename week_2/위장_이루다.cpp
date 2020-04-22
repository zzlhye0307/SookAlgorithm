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
        answer *= iter->second+1;		//입지 않는 경우 +1 해서 곱해주기
    }

    answer--; //모든 부위에 아무것도 입지 않는 경우는 제외


    return answer;
}

//map.begin, map.end
//map<>::iterator
//map[]++


 