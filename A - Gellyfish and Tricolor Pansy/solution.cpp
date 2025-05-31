#include <iostream> 
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>


using namespace std ;
using ll = long long ; 

void solve() {
    int a , b , c , d ; 
    cin >> a >> b >> c >> d ; 

    string winner = "-1" ; 

    int n = min( a , c ) ; 
    int m = min( b , d ) ; 
    if(  n >= m ){
        winner = "Gellyfish" ; 
    }else {
        winner = "Flower" ; 
    }
    cout << winner << endl ; 
    
}

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;

    int t = 1 ;
    cin >>  t ;
    while (t--) {
        solve() ; 
    }
    return 0;
}