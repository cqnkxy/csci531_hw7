#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include "utility.h"
#include "x4.h"

using namespace::std;

static const double THRESHOLD = 1.9600;

void X5(istream &in, int dval) {
	int n = 0, cnt = 0, total = 0;
	unsigned char byte;
	string bytes;
	while (in >> noskipws >> byte) {
		n += 8;
		if (total < 256) {
			printf("%02x", byte);
			cnt += 2;
			total++;
			if (cnt == 32) {
				cnt = 0;
				cout << endl;
			}
		}
		bytes += byte;
	}
	if (cnt != 0) {
		cout << endl;
	}
	if (n < dval + 10) {
		Fatal("n = %d\nx5: insufficient data\n", n);
	}
	if (dval < 1 || dval > (n>>1)) {
		Fatal("n = %d\nx5: d should be in the range [1,%d]\n", n, n>>1);
	}
	int Ad = 0;
	for (int i = 0; i < n-dval; i++) {
		Ad += IthBit(bytes, i) != IthBit(bytes, i+dval);
	}
	double x5 = 2*(Ad - (n-dval)/2.0) / sqrt(n-dval);
	printf("n = %d\n", n);
	printf("d = %d\n", dval);
	printf("A(d) = %d\n", Ad);
	printf("x5 = %.06f\n", x5);
	printf("pass/fail = %s\n", x5 < THRESHOLD && x5 > -THRESHOLD ? "pass" : "fail");
}
