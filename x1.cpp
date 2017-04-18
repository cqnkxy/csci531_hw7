#include <iostream>
#include <string>
#include <vector>
#include "utility.h"
#include "x1.h"

using namespace::std;

static const double THRESHOLD = 3.8415;

void X1(istream &in) {
	size_t n = 0, n1 = 0, n0 = 0, cnt = 0;
	unsigned char byte;
	while (in >> noskipws >> byte) {
		printf("%02x", byte);
		cnt += 2;
		n += 8;
		CountZeroOneBits(byte, n0, n1);
		if (cnt == 32) {
			cnt = 0;
			cout << endl;
		}
	}
	if (cnt != 0) {
		cout << endl;
	}
	if (n < 10) {
		Fatal("n = %zu\nx1: insufficient data\n", n);
	}
	double x1 = (n0 - n1)*(n0-n1)*1.0/n;
	printf("n = %zu\n", n);
	printf("n0 = %zu\n", n0);
	printf("n1 = %zu\n", n1);
	printf("x1 = %.06f\n", x1);
	printf("pass/fail = %s\n", (x1 <= THRESHOLD ? "pass" : "fail"));
}
