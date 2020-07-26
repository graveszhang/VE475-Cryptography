> Arthor: Liqin Zhang
>
> UID: 517370910123
>
> VE475 Homework7

## Usage

The code is written in c, and tested under macOS Catalina 10.15.4. 

Please use following command to compile and run the code (make sure gmp library is installed).

```bash
$ gcc main.c -lgmpxx -lgmp
```

## Faster multiple modular exponentiation

This project is my implementation of regular square and multiply algorithm and faster multiple modular exponentiation.

Input for the algorithms are 5 big integers ```(a,b,x,y,n)```, which are generated randomly. Here by default, ```n``` is 256 bits, and the rest are 64 bits.

Output of the algorithms is  the result of $a^xb^y \text{ mod }n$ and the comparison based on their runtime.

## Sample output

```c
n = 38664216765059922648131121781763603171417642853164328902694022676789531768559
a = 809550273035356741
b = 4065807389186626716
alpha = 8895135524184400835
beta = 10663849693912557257
Faster multiple modular exponentiation algorithm is faster.
```

