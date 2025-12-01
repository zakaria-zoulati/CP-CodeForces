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
    ll n  ; cin >> n ; 
    ll sum = n*(n+1)/2 ; 
   
    ll curr ;
    cout << 2 << " " << 1 << " " << n << '\n' ; 
    cout.flush() ; 
    cin >> curr ; 
    
    int len = curr - sum ; 
    
    ll a ; 
    ll b ; 
    cout << 1 << " " << 1 << " " << 1 << '\n' ;
    cout.flush() ; 
    cin >> a ; 
    cout << 2 << " " << 1 << " " << 1 << '\n' ; 
    cout.flush() ; 
    cin >> b ; 
    
    if( a != b ){
        cout << "! " << 1 << " " << 1 + len - 1 << " " << '\n' ; 
        cout.flush() ; 
        return ; 
    }
    
    
    int l = 2; 
    int r = n ; 
    while( l < r ){
        int mid = l + ( r - l )/2 ; 
        ll prev1 ; 
        cout << 1 << " " << 1 << " " << mid << '\n' ; 
        cout.flush() ; 
        cin >> prev1 ; 
        ll prev2 ; 
        cout << 2 << " " << 1 << " " << mid << '\n' ; 
        cout.flush() ; 
        cin >> prev2 ; 
        

        if( prev1 == prev2 ){
            l = mid + 1 ; 
        }else {
            r = mid ; 
        }
    }
    
    cout << "! " << l << " " << l + len - 1 << '\n' ; 
    cout.flush() ; 
    
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
