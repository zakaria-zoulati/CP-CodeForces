#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;
using vll = vector<ll>; 
using vvll = vector<vll>; 
using vvvll = vector<vvll>; 

ll mod = 1e9 + 7 ; 

int isValid( string &s , int m , int d ){
    for( int i=0 ; i<s.size() ; i++ ){
        if( i % 2 == 1 && s[i] - '0' != d ) {
            return 0 ; 
        }else if( i % 2 == 0 && s[i] - '0' == d ){
            return 0 ; 
        }
    }
    ll ans = 0 ; 
    ll pow = 1;  
    
    for( int i=s.size()-1; i>=0 ; --i ){
        ans = ( ans + ( s[i] - '0' )*pow ) % m ; 
        pow = ( pow * 10 ) % m ; 
    }
    return ans == 0 ; 
}   

ll helper( string &s , int m , int d ){
    int n=s.size() ; 
    if( n == 1 ){
        int l = s[0]-'0' ;
        int ans = 0 ;  
        for( int i=0 ; i<=l ; ++i ){
            if( i == d ) continue ; 
            if( i % m == 0 ){
                ans++ ; 
            }
        }
        return ans ; 
    }



    int pos = n % 2 ;
    int rem = d % m ; 
    reverse( all(s) ) ; 

    vvvll dp( n , vvll( m , vll( 2 , 0 ) ) ) ; 
    if( pos == 0 ){
        dp[0][rem][0] = 1 ; 
        if( d <= s[0] - '0' ){
            dp[0][rem][1] = 1 ; 
        }
    }else {
        for( int i=0 ; i<=9 ; ++i ){
            if( i == d ) continue ; 
            dp[0][i%m][0]++ ; 
            if( i <= ( s[0] - '0' ) ){
                 dp[0][i%m][1]++ ; 
            }
        }
    }

    ll p = 10;  

    for( int i=1 ; i<n ; ++i ){
        int f = ( i == n-1 ? 1 : 0 ) ;  
        if( i % 2 == pos ){

            for( int j=0 ; j<m ; ++j ){
                dp[i][(j+rem*p)%m][0] = ( dp[i][(j+rem*p)%m][0] + dp[i-1][j][0] ) % mod ; 
            }
            if( s[i] - '0' == d ){
                for( int j=0 ; j<m ; ++j ){
                    dp[i][(rem*p+j)%m][1] = ( dp[i][(rem*p+j)%m][1] + dp[i-1][j][1] ) % mod ; 
                }
            }else if( s[i] - '0' > d ){
                for( int j=0 ; j<m ; ++j ){
                    dp[i][(rem*p+j)%m][1] = ( dp[i][(rem*p+j)%m][1] + dp[i-1][j][0] ) % mod ; 
                }
            }

        }
        else {
            
            for( int j=0 ; j<=9 ; ++j ){
                if( j == d ) continue ; 
                for( int k=0 ; k<m ; ++k ){
                    dp[i][(j*p+k)%m][0] = ( dp[i][(j*p+k)%m][0] + dp[i-1][k][0] ) % mod ; 
                }
            }

            int l = ( s[i] - '0' ) ; 
            for( int j=f ; j<l ; ++j ){
                if( j == d ) continue ; 
                for( int k=0 ; k<m ; ++k ){
                    dp[i][(j*p+k)%m][1] = ( dp[i][(j*p+k)%m][1] + dp[i-1][k][0] ) % mod ; 
                }
            }
            if( l != d ){
                for( int j=0 ; j<m ; ++j ){
                    dp[i][(l*p+j)%m][1] = ( dp[i][(l*p+j)%m][1] + dp[i-1][j][1] ) % mod ;
                }
            }

        }

        p = ( p * 10 ) % m ; 
    }
    return dp[n-1][0][1] ; 
}

void solve(){
    int m ; cin >> m ; 
    int d ; cin >> d ; 

    string a , b ; 
    cin >> a >> b ;
    
    
    ll x = helper(b,m,d) ; 
    ll y = helper(a,m,d) ; 
    reverse( all(a) ) ; 

    ll ans = ( x - y + isValid(a,m,d) + mod ) %  mod ;  
    
    cout << ans << '\n' ; 
}

int main() {

    int t=1 ;
    while(t--){
        solve();
    }
    return 0;
}