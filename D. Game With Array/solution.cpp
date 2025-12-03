#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int mod = 1e9 + 7 ;


void solve( ){
    int n ; cin >> n ; 
    int s ; cin >> s ; 

    if( s >= 2*n ){
        cout << "YES\n" ; 
        for( int i=0 ; i<n-1 ; ++i ){
            cout << 2 << " " ; 
        }
        cout << s - 2*(n-1) << '\n'  ;
        cout << "1\n" ; 
    }else {
        cout << "NO\n"; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int t = 1 ; 
    while( t-- ){
       solve() ; 
    }
}
