#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)  

using namespace std ; 

using ll = long long  ;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

ll mod = 998244353 ; 


void solve(){
   int n , k ; 
   cin >> n >> k ; 
   vector<int> a(n) ; 
   for( int i=0 ; i<n ; ++i ){
        cin >> a[i] ; 
   }
   
   sort(all(a));
   
   int m = n-k ; 
   
   if (m % 2 == 1 && k == 0) {
        cout << 1 << '\n';
        return;
    }

    if (m % 2 == 1) m++;
    
    cout << (ll)a[n - m/2] - a[m/2 - 1] + 1 << '\n';
   
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
