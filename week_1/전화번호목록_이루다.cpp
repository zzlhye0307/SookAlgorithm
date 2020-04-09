#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    int pos = 1;
    for(int i = 0 ; i<phone_book.size() ; i++) {
        for(int j = 0 ; j<phone_book.size() ; j++) {
            if(i != j ) {
                int pos = phone_book[j].find(phone_book[i]);
                if(pos == 0) return false;
            }
        }
    }
    return true;
}

//풀이방법
//모든 원소를 탐색한다.
//find : string이 들어있는지 찾고, 위치가 0이면 false를 바로 리턴한다.
//찾지 못해 false를 리턴하지 못하면 true 리턴