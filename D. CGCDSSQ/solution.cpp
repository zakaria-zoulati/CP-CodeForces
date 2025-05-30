#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int gcd( int a , int b ){
    while( b != 0 ){
        int temp = a%b ; 
        a = b ; 
        b = temp ; 
    }
    return a ; 
}

void solve() {
   int n ; cin >> n ; 
   vector<int> arr(n) ; 
   for( int i=0 ; i<n ; ++i ){
       cin >> arr[i] ; 
   }
   
   map<int , ll > result ; 
   map<int,int> divisors ; 
   map<int,int> nextDivisors ; 
   for( int i=0 ; i<n ; ++i ){
       nextDivisors.clear() ; 
       for( auto &p : divisors ){
            nextDivisors[ gcd( arr[i] , p.first ) ] += p.second ;     
       }
       nextDivisors[ arr[i] ]++ ; 
       swap( nextDivisors , divisors ) ; 
       for( auto &p : divisors ){
           result[ p.first ] += p.second ; 
       }
       
   }
   
   int q ; cin >> q ; 
   while( q-- ){
       ll xi ; cin >> xi ; 
       cout << result[xi] << endl ; 
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
