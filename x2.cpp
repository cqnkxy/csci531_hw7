#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "utility.h"
#include "x2.h"

using namespace::std;

static const double THRESHOLD = 5.9915;

bool ithBit(const string &bytes, size_t i) {
	return bytes[i/8] & (1 << (7-i%8));
}

void X2(std::istream &in) {
	size_t n = 0, n1 = 0, n0 = 0, cnt = 0, total = 0;
	//consecutive bits count
	vector<size_t> twoBits(4, 0);
	unsigned char byte;
	string bytes;
	while (in >> noskipws >> byte && total < 256) {
		printf("%02x", byte);
		cnt += 2;
		total++;
		n += 8;
		bytes += byte;
		CountZeroOneBits(byte, n0, n1);
		if (cnt == 32) {
			cnt = 0;
			cout << endl;
		}
	}
	for (size_t i = 0; i < 8 * bytes.size() - 1; ++i) {
		unsigned char _2bits = (ithBit(bytes, i) << 1) | (ithBit(bytes, i+1));
		twoBits[_2bits]++;
	}
	if (cnt != 0) {
		cout << endl;
	}
	if (n < 21) {
		Fatal("n = %lu\nx1: insufficient data\n", n);
	}
	double x2 = 4.0/(n-1)*(twoBits[0]*twoBits[0]+twoBits[1]*twoBits[1]+twoBits[2]*twoBits[2]+twoBits[3]*twoBits[3])-2.0/n*(n0*n0+n1*n1)+1;
	printf("n = %lu\n", n);
	printf("n0 = %lu\n", n0);
	printf("n1 = %lu\n", n1);
	printf("n00 = %lu\n", twoBits[0]);
	printf("n01 = %lu\n", twoBits[1]);
	printf("n10 = %lu\n", twoBits[2]);
	printf("n11 = %lu\n", twoBits[3]);
	printf("x2 = %.06f\n", x2);
	printf("pass/fail = %s\n", (x2 <= THRESHOLD ? "pass" : "fail"));
}
