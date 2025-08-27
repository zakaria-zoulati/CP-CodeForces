#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long ; 

ll mod = 1e9 +7 ; 

vector<ll> dp( 40'001 , 0  ) ; 

bool isPal( int n ){
    int rs = n ; 
    int rev = 0 ; 
    while( n > 0 ){
        rev = rev*10 + n % 10 ; 
        n /= 10 ; 
    }
    return rs == rev ; 
}

void precompute(){
    dp[0] = 1 ; 
    vector<int> palindromes ; 
    for( int i=1; i<40'001 ; ++i ){
        if( isPal(i) ){
            palindromes.push_back( i ) ; 
        }
    }
    for( int j : palindromes ){
        for( int i=j ; i<40'001 ; i++ ){
            dp[i] = ( dp[i] + dp[i-j] ) % mod ; 
        }
    }
}


void solve(){
    int n ; cin >> n ; 
    cout << dp[n] << '\n' ;     
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute();

    int t ; cin >> t ; 
    while( t-- ){
       solve() ; 
    }
    return 0;
}