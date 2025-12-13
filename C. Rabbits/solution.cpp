#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int MOD = 1e9 + 7 ;


void solve(){
    int n ; cin >> n; 
    string s ; cin >> s ; 
    
    bool req = false ; 
    int prev = -1000 ; 
    
    for( int i=0 ; i<n ; ++i ){
        if( s[i] == '0' ){
            int curr = 1 ;
            int start = i ; 
            while( i+1<n && s[i+1] == '0' ){
                i++ ; 
                curr++ ; 
            }
            if( req ){
                if( prev != start-2 ){
                    cout << "NO\n" ; 
                    return ; 
                }
                req = false ; 
                if( curr > 1 ){
                    prev = i ; 
                }
            }else if( curr == 1 && i != 0 && i != n-1 ){
                if( prev != start - 2 ){
                    req = true ; 
                }
                prev = i ; 
            }else {
                prev = i ; 
            }
        }
    }
    cout << ( req ? "NO\n" : "YES\n" ) ; 
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
