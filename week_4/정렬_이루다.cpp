#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    int i = 0;
    while(citations[i] <= citations.size()-i && i < citations.size()) {
        i++;
    }
    i--;   
    
    if(citations[i]==citations.size()-i) answer = citations[i];
    else answer = citations.size()-i-1;

    return answer;
}


/*
인용된 횟수가 그 이상으로 인용된 논문의 개수보다 커질때까지 index를 늘린다.
*/