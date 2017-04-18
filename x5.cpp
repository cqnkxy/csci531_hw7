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
	size_t n = 0, cnt = 0, total = 0;
	unsigned char byte;
	string bytes;
	while (in >> noskipws >> byte && total < 256) {
		printf("%02x", byte);
		cnt += 2;
		total++;
		n += 8;
		bytes += byte;
		if (cnt == 32) {
			cnt = 0;
			cout << endl;
		}
	}
	if (cnt != 0) {
		cout << endl;
	}
	if (n < (size_t)dval + 10) {
		Fatal("n = %zu\nx5: insufficient data\n", n);
	}
	if (dval < 1 || (size_t)dval > (n>>1)) {
		Fatal("n = %zu\nx5: d should be in the range [1,%zu]\n", n, n>>1);
	}
	size_t Ad = 0;
	for (size_t i = 0; i < n-dval; i++) {
		Ad += IthBit(bytes, i) != IthBit(bytes, i+dval);
	}
	double x5 = 2*(Ad - (n-dval)/2.0) / sqrt(n-dval);
	printf("n = %zu\n", n);
	printf("d = %d\n", dval);
	printf("A(d) = %zu\n", Ad);
	printf("x5 = %.06f\n", x5);
	printf("pass/fail = %s\n", x5 < THRESHOLD ? "pass" : "fail");
}
