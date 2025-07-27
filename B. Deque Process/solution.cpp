#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
using ll = long long;

ll mod = 998244353 ; 
void solve() {
  int n ; cin >> n ; 
  vector<int> arr(n) ; 
  for( int i=0 ; i<n ; ++i ){
    cin >> arr[i] ; 
  }
  int l = 1 ; 
  int r = n-1 ; 
  int prev = arr[0]  ;
  string rs = "L" ; 
  int mo = 0;  
  while( l<r ){
    if( arr[l] == arr[r] ){
        rs += "LR" ; 
        mo = 0; 
        prev = arr[l] ;
        l++ ; 
        r-- ; 
    }else if( arr[l] == prev ){
      rs += "L" ; 
      l++ ; 
      mo = 0 ;
    }else if( arr[r] == prev) {
      rs += "R" ; 
      r-- ; 
      mo = 0 ;
    }else if( arr[l] > prev && arr[r] > prev ){
      if( arr[l] == arr[r] ){
        prev = arr[l] ; 
        mo = 0 ; 
        rs += "LR" ; 
        l++ ; 
        r-- ; 
      }else {
        if( arr[l] < arr[r] ){
          prev = arr[l] ; 
          rs += "RL" ; 
          l++ ; 
          r-- ; 
        }else {
          prev = arr[r] ; 
          rs += "LR" ; 
          r-- ; 
          l++ ; 
        }
        mo = 2 ; 
      }
    }else if( arr[l] < prev && arr[r] < prev ){
      if( arr[l] == arr[r] ){
        prev = arr[l] ; 
        mo = 0 ; 
        rs += "LR" ; 
        l++ ; 
        r-- ; 
      }else {
        if( arr[l] > arr[r] ){
          prev = arr[l] ; 
          rs += "RL" ; 
          l++ ; 
          r-- ;
        }else{
          prev = arr[r] ; 
          rs += "LR" ; 
          r-- ; 
          l++; 
        }
        mo = 1 ; 
      }
    }else {
      if( mo == 1 ){
        if( arr[l] < prev ){
          rs += "L" ; 
          prev = arr[l] ; 
          l++ ; 
          mo = 2 ; 
        }else {
          rs += "R" ; 
          prev = arr[r] ; 
          r-- ; 
          mo = 2 ; 
        }
      }else if( mo == 2 ){
        if( arr[l] > prev ){
          rs += "L" ; 
          prev = arr[l] ; 
          l++ ; 
          mo = 1 ; 
        }else {
          rs += "R" ; 
          prev = arr[r] ; 
          r-- ; 
          mo = 1 ; 
        }
      }else {
        if( arr[l] > prev ){
          mo = 1 ; 
        }else {
          mo = 2 ; 
        }
        rs += "L" ; 
        prev = arr[l] ; 
        l++ ; 
      }
    }
  }
  if( l == r ){
    rs += "L" ; 
  }
  cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    cin >> t ; 
    while (t--){
      solve() ; 
    }
    return 0;
}