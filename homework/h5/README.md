> Arthor: Liqin Zhang
>
> UID: 517370910123
>
> VE475 Homework5

## Usage

The code is written in c, and tested under macOS Catalina 10.15.4. 

Please use following command to compile and run the code (make sure gmp library is installed).

```bash
$ g++ main.c -lgmpxx -lgmp
```

## RSA

This project is my implementation of RSA, which takes an arbitrary length bits of decimal plaintext message as input and turns it into hexadecimal with encryption and decryption process.

First, we can choose from five different selectable security levels, with which we can generate our rsa key.

```cpp
#define RSA80 1024
#define RSA112 2048
#define RSA128 3072
#define RSA192 7680
#define RSA256 15360
```

Next, we have all the information about ``` p,q,n,d,e``` of our key, we can use ```print_keys(rsa_key)``` function to check the info.

After that, we can use ```encrypt``` and ```decrypt``` to get ciphertext and plaintext from our original message, we can verify that they should be identical. 

*Note* that we can only input decimal and ```mpz_get_strs``` will turn it into hex and display in strings. For example, input message ```10``` will become ```a```, and ```15``` will be come ```f```.

A sample output of this program is given below:

```bash
**********************************RSA Key INFO*************************************
RSA modulus(bits): 2048
p: 5552f02fa289c275e1a18cede2ddb80415112731e366499f64a4319fe0224a26956f32434fee8ec7795e87b018d6ee8439b01b073f5fd9d06440ea2027ed137c5ee668f14639cb9f6a2e5dcbe6eb0c4a2aec50119d41e71e31dbb906b1f215f165af97ad95cd7fc824f2c79f86b1953dd9716960e01cc536e69e5ac366587889
q: 549376251396960b2410d6a2a8f8b6d6cb6fa1b211fe4c1d7dac756204ad0d5f11424d8fa59188a1f06c373fddb2fb5e7a0c71fb5f70fde688ac55368027e8097e300c4771ddc00a8ff40fc286e989f6a0b775326f8d16c349ce7f846dd2e238e4ae462cbb67c5fce3d52a2cd7ad0ed4a9415460c51c7eaa16ae9b20d879b5ff
n: 1c305cd022e98d25e98ffafab47154ead165ee9daedc0423abc25a49b9be97b18df5f190fc8984337e424f70a3eb827348f2baf9a77d70ffd698f254a1718566c87314d931cf52e2880abc92d020c3b375961c3ffbd52ff3126278c0ec7b3c7f956012227cb81820936182f3b650da1fe3674e9cbcd31b49781a0f4d21e306125bf66b1b05bf6b49203452326757db37548eca4a963839f25554e76d98e1e71aa718377db28a43332efa85a16280a8fbc4fe5fbacdfb5bbac133664027aaafb53aa9c5d1610a2aec3b3c4772c355c0bae8b498e345adc5fe5f882cf0cd5cd94d9f7805165cf5c1af914ba86da39e66a55af7c9d06c0b2b0781c699a41019ed77
e: 18635157e1609c9710455509446e33cea8b259a0c6dffb8abec9b8ce3d4e64e54817b0b6c53cb1d5e3827c44194f43f2afe9407d6eccd30776107d3214c7b6b09e75df453cfc237e358b245510cd1df825b605c5344e64f75af779e5ff04b8d397a1d9887b8b5cd52ffb377fc92ab8617e1b252db647e2cb87a41b23cdb93f3c530bde0de1ab92508e77f615dc4d3e88dd5fe5aeceaf38d7d4f8c86cd2e42e0b2850b4244dc71df56e30e5a3b23035a539692364d9cc7d982f4fb0e89f3cef9a641e4abd5603e950cf806e3fab63a37793474fe447518bdcecca5d552f1a415cea47ce1bd408e62ca4103645ec2c55235bcc1a7fa4189aa444551cf99ae1a7ef
d: 64d0a49f227f7d81e202b4983ba110bf5cf4af3ce864d16cc3f82808da50d34c09b641a0616add450246656857f8a84aef1cef66b88a6b7ce30c2aa87b5305196ca818a6040bfc04076440d2355fdd34c7654036693ee7eb26c4110246dbe13a8d495cd0e8cdddfadc2ee35b6f1ce51c7ca90c9ce67a3228da77abbc20d999e7ae8580c298f2c99abae0ba70e90677c0c83fad796f8ac633b0affa2ad20c9dae3a49121827b2693426d829209fb2475252fdd592ae989eccbb3ac21952ae163f53ae85a6995131e035c1a713285678925cd42d95fca4473409214531a2a42e1fc1da5453351c256cc22c78a6dd6d8d003bef6d0099d3cd8dbdcdfce3d41368f
***************************************************************************************
Enter any text you want to be encrypted(0-9): 1234
Plaintext(Hex): 4d2
Ciphertext: 1505bc9c4af91b6ea01765770321af598cae2fb7440c825020aaa06453d1b5ed9346d18489519bd6f0f81cf564568b00290df3a1a772ffa3dc179d1478dc5c30539ef55a6aeeba9baf7821cfcef69bc11ffe1b734cceb09799bebbe2403006e812bdc8228c824cead80290c78b8482c2bc195b044dfa2fcec030e2406021c173417cc3af9860dcbda53a48b967ce44e58097e72eef5c7b1595d099356151683aaf6b0567a57aa43c6a012583998d9036b1d31d6719a8e5cd32117bfc98789fa8af95f285791a859cdc8205c324a9b692942c55614a3976fb45e7c41267760a434fab369d3ced64a5d71f4e9edc8752c10e221c2054513423e41167a8879a7ca4
Decrypted text: 4d2
***************************************************************************************
```



