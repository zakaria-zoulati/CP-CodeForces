#include <bits/stdc++.h>

#define all(x) begin(x) , end(x) 

using namespace std;
using ll = long long ; 

void solve(){
    int n ; cin >> n ; 
    vector<tuple<int,int,int>> pairs(n) ; 
    for( int i=0 ; i<n ; ++i ){
        int start , end ; 
        cin >> start >> end ; 
        pairs[i] = { end , -start , i+1 } ;  
    }
    sort( all(pairs) ) ; 
    int start = -get<1>( pairs[n-1] ) ; 
    int idx = get<2>( pairs[n-1] ) ;
    for( int i=n-2 ; i>=0 ; --i ){
        int curr_start = -get<1>( pairs[i] ) ; 
        int curr_idx = get<2>( pairs[i] ) ; 
        if( curr_start < start ){
            start = curr_start ; 
            idx = curr_idx ; 
        }else {
            cout << curr_idx << " " << idx << '\n' ; 
            return ; 
        }
    }
    cout << -1 << " " << -1 << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 
    
    int t = 1 ; 
    while( t-- ){
       solve() ; 
    }
}
