#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 1'000'000'007 ; 

bool possible( vector<pair<int,int>> &arr , int n , int tar ){
    int ele = 1 ; 
    for( int i=0 ; i<n ; ++i ){
        if( arr[i].first >= tar - ele && arr[i].second >= ele -1 ){
            ele++ ; 
        }
        if( ele > tar ) return true; 
    }
    return false ; 
}

void solve(){
  int n ; cin >> n ; 
  
  
  vector<pair<int,int>> arr(n) ; 
  for( int i=0 ; i<n ; ++i ){
      cin >> arr[i].first >> arr[i].second ; 
  }
  
  int l = 1 ; 
  int r = n ; 
  while( l < r ){
      int mid = l + ( r - l + 1 )/2 ; 
      if( possible( arr , n , mid ) ){
          l = mid ; 
      }else {
          r = mid - 1 ; 
      }
  }
  
  cout << l << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    cin >> t ; 
    
    while( t-- ){
       solve() ; 
    }
}
