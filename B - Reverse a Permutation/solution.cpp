#include <bits/stdc++.h>


using namespace std;

using ll = long long ; 
using ld = long double ; 

using vi = vector<int> ; 
using vvi = vector<vi> ; 
using vvvi = vector<vvi> ; 

ll mod = 998'244'353 ; 

void reverse( vector<int> &p , int i , int j ){
    while( i < j ){
        swap( p[i] , p[j] ) ; 
        i++ ; j-- ; 
    }
}

void solve() {
   int n ; cin >> n ; 
   vector<int> p(n) ; 
   for( int i=0 ; i<n ; ++i ){
    cin >> p[i] ; 
   }
   int curr = n ; 
   for( int i=0 ; i<n && curr > 0 ; ++i ){
     if( p[i] != curr ){
        for( int j=i+1 ; j<n ; ++j ){
            if( p[j] == curr ){
                reverse( p , i , j ) ; 
                curr = -1 ; 
            }
        }
     }
     curr-- ; 
   }

   for( int i=0 ; i<n ; ++i ){
    cout << p[i] << " " ; 
   }
   cout << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}