#include <iostream>
#include <vector>


using namespace std;

#include <iostream>
using namespace std;

void solve() {
    int n ; cin >> n ; 
    int s ; cin >> s ; 
    int count = 0; 
    for( int i=0 ; i<n ; ++i ){
        int dx , dy ; 
        cin >> dx >> dy ; 
        int x , y ; 
        cin >> x >> y ; 
        if( dx*dy == 1 ){
            if( s -  x == s - y ){
                count++ ; 
            }
        }else {
            if( y == s - x ){
                count++ ; 
            }
        }
    }
    cout << count << '\n' ; 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1 ;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
