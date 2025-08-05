#include <bits/stdc++.h>
using namespace std;

int main(void) {   // 한글자니까 char 이용
    ios::sync_with_stdio(0);
    cin.tie(0);
    string init;
    cin >> init;
    list<char> L;
    for(auto c : init) L.push_back(c);
    list<char>::iterator cursor = L.end();
    int s;
    cin >> s;
   while(s--) {
    char edit;
    cin >> edit;
   if(edit == 'L') {
    if(cursor != L.begin()) 
        cursor--;
   }
   if(edit == 'D') {
     if(cursor != L.end()) 
        cursor++;
   }
    if(edit == 'B') {
     if(cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);
        // 삭제 후 cursor 위치(iterator가 가리키는 위치)에는 현재 빈 공간이므로 cursor는 길을 잃게 됩니다.
        // 그러나 'B' 커맨드 이후 cursor의 오른쪽 문자는 그대로 여야 하므로 cursor를 erase가 반환하는 값으로 맞춰줍니다.
     }
   }
    if(edit == 'P') {
    char add;
    cin >> add;
    L.insert(cursor,add);
   }
   }
for (auto c : L) cout << c;
return 0;
}

