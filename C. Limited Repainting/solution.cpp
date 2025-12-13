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

bool check( string &s , vector<ll> &arr , int n , int k , ll tar ){
    int cost = 0 ;
    for( int i=0 ; i<n ; ++i ){
        if( s[i] == 'B' && arr[i] > tar ){
            cost++ ; 
            while( i+1<n ){
                if( s[i+1] == 'R' && arr[i+1] > tar ){
                    break ; 
                }else {
                    i++ ; 
                }
            }
        }
    }
    
    return cost <= k ; 
}

void solve(){
    int n ; cin >> n ; 
    int k ; cin >> k ; 
    string s ; cin >> s ; 
    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    
    ll l = 0 ; 
    ll r = LLONG_MAX ; 
    while( l < r ){
        ll mid = l + ( r - l )/2 ; 
        if( check( s , arr , n , k , mid )){
            r = mid ; 
        }else {
            l = mid +  1; 
        }
    }
    cout << l << '\n' ;  
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
