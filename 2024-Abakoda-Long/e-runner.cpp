#include <bits/stdc++.h>
#include "e.cpp"

int main() {
    init();

    string test = "TTFFTFTFTFTFTTTFTFTFFFTFFFTFTTTFTFTFTFTFFFFFFFTFTFTFTFTFTFTFTFTFTFTFTFTFTFTFTFTFFFFFFTTTTTFFFFFTTTTT";
    string res = decode(encode(test));
    
    int ans = 0;

    for (int i = 0; i < 100; i++) { ans += (test[i] == res[i]); }
    
    cout << test << endl;
    cout << res << endl;
    cout << ans << endl;

    return 0;
}