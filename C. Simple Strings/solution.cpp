#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void helper(string &s, int in, int count) {
    if (count % 2 == 1) {
        for (int i = in + 1; i < in + count; i += 2) {
            if (s[i-1] == 'a') {
                s[i] = 'b';
            } else if (s[i-1] == 'b') {
                s[i] = 'a';
            } else {
                s[i] = 'a';
            }
        }
    } else {
        for (int i = in; i < in + count; i += 2) {
            char prev = (i > 0) ? s[i-1] : ' ';
            char next = (i+1 < s.size()) ? s[i+1] : ' ';
            
            if (prev != 'a' && next != 'a') {
                s[i] = 'a';
            } else if (prev != 'b' && next != 'b') {
                s[i] = 'b';
            } else {
                s[i] = 'c';
            }
        }
    }
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    for (int i = 0; i < n; ++i) {
        int start = i;
        int count = 1;
        while (i + 1 < n && s[i+1] == s[i]) {
            i++;
            count++;
        }
        if (count > 1) {
            helper(s, start, count);
        }
    }
    
    cout << s << endl;
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}