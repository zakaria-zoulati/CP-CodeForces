#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

ll mod = 998244353 ; 

void solve(){
    int n , m ; 
    cin >> n >> m ; 
    
    priority_queue<int> alice , bob ; 
    for( int i=0 ; i<n ; ++i ){
        int ai ; cin >> ai ; 
        alice.push(ai) ; 
    }  
    for( int i=0 ; i<m ; ++i ){
        int bi ; cin >> bi ; 
        bob.push(bi) ; 
    }
    
    int alice_turn = 1 ; 
    while( true ){
        if( alice_turn ){
            int x = alice.top() ;
            int y = bob.top() ; bob.pop() ; 
            if( x >= y ){
                if( bob.empty() ){
                    cout << "Alice\n" ; 
                    return ; 
                }
            }else {
                bob.push( y - x ) ; 
            }
        }else {
            int x = bob.top() ;
            int y = alice.top() ; alice.pop() ; 
            if( x >= y ){
                if( alice.empty() ){
                    cout << "Bob\n" ; 
                    return ; 
                }
            }else {
                alice.push( y - x ) ; 
            }            
        }
        alice_turn ^= 1 ; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 
    
    int t = 1 ;
    cin >> t;  
    while( t-- ){
      solve() ; 
    }
}
