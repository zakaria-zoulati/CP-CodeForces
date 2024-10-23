#include <iostream>
#include <cmath>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t; 
    while(t--) {
        long long x;
        cin >> x;

        bool flag = false; 
        for(long long i = 1; i*i*i < x; ++i) {
            long long a = i * i * i;
            long long remaining = x - a;
            long long j = round(cbrt(remaining)); 
            if(j * j * j == remaining) {
                flag = true;
                break;
            }
        }

        cout << (flag ? "YES" : "NO") << "\n"; 
    }
    
    return 0;
}
