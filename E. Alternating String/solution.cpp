#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

ll mod = 1e9 + 7 ; 

bool isGood( string &s , int idx , int pref  , char a , char b ){
    if( idx % 2 == pref ){
        return s[idx] == a ; 
    }    
    return s[idx] == b ; 
}

void solve() {
    int n ; cin >> n ; 
    string s ; cin >> s ; 
    if( n % 2 == 0 ){
        int ans = n ; 
        for( char i = 'a' ; i<='z' ; i += 1 ){
            for( char j = 'a' ; j<='z' ; j += 1 ){
                int curr = 0 ; 
                for( int k=0 ; k<n ; ++k ){
                    curr += !isGood( s , k , 0 , i , j ) ; 
                }
                ans = min( ans , curr ) ; 
            } 
        }
        cout << ans << '\n' ; 
    }else if( n == 1 ){
        cout << 1 << '\n' ;    
    }else {
        int ans = n ;
        vector<int> pref(n,0) ; 
        vector<int> suff( n , 0 ) ;
        for( char a = 'a' ; a <= 'z' ; a += 1 ){
            for( char b = 'a' ; b <= 'z' ; b += 1 ){
                pref[0] = !isGood( s , 0 , 0 , a , b ) ; 
                for( int i=1 ; i<n ; ++i ){
                    pref[i] = pref[i-1] + ( !isGood( s , i , 0 , a , b ) ) ; 
                }
                suff[n-1] = !isGood( s , n-1 , 1 , a , b ) ; 
                for( int i=n-2 ; i>=0 ; --i ){
                    suff[i] = suff[i+1] + ( !isGood( s , i , 1 , a , b ) ) ; 
                }
                ans = min( ans , pref[n-2] + 1 ) ; 
                ans = min( ans , suff[1] + 1 ) ; 
                for( int i=1 ; i<n-1 ; ++i ){
                    ans = min( ans , pref[i-1] + suff[i+1] + 1 ) ; 
                }
            }
        
        }
        cout << ans << '\n'; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
