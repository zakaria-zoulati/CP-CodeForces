#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;
using ll = long long;

int helper( vector<vector<int>> &f ,int l , int r ){
    int all = 0 ; 
    int best = 0 ; 
    for( int i=0 ; i<26 ; ++i ){
        all += f[l][i] ; 
        all += f[r][i] ; 
        if( f[l][i] + f[r][i] > best ){
            best = f[l][i] + f[r][i] ; 
        }
    }
    return all - best ; 
}

void solve(){
  int n , k ; 
  cin >> n >> k ; 
  string s ; cin >> s ; 
  vector<vector<int>> f( k ,vector<int>( 26 , 0 ) ) ;
  for( int i=0 ; i<n ; ++i ){
    f[ i % k ][ s[i] - 'a' ]++ ; 
  } 
  int rs = 0 ; 
  int l = 0 ; 
  int r = k-1 ; 
  while( l <  r ){
    rs += helper( f , l , r ) ; 
    l++ ; 
    r-- ; 
  }
  if( l == r ){
    rs += helper( f , l , r )/2 ; 
  }
  cout << rs << '\n' ; 
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    cin >> t ; 
    while(  t--  ){
       solve() ; 
    }
    return 0 ; 
}
