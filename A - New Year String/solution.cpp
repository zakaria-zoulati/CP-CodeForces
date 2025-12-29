#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x) 

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int MOD = 1e9 + 7 ;



void solve( ){
    int n ; cin >> n  ; 
    string s ; cin >> s ;
    for( int i=0 ; i+3<n ; ++i ){
        if( s[i] == '2' && s[i+1] == '0' && s[i+2] == '2' && s[i+3] == '6'  ){
            cout << "0\n" ; 
            return ; 
        }
    }
    for( int i=0 ; i+3<n ; ++i ){
        if( s[i] == '2' && s[i+1] == '0' && s[i+2] == '2' && s[i+3] == '5'  ){
            cout << "1\n" ; 
            return ; 
        }
    }
    cout << "0\n" ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
