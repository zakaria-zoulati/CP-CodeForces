#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;


vector<bool> isPrime( 1'000'001 , true ) ; 


void precompute(){
    isPrime[1] = false ; 
    for( ll i=2 ; i<1'000'001 ; ++i ){
        if( isPrime[i] ){
            for( ll j=i*i ; j<1'000'001 ; j += i ){
                isPrime[j] = false ; 
            }
        }
    } 
}

void solve() {
    int n , e ; 
    cin >> n >> e ;  
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    vector<int> pref( n , 0 ) ; 
    for( int i=0 ; i<n ; ++i ){
        if( arr[i] == 1 ){
            pref[i] = 1 ; 
            if( i - e >= 0 ){
                pref[i] += pref[i-e] ; 
            }
        }
    }
    vector<int> suff(n , 0 ) ; 
    for( int i=n-1 ; i>=0 ; --i ){
        if( arr[i] == 1 ){
            suff[i] = 1 ; 
            if( i + e < n ){
                suff[i] += suff[i+e] ; 
            }
        }
    }
    ll rs = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( isPrime[ arr[i] ] ){
            ll a = i-e>=0 ? pref[i-e] : 0 ; 
            ll b = i+e<n  ? suff[i+e] : 0 ; 
            rs += (a+1)*(b+1) - 1 ; 
        }
    }
    cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    precompute() ; 
    
    int t = 1 ;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
