> Arthor: Liqin Zhang
>
> UID: 517370910123
>
> VE475 Homework3

## Usage

The code is written in c, and tested under macOS Catalina 10.15.4. 

Please use following command to compile and run the code (make sure cmake is installed).

```c
cmake ./
```

## AES

This project is my implementation of AES, which takes an 128 bits size plaintext message as input and return a 128 bits size ciphertext. I implemented all four layers in the encryption process and wrote some helper functions for the completeness. Those four layers I mentioned are:

- Add Round Key Layer
- Sub Bytes Layer
- Shift Rows Layer
- Mix Column Layer

A sample output of this program is given below:

```bash
Plaintext message:
00	11	22	33	44	55	66	77	88	99	aa	bb	cc	dd	ee	ff	
Key used:
2e	46	0d	11	01	a9	85	b2	29	30	af	76	a2	e1	7d	a8	
Ciphertext message:
69	8c	d5	f6	10	54	1b	7e	85	d4	55	c4	60	e3	aa	0a	

Process finished with exit code 0
```



