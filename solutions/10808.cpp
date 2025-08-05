#include <iostream>
#include <string>
using namespace std;


// 풀이 1
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(char a = 'a'; a <= 'z'; a++) {
        int cnt = 0;
        for(auto c : s) // auto + range based for 문 -> 배열 출력할떄 사용, 
        // 시작과 끝점을 알려주지 않아도 알아서 처음부터 끝까지 선회하는 반복문
        // auto c 는 s의 자료형에 자동으로 맞춰주는거
        // c = s[0], c = s[1] 이런식으로 c배열에 복사되어서 출력되는거임
        if( a == c) cnt ++;
        cout << cnt << ' ';
    }
}
// 풀이 1은 문자열 s를 26번 반복해서 확인하는 코드


// 풀이 2

int freq[26]; // freq 배열의 초기값은 0이어야 할텐데 전역에 선언하면 알아서 0으로 채워지니 따로 초기화 x
// freq가 지역변수 였다면 int freq[26]; 이렇게 선언시 0이아닌 다른 쓰레기 값이 채워지기 때문에 int freq[6] = {} 
// 혹은 fill(freq,freq+26,0); 과 같은 조치가 필요
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(auto c : s)
     freq[c-'a']++;
    for(int i = 0; i < 26; i++)
     cout << freq[i] << ' ';
}
// 배열의 모든 그릇의 값이 0으로 초기화된 freq 배열에 36번째줄을 이용하여 해당하는 글자가
// 있으면 ++ -> 즉 해당 그릇에 +1을 시켜준후 출력

