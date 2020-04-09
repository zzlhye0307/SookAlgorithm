#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    int clothes[n];
    int count = 0;
    
    for(int i=0 ; i<n ; i++) clothes[i] = 0;
    for(int i=0 ; i<reserve.size() ; i++)  clothes[reserve[i]-1]++;
    for(int i=0 ; i<lost.size() ; i++) clothes[lost[i]-1]--;  
    
    for(int i=0 ; i<n ; i++) {
        if(clothes[i] == -1) {
            if(i-1>=0 && clothes[i-1] == 1) clothes[i-1] = 0;
            else if(i+1<n && clothes[i+1] == 1) clothes[i+1] = 0;
            else count++;
        }
    }
    
    
    
    int answer = n-count;
    
    return answer;
}

//1. 여분 옷 개수를 저장하는 학생수(n) 크기의 배열 생성
//2. 여분 옷이 있으면 1 없으면 0 도난 당해 입을 옷이 없으면 -1 저장하게 한다.
//3. -1일 때마다 앞뒤로 여분 옷이 있는지를 검사하며, 
//	 발견하지 못했을 시 count++, 발견했을 시 여분 옷 원소를 0으로