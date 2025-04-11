#include <iostream> 
#include <vector>
#include <limits>
#include <cmath>

using namespace std ; 

typedef long long ll ; 

int main( ) {
    int n ; cin >> n ; 
    double vb , vs ; 
    cin >> vb >> vs ; 
    vector<double> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    double x , y ; 
    cin >> x >> y ;
    int rs = 2 ; 
    double best = numeric_limits<double>::max()  ; 
    for( int i=1 ; i<n ; ++i ){
        double d = sqrt( y*y + (x-arr[i])*(x-arr[i]) ) ; 
        double t = arr[i]/vb + d/vs ;
        if( t <= best ){
            rs = i+1 ; 
            best = t ; 
        }
    }
    cout << rs << endl ; 
    
    return 0 ; 
}