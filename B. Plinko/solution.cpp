#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1 ;  
    // int t ; cin >> t ; 
    while( t-- ){
        string s ; getline( cin , s ) ; 
        int n = s.size() ; 
        int round = -1 ; 
        if( n == 7 ){
            round = 10 ;
        }else {
            round = s[5] - '0' ; 
        }
        cout << -1 << endl ;      
        
    }
    return 0;
}