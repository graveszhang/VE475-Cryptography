> Arthor: Liqin Zhang
>
> UID: 517370910123
>
> VE475 Homework6

## Usage

The code is written in c, and tested under macOS Catalina 10.15.4. 

Please use following command to compile and run the code (make sure gmp library is installed).

```bash
$ g++ main.cpp
```

## Pollard-rho 

This program will use pollard-rho algorithm to find nontrivial factors of a large integer n.

Sometimes the algorithm may fail even when n is composite, in that case, this method can be re-run using another starting value. (By default a=b=2)

## Sample

```c
Please enter a number to be factorized: 91237321931247212
Found factor: 4
Found factor: 7
Found factor: 7
Found factor: 447883
Found factor: 1039326209
  
Process finished with exit code 0

```

