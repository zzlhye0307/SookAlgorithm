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

//Ǯ�̹��
//��� ���Ҹ� Ž���Ѵ�.
//find : string�� ����ִ��� ã��, ��ġ�� 0�̸� false�� �ٷ� �����Ѵ�.
//ã�� ���� false�� �������� ���ϸ� true ����