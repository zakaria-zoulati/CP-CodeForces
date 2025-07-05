#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

constexpr double pi = 3.14159265358979323846;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1; 
    // cin >> t ; 
    while(  t--  ){
       double d , h , v , e ;
       cin >> d >> h >> v >> e ; 
       
       double v_e = pi*e*d*d/4.0 ; 
       if( v_e >= v ){
           cout << "NO" << '\n' ; 
       }else {
           double curr = h*pi*d*d/4.0 ;
           double rs = curr/( v - v_e ) ; 
           cout << "YES" << '\n' ; 
           cout << fixed << setprecision(5) << rs << '\n' ; 
       }
       
    }
    return 0 ; 
}
