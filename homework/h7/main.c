#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <gmp.h>

float sm(mpz_t n, mpz_t a, mpz_t b, mpz_t x, mpz_t y){
    mpz_t temp_a, temp_b;
    mpz_init_set_ui(temp_a, 1);
    mpz_init_set_ui(temp_b, 1);

    auto k_x = mpz_sizeinbase(x, 2);
    auto k_y = mpz_sizeinbase(y, 2);
    auto timestamp_a = clock();

    for (auto i = k_x - 1; i >= 0; i--){
        mpz_mul(temp_a, temp_a, temp_a);
        mpz_mod(temp_a, temp_a, n);
        if (mpz_tstbit(x, i)){
            mpz_mul(temp_a, temp_a, a);
            mpz_mod(temp_a, temp_a, n);
        }
    }
    for (auto i = k_y - 1; i >= 0; i--){
        mpz_mul(temp_b, temp_b, temp_b);
        mpz_mod(temp_b, temp_b, n);
        if (mpz_tstbit(y, i)){
            mpz_mul(temp_b, temp_b, b);
            mpz_mod(temp_b, temp_b, n);
        }
    }
    mpz_mul(temp_a, temp_a, temp_b);
    mpz_mod(temp_a, temp_a, n);
    auto timestamp_b = clock();
    mpz_clears(temp_a, temp_b, NULL);
    return difftime(timestamp_b, timestamp_a) / CLOCKS_PER_SEC;
}

float fast_sm(mpz_t n, mpz_t a, mpz_t b, mpz_t x, mpz_t y, mpz_t ab){
    mpz_t p;
    mpz_init_set_ui(p, 1);

    auto kx = mpz_sizeinbase(x, 2);
    auto ky = mpz_sizeinbase(y, 2);

    auto timestamp_a = clock();
    auto max = kx - 1;
    if (kx < ky) max = ky - 1;
    for (int i = max; i >= 0; i--){
        mpz_mul(p, p, p);
        mpz_mod(p, p, n);
        if (mpz_tstbit(x, i) && mpz_tstbit(y, i)){
            mpz_mul(p, p, ab);
            mpz_mod(p, p, n);
        }
        else if (mpz_tstbit(x, i)){
            mpz_mul(p, p, a);
            mpz_mod(p, p, n);
        }
        else{
            mpz_mul(p, p, b);
            mpz_mod(p, p, n);
        }
    }

    auto timestamp_b = clock();
    mpz_clear(p);
    return difftime(timestamp_b, timestamp_a) / CLOCKS_PER_SEC;
}

int main(){
    gmp_randstate_t randstate = {};
    gmp_randinit_mt(randstate);
    gmp_randseed_ui(randstate, (unsigned) time(NULL));
    mpz_t n, a, b, x, y, ab;
    mpz_inits(n, a, b, x, y, ab, NULL);
    size_t l = 256;
    size_t l2 = 64;
    mpz_urandomb(n, randstate, l);
    mpz_urandomb(a, randstate, l2);
    mpz_urandomb(b, randstate, l2);
    mpz_urandomb(x, randstate, l2);
    mpz_urandomb(y, randstate, l2);
    gmp_printf("n = %Zd\n", n);
    gmp_printf("a = %Zd\n", a);
    gmp_printf("b = %Zd\n", b);
    gmp_printf("alpha = %Zd\n", x);
    gmp_printf("beta = %Zd\n", y);

    mpz_mul(ab, a, b);
    auto timestamp1 = sm(n, a, b, x, y);
    auto timestamp2 = fast_sm(n, a, b, x, y, ab);
    if (timestamp1>timestamp2)
        printf("Normal square and modular algorithm is faster.\n");
    else printf("Faster multiple modular exponentiation algorithm is faster.\n");
    mpz_clears(n, a, b, x, y, NULL);
    return 0;
}