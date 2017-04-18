# USC CSCI531 [HW7](http://merlot.usc.edu/cs531-s17/homeworks/hw7/)

Randomness Tests.

## Compile

type `make` or `make hw7` to generate executable.
type `make clean` to clear up *.o file and executable.

## Command

### Simulate the RC4 stream cipher: hw7 rc4 -p=pphrase [-l=len]

### Perform the frequency test on the input: hw7 x1 [file]
X1 should approximately follow a chi-square distribution with 1 degree of freedom if the input has at least 10 bits.

### Perform the serial test on the input: hw7 x2 [file]
X2 should approximately follow a chi-square distribution with 2 degrees of freedom if the input has at least 21 bits.

### Perform the poker test on the input: hw7 x3 [file]
X3 should approximately follow a chi-square distribution with (2m-1) degrees of freedom.

### Perform the runs test on the input: hw7 x4 [file]
X4 should approximately follow a chi-square distribution with (2k-2) degrees of freedom.

### Perform the autocorrelation test on the input: hw7 x5 -d=dval [file]
dval is the value of d given in the references. X5 should approximately follow an N(0,1) distribution if the input has at least (d+10) bits.
