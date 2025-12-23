#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;

int mod = 1'000'000'007 ; 

bool check( int l , int r , vector<int> &maxPref , vector<int> &minPref , vector<int> &maxSuff , vector<int> &minSuff , int n  ){
    int low = 0 ; 
    int high = n-1 ; 
    while( low < high ){
        int mid = low + ( high - low + 1 )/2; 
        if( maxPref[mid] <= r && minPref[mid] >= l  ){
            low = mid ; 
        }else {
            high = mid - 1 ; 
        }
    } 
    return minSuff[low] >= l && maxSuff[low] <= r ; 
}

void solve(){
  int n ; cin >> n ; 
  vector<int> row1(n) ; 
  for( int i=0 ; i<n ; ++i ){
      cin >> row1[i] ; 
  }
  vector<int> row2(n) ; 
  for( int i=0 ; i<n ; ++i ){
      cin >> row2[i] ; 
  }
  vector<int> maxSuff( n ) ; 
  vector<int> minSuff( n ) ; 
  maxSuff[n-1] = row2[n-1] ; 
  minSuff[n-1] = row2[n-1] ; 
  for( int i=n-2 ; i>=0 ; --i ){
      maxSuff[i] = max( row2[i] , maxSuff[i+1] ) ; 
      minSuff[i] = min( row2[i] , minSuff[i+1] ) ; 
  }
  vector<int> maxPref( n ) ; 
  vector<int> minPref( n ) ; 
  maxPref[0] = row1[0] ; 
  minPref[0] = row1[0] ; 
  for( int i=1 ; i<n ; ++i ){
      maxPref[i]= max( maxPref[i-1] , row1[i] ) ; 
      minPref[i]= min( minPref[i-1] , row1[i] ) ; 
  }
  ll ans = 0 ;
  for( int i=2*n ; i>=1 ; --i ){
      if( row1[0] <= i &&  check( 1 , i , maxPref , minPref , maxSuff , minSuff , n ) ){
        int l = 1 ; 
        int r = i ; 
        while( l < r ){
            int mid = l + ( r - l + 1)/2 ; 
            if( row1[0] >= mid && check( mid , i , maxPref , minPref , maxSuff , minSuff , n ) ){
                l = mid ; 
            }else {
                r = mid - 1 ; 
            }
        }
        ans += l ; 
      }
  }
  cout << ans << '\n' ; 
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
