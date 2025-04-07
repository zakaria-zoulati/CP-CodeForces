#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1 ; 
    while (t--) {
        int n ; cin >> n ; 
        string s ; cin >> s ; 
        bool vasya = true ; 
        int moves = n - 11 ;
        int eights = 0 ; 
        int nums = 0 ; 
        for( int i=0 ; i<moves ; ++i ){
            if( s[i] == '8' ) eights++ ; 
            else nums++ ; 
        }
        if( eights == nums ){
            if( s[n-11] != '8' ) vasya = false ; 
        }else if( eights < nums ){
            vasya = false ; 
        }
        
        
        if( vasya ){
            cout << "YES" << endl ; 
        }else {
            cout << "NO" << endl ;
        }
    }

    return 0;
}