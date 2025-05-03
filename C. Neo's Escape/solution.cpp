#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>

using namespace std;

using ll = long long;

void solve() {
   int n ; cin >> n ; 
   vector<int > arr ;     
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        if (arr.empty() || arr.back() != ai) {
            arr.push_back(ai);
        }
    }
   int len = arr.size() ; 
   if( len == 1 ){
       cout << 1 << endl ; 
   }else {
       int rs = 0 ; 
       if( arr[1] < arr[0] ) rs++ ; 
       for( int i=1 ; i<len-1 ; ++i ){
           if( arr[i-1] < arr[i] && arr[i] > arr[i+1] ){
               rs++ ; 
           }
       }
       if( arr[len-2] < arr[len-1] ) rs++ ; 
       cout << rs << endl ; 
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ; cin >> t ; 
    while (t--) {
        solve();
    }
}
