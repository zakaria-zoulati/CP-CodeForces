#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
#include <utility>
#include <stack>
#include <sstream>

using namespace std;
using ll = long long;

ll getCount(int n, int pos) {
    ll rs = 0; 
    while (pos > 0) {
        rs += n--; 
        pos--; 
    }
    return rs; 
}

bool check(ll pos, int n, int tar) {
    ll curr = getCount(n, tar); 
    return pos <= curr; 
}

stringstream rs ; 

void solve() {
    string s; cin >> s;
    ll pos; cin >> pos; 
    int n = s.size(); 
    int l = 1; 
    int r = n ; 
    while (l < r) {
        int mid = l + (r - l) / 2; 
        if (check(pos, n, mid)) {
            r = mid; 
        } else {
            l = mid + 1;
        }
    } 
    if (l == 1) {
        rs << s[pos-1] ; 
    } else {
        vector<bool> removed(n, false); 
        stack<int> st;
        pos -= getCount(n, l - 1); 
        int t = l - 1; 
        st.push(0); 
        for (int i = 1; i < n; ++i) {
            while( !st.empty() &&  t>0 ) {
                int prev = st.top() ; 
                if( s[prev] <= s[i] ) break ; 
                st.pop(); 
                removed[prev] = true; 
                t--; 
            }
            st.push(i) ; 
            if (t == 0) break; 
        }
        while (t-- > 0) {
            int prev = st.top(); st.pop(); 
            removed[prev] = true; 
        }
        for (int i = 0; i < n; ++i) {
            if (removed[i]) continue; 
            pos--; 
            if (pos == 0) {
                rs << s[i];  
                return ; 
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    cout << rs.str() ; 
    return 0;
}
