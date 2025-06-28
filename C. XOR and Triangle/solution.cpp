#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long ; 

void solve() {
   int x ; cin >> x ; 

   if ((x & (x - 1)) == 0 || ((x + 1) & x) == 0) {
       cout << -1 << '\n' ; 
       return ; 
   }
   
   int y = x ; 
   while( ( y & ( y -1 ) ) != 0 ){
       y -= ( y & -y ) ; 
   }
   cout << y-1 << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t ; 
    while (t--) {
        solve();
    }
    
    return 0;
}
