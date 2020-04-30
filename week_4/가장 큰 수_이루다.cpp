#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool fun(string a, string b) {
    if(a+b > b+a) return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for(int i = 0; i < numbers.size() ; i++) {
        v.push_back(to_string(numbers[i]));
    }
    
    sort(v.begin(), v.end(), fun);
    
    if(v[0]=="0") return "0";
    for(int i = 0; i<v.size() ; i++) {
        answer+=v[i];
    }
    
    return answer;
}


/*
sort 기준 함수 fun의 재정의
*/