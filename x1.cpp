#include <iostream>
#include <string>
#include <vector>
#include "utility.h"
#include "x1.h"

using namespace::std;

static const double THRESHOLD = 3.8415;

void X1(istream &in) {
	int n = 0, n1 = 0, n0 = 0, cnt = 0, total = 0;
	unsigned char byte;
	while (in >> noskipws >> byte) {
		n += 8;
		if (total < 256){
			cnt += 2;
			printf("%02x", byte);
			total++;
			if (cnt == 32) {
				cnt = 0;
				cout << endl;
			}
		}
		CountZeroOneBits(byte, n0, n1);
	}
	if (cnt != 0) {
		cout << endl;
	}
	if (n < 10) {
		Fatal("n = %d\nx1: insufficient data\n", n);
	}
	double x1 = 1.0*(n0-n1)/n*(n0-n1);
	printf("n = %d\n", n);
	printf("n0 = %d\n", n0);
	printf("n1 = %d\n", n1);
	printf("x1 = %.06f\n", x1);
	printf("pass/fail = %s\n", (x1 <= THRESHOLD ? "pass" : "fail"));
}
