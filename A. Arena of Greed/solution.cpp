#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;
using ll = long long;

constexpr double pi = 3.14159265358979323846;

void solve(){
    ll n ; cin >> n ; 
    ll rs = 0 ; 
    bool fl = true ; 
    while( n > 0 ){
        if( fl ){
            if( n % 2 == 1 ){
                rs++ ; 
                n-- ; 
            }else if( n%4==0 && n>=8 ){
                rs++ ; 
                n-- ; 
            }else {
                rs += n/2 ; 
                n >>= 1 ; 
            }
        }else{
            if( n % 2 == 1 ){
                n-- ; 
            }else if( n % 4 == 0 && n>=8 ){
                n-- ; 
            }else {
                n >>= 1 ;
            }
        }
        fl = !fl ; 
    }
    cout << rs << '\n' ;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    cin >> t ; 
    while(  t--  ){
       solve() ; 
    }
    return 0 ; 
}
