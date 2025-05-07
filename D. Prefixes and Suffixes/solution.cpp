#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

vector<int> z_function(string s) {
    int n = (int) s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve() {
    string s ; cin >> s ; 
    int n = s.size() ; 
    vector<int> Z = z_function(s) ; 
    int k = 1 ;
    for( int i=1 ; i<n ; ++i ){
        if( Z[i] == n-i ){
            k++ ; 
        }
    }
    cout << k << endl ; 
    vector<ll> f( n , 0 ); 
    vector< int > result ; 
    for( int i=1 ; i<n ; ++i ){
        f[ Z[i] ]++  ;
        if( Z[i] == n - i ){
            result.push_back( n-i ) ;
        }
    }
    for( int i=n-2 ; i>=1 ; --i ){
        f[i] += f[i+1] ; 
    }
    for( int i=result.size()-1 ; i>=0 ; --i ){
        cout << result[i] << " " << f[ result[i] ] + 1 << endl ; 
    }
    cout << n << " " << 1 << endl ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
