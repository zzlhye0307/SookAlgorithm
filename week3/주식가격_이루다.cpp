#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    

    for(int i=0 ; i<prices.size()-1 ; i++)  {
        int n=1;
        for(int j=i+1 ; prices[i]<=prices[j] && j< prices.size()-1 ; j++) {
            n++;
        }
        answer.push_back(n);
    }
    answer.push_back(0);
    
    
    
    return answer;
}