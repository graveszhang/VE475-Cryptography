syms x
eqn = sqrt(x *log2(x)) == 128
S = solve(eqn)
Sa = double(solve(eqn,x))