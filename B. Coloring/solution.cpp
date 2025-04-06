#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int top = ( n+k-1 )/k ; 
        bool fl = false ; 
        int count = 0 ; 
        for( int i=0 ; i<m ; ++i ){
            int ai ; cin >> ai ; 
            if( ai > top ){
                fl = true ; 
            }else if( ai == top ){
                count++ ; 
            }
        }

        if ( fl ) {
            cout << "NO\n";
        } else if( count <= (n-1)%k + 1 ) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }

    return 0;
}
