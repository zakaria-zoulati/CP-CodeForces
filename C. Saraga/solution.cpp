#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

void solve() {
    string s ; cin >> s ; 
    string t ; cin >> t ; 
    int n = s.size() ; 
    int m = t.size() ; 
    vector<int> f_t(26,-1) ; 
    for( int i=0 ; i<m-1 ; ++i ){
        int in = t[i] - 'a'; 
        f_t[in] = i ; 
    }
    string rs = s + t ; 
    bool fl = true ; 
    for( int i=1 ; i<n ; ++i ){
        int in = s[i] - 'a' ; 
        int next = f_t[in] ; 
        if( next == -1 ) continue ; 
        int len = i + ( m - next ) ; 
        if( len >= rs.size() ) continue  ;
        string curr = s.substr( 0 , i ) + t.substr( next , m ) ; 
        if( curr.size() < rs.size() ){
            rs = curr ; 
            fl =  false ; 
        }
    }
    if( fl ){
        cout << -1 << endl ; 
    }else {
        cout << rs << endl ;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
