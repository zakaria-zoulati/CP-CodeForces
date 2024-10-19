#include <iostream>
using namespace std;

int main() {
    long long b; 
    cin >> b; 
    long long rs = 1; 

    if (b % 2 == 0) {
        int count = 0; 
        while (b % 2 == 0) {
            count++;  
            b /= 2; 
        }
        rs *= (count + 1); 
    }


    for (long long i = 3; i * i <= b; i += 2) {
        if (b % i == 0) {
            int count = 0; 
            while (b % i == 0) {
                count++;  
                b /= i; 
            }
            rs *= (count + 1); 
        }
    }
    

    if (b > 1) {
        rs *= 2; 
    }
    
    cout << rs << endl;
    
    return 0;
}
