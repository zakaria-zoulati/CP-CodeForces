#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check2( string s , int k , int in ){
    int n = s.size() ; 
    int count = 0 ; 
    for( int i=(in%k) ; i < n ; i += k ){
        if( s[i] == s[in] ){
            count++ ; 
        }
    }
    if( count == ( (s.size()/k) -1 ) ){
        return true ; 
    }else if( count == 1 ){
        return check2( s , k , in + k ) ; 
    }
    return false ; 
}

bool check( string s , int k ){
    int n = s.size() ; 
    int in = -1 ; 
    for( int i=k ; i<n ; i++ ){
        int j = i%k ; 
        if( s[j] != s[i] ){
            if( in == -1 ){
                in = j ; 
            }else if( j != in ){
                return false ;
            }
        }
        
    }
    if( in == -1 ) return true ; 
    return check2( s , k , in ) ; 
}

void solve() {
   int n ; cin >> n ; 
   string s ; cin >> s ;
   if( n <= 2 ){
       cout << 1 << endl ; 
       return ; 
   }
   if( check( s , 1 ) ){
       cout << 1 << endl ; 
       return ; 
   }
   int rs = n ; 
   for( int i=2 ; i*i<=n ; ++i ){
       if( n % i != 0 ) continue ; 
       if( check( s , i ) ){
           rs = min( rs , i ) ; 
       }
       if( check( s , n/i ) ){
           rs = min( rs , n/i ) ; 
       }
   } 
   cout << rs << endl ;
}

int main() {
    int t ; cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}
