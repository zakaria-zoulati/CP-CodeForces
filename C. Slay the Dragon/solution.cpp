#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1 ;  
    long long zero = 0 ; 
    while( t-- ){
        // The Heros 
        int n ; cin >> n ; 
        vector<long long> heroes( n ) ;
        long long sum = 0 ; 
        for( int i=0 ; i<n ; ++i ){
            cin >> heroes[i] ; 
            sum += heroes[i] ; 
        }
        sort( heroes.begin() , heroes.end() ) ;
        // The Dragons 
        int m ; cin >> m ; 
        // Solve for each dragon independently
        for( int i=0 ; i<m ; ++i ){
            long long xi ; cin >> xi ; 
            long long yi ; cin >> yi ;
            long long cost = 0 ; 
            if( heroes[n-1] == xi ){
                cost = max( zero , yi - sum + heroes[n-1] ) ; 
            }
            else if( heroes[n-1] > xi ){
               // We can make the attack 
               int l = 0 ; 
               int r = n-1 ; 
               while( l < r ){
                   int mid = l + ( r - l )/2 ; 
                   if( heroes[mid] >= xi ){
                       r = mid ; 
                   }else{
                       l = mid +1  ;
                   }
               }
               long long rest = sum - heroes[l] ; 
               if( rest < yi ){
                   cost = yi - rest ; 
                   if( l > 0 ){
                       if( sum - heroes[l-1] < yi ) {
                           cost = min( cost , xi + yi - sum ) ;  
                       }
                   }
                   if( l>0 && sum - heroes[0] >= yi ){
                       int a=0 ; 
                       int b=l-1 ; 
                       while( a < b ){
                            int mid = a + ( b - a + 1 )/2 ; 
                            if( sum - heroes[mid] >= yi ){
                                a = mid ; 
                            }else {
                                b = mid - 1; 
                            }
                       }
                       if(sum - heroes[a] >= yi) {
                           cost = min( cost , xi - heroes[a] );
                       }
                   }
               }
               
            }else {
                cost += xi - heroes[n-1] ; 
                cost += max( zero , yi -  sum + heroes[n-1] ) ; 
            }
            
            cout << cost << "\n" ; 
        }
    }
    return 0;
}