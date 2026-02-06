#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

int sol1( vi &a , vi &b , int n ){
    vvi f( 2 , vi( n+1 , 0 ) ) ; 
    for( int i=n-1 ; i>=0 ; --i ){
        f[ i%2 ][ a[i] ]++ ; 
        f[ 1 - i%2 ][ b[i] ]++ ; 
        if( f[0][a[i]] > 0 && f[1][ a[i] ] > 0 ){
            return i+1 ; 
        }
        if( f[0][b[i]] > 0 && f[1][ b[i] ] > 0 ){
            return i+1 ; 
        }
    }
    return  0 ; 
}

int util( vi &seq , int n ){
    vi f( n+1 , -1 ) ; 
    for( int i=n-1 ; i>=0 ; --i ){
        if( f[ seq[i] ] > i+1 ){
            return i+1 ; 
        }   
        if( f[ seq[i] ] == -1 ){
            f[ seq[i] ] = i ; 
        }
    }
    return 0 ; 
}

int sol2( vi &a , vi &b , int n ){
    vi seq1(n) , seq2(n) ; 
    for( int i=n-1 ; i>=0 ; --i ){
        seq1[i] = ( i % 2 == 0 ? a[i] : b[i] ) ; 
        seq2[i] = ( i % 2 == 0 ? b[i] : a[i] ) ; 
    }
    return max( util( seq1 , n ) , util( seq2 , n ) ) ; 
}


void solve(){
    int n ; cin >> n ; 
    vi a(n) , b(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> a[i] ; 
    }
    for( int i=0;i<n ; ++i ){
        cin >> b[i] ; 
    }
    
    int ans = max( sol1( a , b , n ) , sol2( a , b , n ) ) ; 
    cout << ans << '\n' ; 
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
