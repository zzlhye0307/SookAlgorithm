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

//1. ���� �� ������ �����ϴ� �л���(n) ũ���� �迭 ����
//2. ���� ���� ������ 1 ������ 0 ���� ���� ���� ���� ������ -1 �����ϰ� �Ѵ�.
//3. -1�� ������ �յڷ� ���� ���� �ִ����� �˻��ϸ�, 
//	 �߰����� ������ �� count++, �߰����� �� ���� �� ���Ҹ� 0����