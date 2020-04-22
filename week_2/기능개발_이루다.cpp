#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for(int i  = 0 ; i < progresses.size() ; i++) {
        q.push(i);
    }

    while(q.size() != 0) {
        int num = 0;

        for(int i = 0 ; i < progresses.size() ; i++) {
            progresses[i] += speeds[i];
        }

        if(progresses[q.front()] >= 100) {
            while(progresses[ q.front() ] >= 100 && q.size()!=0) {
                q.pop();
                num++;
            }
            answer.push_back(num);
        }


    }
    return answer;
}

