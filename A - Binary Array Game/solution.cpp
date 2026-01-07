#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x) 

using ll = long long ;  
using vi = vector<int> ; 
using vvi = vector<vi> ; 

using vb = vector<bool> ; 
using vvb = vector<vb> ; 

using pi = pair<int,int> ; 

const int mod = 998244353; 

void solve( ){
   int n ; cin >> n ; 
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
    cin >> arr[i] ; 
   }
   
   int ones = 0  ; 
   int zeros = 0 ; 
   for( int i=0 ; i<n ; ++i ){
    if( arr[i] == 1 ){
        ones++ ; 
    }else {
        zeros++ ; 
    }
   while( i+1<n && arr[i+1] == arr[i] ) i++ ; 
    
}
   if( ones >= zeros ){
    cout << "Alice\n" ; 
   }else {
    cout << "Bob\n" ; 
   }


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