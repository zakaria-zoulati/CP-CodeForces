#include <iostream> 
#include <vector>

using namespace std ; 

typedef long long ll ; 

int main( ) {
    string s ; cin >> s ; 
    int n = s.size() ; 
    
    ll rs = 0 ; 
    if( s[0] == '0' || s[0] == '4' || s[0] == '8' ){
        rs++ ; 
    }
    for( int i=1 ; i<n ; ++i ){
        int curr = s[i] - '0' ; 
        if( curr % 4 == 0 ){
            rs++ ;
        }
        curr += ( s[i-1] - '0' )*10 ; 
        if( curr % 4 == 0 ){
            rs += i ; 
        }
    }
    
    cout << rs << endl ; 
    
    return 0 ; 
}