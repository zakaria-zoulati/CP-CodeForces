#include <bits/stdc++.h>

using namespace std;

using ll = long long ; 

void solve(){
  int n ; cin >> n ; 
  string s; cin >> s ; 
  
  if( n % 2 == -1 ){
      cout << "-1\n" ; 
  }else {
    int a = 0 ; 
    int b = 0 ; 
    for( char c : s ){
        if( c == ')' ){
            a++  ; 
        }else {
            b++ ; 
        }
    }
    
    if( a==b ){
        vector<int> curr(n,0) ;
        curr[0] = ( s[0] == '(' ? 1 : -1 ) ; 
        for( int i=1 ; i<n ; ++i ){
            if( s[i] == '(' ){
                curr[i] = curr[i-1] + 1 ; 
            }else {
                curr[i] = curr[i-1] - 1 ;  
            }
        }
        int pos = 0 ; 
        int neg = 0 ; 
        for( int i=0 ; i<n ; ++i ){
            if( curr[i] == 0 ){
                pos++ ; 
                neg++ ; 
            }else if( curr[i] > 0 ){
                pos++ ; 
            }else {
                neg++ ; 
            }
        } 
        if( pos == n || neg == n ){
            cout << "1\n" ; 
            for( int i=0 ; i<n ; ++i ){
                cout << 1 << " " ;
            }
            cout << '\n' ; 
        }else {
            cout << "2\n" ; 
            vector<int> color(n,1) ;
            int l = 0 ; 
            int r = n-1 ; 
            while( l < r ){
                if( s[l] == '(' ){
                    l++ ; 
                }else if( s[r] == ')' ){
                    r-- ; 
                }else {
                    color[l] = 2 ; 
                    color[r] = 2 ; 
                    l++ ; r-- ; 
                }
            }
            for( int i=0 ; i<n ; ++i ){
                cout << color[i] << " " ; 
            }
            cout << '\n' ; 
        }
        
    }else {
        cout << "-1\n" ;  
    }
  }
  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
