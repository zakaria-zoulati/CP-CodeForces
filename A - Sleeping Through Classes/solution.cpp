#include <bits/stdc++.h>

using namespace std;

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int MOD = 1e9 + 7 ;



void solve( ){
    int n ; cin >> n ; 
    int k ; cin >> k ; 
    string s ; cin >> s ; 
    int ans = 0;
    int max = -1 ;  
    for( int i=0 ; i<n ; ++i ){
        if( s[i] == '1' ){
            max = i + k ; 
        }else if(i > max ){
            ans++ ; 
        }
    }
    cout << ans << '\n' ; 
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
