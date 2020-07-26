#include <gmpxx.h>
#include <iostream>
#include <ctime>
using namespace std;

pair<mpz_class, pair<mpz_class, mpz_class> >EEA(mpz_class &a, mpz_class &b){
    mpz_class r0 = b, r1t, r1 = a, s0 = 0, s1t, s1 = 1, t0 = 1, t1t, t1 = 0, q;
    while (r0 != 0){
        q = r1/r0;
        r1t = r1, r1 = r0, r0 = r1t - q * r0;
        s1t = s1, s1 = s0, s0 = s1t - q * s0;
        t1t = t1, t1 = t0, t0 = t1t - q * t0;
    }
    return make_pair(r1, make_pair(s1,t1));
}

int main(){
    gmp_randclass r1(gmp_randinit_default);
    r1.seed((unsigned long)(time(NULL)));

    mpz_class a = r1.get_z_bits(4096);
    mpz_class b = r1.get_z_bits(4096);

    cout << "Given two random 4096 bit number: " << a << " and "<< b << ", their gcd given by GMP function is: " << gcd(a,b) << ", and the result of extended euclidean algorithm is: " << EEA(a,b).first <<"."<< endl;

    if(gcd(a,b) == EEA(a,b).first) cout<< "We can see that two results are identical."<<endl;
    else cout<< "Two results are different."<<endl;

    return 0;
}
