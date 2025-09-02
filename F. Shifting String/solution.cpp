#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;

ll gcd( ll a , ll b ){
    while( b != 0 ){
        int t = a%b ; 
        a = b ; 
        b = t ; 
    }
    return a ; 
}

ll lcm( ll a , ll b ){
    return ( a / gcd(a,b) )*b ; 
}

ll helper( vector<int> &a , string &s ){
    int len = a.size() ;
    for( int i=1 ; i<=len ; ++i ){
        bool fl = true ; 
        for( int j=0 ; j<len ; ++j ){
            if( s[a[j]] != s[a[(i+j)%len]] ){
                fl = false; 
                break ; 
            }
        }
        if( fl ){
            return i ;
        }
    }
    return -1 ; 
}

void solve() {
   int n ; cin >> n ; 
   string  s ; cin >> s ; 
   vector<int> p(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> p[i] ; 
       p[i]-- ; 
   }
   ll rs = 1 ; 
   vector<bool> seen( n , false ) ; 
   for( int i=0 ; i<n ; ++i ){
       if( !seen[i] ) {
            vector<int> curr ;
            int ele = i ;            
            while( !seen[ele] ){ 
                curr.push_back(ele) ; 
                seen[ele] = true ; 
                ele = p[ele] ; 
            }
            rs = lcm( rs , helper(curr,s)  ) ; 
       }
   }
   cout << rs << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1 ; 
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}