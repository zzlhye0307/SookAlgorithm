#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int i;
    int j = 1;
    for(i = 1; i<=j ; i++) {
        j = red/i;
        if(red%i == 0 && (i+2)*(j+2)-red == brown) {
                answer.push_back(j+2);
                answer.push_back(i+2);
                break;
         }      
    }
    return answer;
}