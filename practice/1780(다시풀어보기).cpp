#include <iostream>
#include <algorithm>
using namespace std;

int result[3];
int map[2200][2200];

// 종이 내 모든 칸들이 모두 같은지 아닌지 판단하는 함수
bool check(int row, int col, int num) {
    // 시작점
    int start = map[row][col];
    for(int i = row; i < row + num; i++) {
        for(int j = col; j < col+num; j++) {
            if(start != map[i][j])
                return false;
        }
    }
    return true;
}

// 9분할로 나눠보는 함수
void divide(int row, int col, int num) {

    // 단위 종위 내 모든 칸들의 값이 같을 경우
    if(check(row, col, num)) {
        result[map[row][col]]++; // result list 에 1
    }

    else {
            // 새로운 단위사이즈를 만든다.
            int size = num / 3; 
            // 처음에 num 27이었다면 다음 단위 정사각형은 한 변의 길이 9

            for (int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    divide(row + size*i, col + size*j, size);
                }
            }
    }
}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int N;
cin >> N;

for(int i = 0; i < N; i ++) {
    for(int j = 0; j < N; j++) {
        int input;
        cin >> input;
        input++; // -1, 0, 1 을 0,1,2 로 표현하기 위해 사용
        map[i][j] = input;
    }
}
divide(0,0,N);
for(int i =0; i < 3; i++)
cout << result[i] << '\n';


}


// gpt: https://chat.openai.com/ - > Dividing Paper Problem

//물론, 재귀 호출의 동작을 하나씩 설명해드릴게요. 아래의 예시를 통해 설명하겠습니다. divide(0, 0, 9) 호출을 기준으로 설명하겠습니다.

// 1. divide(0, 0, 9) 호출이 시작됩니다.
// 2. check(0, 0, 9) 함수를 호출하여 9x9 종이의 모든 칸이 같은 숫자인지 확인합니다. 모든 칸이 같지 않다면 분할을 수행합니다.
// 3. 새로운 단위 크기 size를 계산합니다. 여기서는 9 / 3 = 3입니다.
// 4. 이제 for 루프가 시작됩니다. 루프에서 i와 j가 각각 0, 1, 2로 변하며 divide 함수가 재귀 호출됩니다.
// 5. 첫 번째 반복에서 divide(0, 0, 3)이 호출됩니다.
// 6. 이 함수 내부에서 다시 for 루프가 시작되어 i와 j가 0, 1, 2로 변하며 divide 함수가 세 번 더 재귀 호출됩니다. 각 호출은 서로 다른 시작 좌표 (row, col)에 해당합니다.
// 7. 이러한 과정으로 인해 divide(0, 0, 3) 내에서 총 9번의 재귀 호출이 스택에 쌓이게 됩니다. 각각의 호출은 각각의 시작 좌표 (row, col)와 함께 저장됩니다.
// 8. 이제 가장 안쪽의 divide 함수부터 실행되기 시작합니다. 스택 맨 위의 호출부터 실행됩니다.
// 9. 첫 번째 호출에서 check 함수가 호출되어 3x3 크기의 종이 내의 칸이 같은 숫자인지 확인합니다. 칸이 같지 않다면 또 다시 분할을 수행하게 됩니다.
// 10. 같은 숫자가 아닐 때 for 루프를 통해 다시 9개의 divide 함수가 재귀 호출되며 스택에 쌓입니다.
// 11. 위 과정을 반복하여 가장 작은 단위인 1x1 종이에 도달하게 됩니다.
// 12. 1x1 종이의 check 함수와 result 업데이트가 실행됩니다.
// 13. 이제 가장 작은 종이부터 하나씩 스택에서 반환되면서 호출이 종료됩니다. 스택 맨 위부터 순차적으로 반환됩니다.
// 14. 각 호출이 반환되면서 이전 호출의 다음 코드가 실행됩니다.
// 15. 모든 호출이 종료되면 초기 호출인 divide(0, 0, 9)로 돌아가서 for 루프 이후의 코드가 실행됩니다.
// 16. 결과 배열 result가 출력됩니다.
// 이러한 방식으로 재귀 호출이 실행되며, 스택을 통해 호출의 순서가 관리됩니다. 
// 각 호출이 끝날 때까지 기다리는 게 아니라, 호출된 함수들이 스택에 쌓이고 반환되면서 실행 흐름이 진행됩니다.


// 내 친구가 재귀안에 for문 쓰지 말랬음