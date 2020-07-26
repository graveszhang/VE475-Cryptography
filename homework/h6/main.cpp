#include <iostream>
using namespace std;

uint64_t gcd(uint64_t a, uint64_t b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

inline uint64_t f(uint64_t a, uint64_t n){
    return (a * a + 2) % n;
}

uint64_t pollard_rho(uint64_t n){
    uint64_t a = 2, b = 2, d = 1;
    while (d == 1){
        a = f(a, n);
        b = f(f(b, n), n);
        d = gcd(a > b ? a - b : b - a, n);
    }
    return d;
}

int main(){
    uint64_t n;
    cout << "Please enter a number to be factorized: ";
    cin >> n;
    if (n > 1){
        while (true){
            auto p = pollard_rho(n);
            if (p == n){
                cout << "Found factor: " << p << endl;
                break;
            } else {
                cout << "Found factor: " << p << endl;
                n = n/p;
            }
        }
    }
    return 0;
}
