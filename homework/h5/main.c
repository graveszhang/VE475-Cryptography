#include <stdio.h>
#include <gmp.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#define RSA80 1024
#define RSA112 2048
#define RSA128 3072
#define RSA192 7680
#define RSA256 15360
using namespace std;

typedef struct rsa_key_t{
    size_t security;
    mpz_t p,q,n,e,d;
} rsa_key;

void generate_key(rsa_key *key){
    //initialize size of p, q
    size_t len = key->security;
    size_t p_size = len/2;
    size_t q_size = len/2;

    //generate p, q
    gmp_randstate_t randstate;
    gmp_randinit_mt(randstate);
    gmp_randseed_ui(randstate, (unsigned) time(NULL));

    while (1){
        mpz_urandomb(key->p, randstate, p_size - 1);
        if (mpz_even_p(key->p)) mpz_sub_ui(key->p, key->p, 1);
        if (mpz_probab_prime_p(key->p, 15)) break;
    }
    while (1){
        mpz_urandomb(key->q, randstate, q_size - 1);
        if (mpz_even_p(key->q)) mpz_sub_ui(key->q, key->q, 1);
        if (mpz_probab_prime_p(key->q, 15)) break;
    }

    mpz_mul(key->n, key->p, key->q); //n
    mpz_t phi,gcd,p1,q1;
    mpz_inits(phi,p1,q1,gcd);

    mpz_sub_ui(p1, key->p, 1); //p-1
    mpz_sub_ui(q1, key->q, 1); //q-1
    mpz_mul(phi, p1, q1);//phi

    while (1){
        mpz_urandomb(key->e, randstate, len-2);
        if (mpz_even_p(key->e)) mpz_add_ui(key->e, key->e, 1);
        mpz_gcd(gcd, key->e, phi);
        if (mpz_cmp_ui(gcd,1) == 0) break;//calculate e
    }
    mpz_invert(key->d, key->e, phi);//d
}

void encrypt(mpz_t *m, mpz_t *c, rsa_key *k){
    mpz_powm(*c, *m, k->e, k->n);
}

void decrypt(mpz_t *m, mpz_t *c, rsa_key *k){
    mpz_powm(*m, *c, k->d, k->n);
}

void print_key(rsa_key *key){
    printf("******************************************************RSA Key INFO*************************************************\n");
    printf("RSA modulus(bits): %d\n", key->security);
    printf("p: %s\n", mpz_get_str(NULL, 16, key->p));
    printf("q: %s\n", mpz_get_str(NULL, 16, key->q));
    printf("n: %s\n", mpz_get_str(NULL, 16, key->n));
    printf("e: %s\n", mpz_get_str(NULL, 16, key->e));
    printf("d: %s\n", mpz_get_str(NULL, 16, key->d));
    printf("********************************************************************************************************************\n");

}

int main() {
    rsa_key key;
    mpz_inits(key.p,key.q,key.n,key.e,key.d);
    key.security = RSA112;
    generate_key(&key);
    print_key(&key);
    mpz_t m,c;
    mpz_inits(m,c);
    cout <<  "Enter any text you want to be encrypted(0-9): ";
    cin >> m;
    printf("Plaintext(Hex): %s\n", mpz_get_str(NULL, 16, m));
    encrypt(&m, &c, &key);
    printf("Ciphertext: %s\n", mpz_get_str(NULL, 16, c));
    decrypt(&m, &c, &key);
    printf("Decrypted text: %s\n", mpz_get_str(NULL, 16, m));
    printf("********************************************************************************************************************\n");

    return 0;
}
