#include <iostream>
#include <string>
#include <vector>
#include "utility.h"
#include "x2.h"

using namespace::std;

static const double THRESHOLD = 5.9915;

void X2(std::istream &in) {
	int n = 0, n1 = 0, n0 = 0, cnt = 0, total = 0;
	//consecutive bits count
	vector<int> twoBits(4, 0);
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
		CountZeroOneBits(byte, n0, n1);
	}
	for (size_t i = 0; i < 8 * bytes.size() - 1; ++i) {
		unsigned char _2bits = RangeBits(bytes, i, 2);
		twoBits[_2bits]++;
	}
	if (cnt != 0) {
		cout << endl;
	}
	if (n < 21) {
		Fatal("n = %d\nx2: insufficient data\n", n);
	}
	double x2 = 4.0/(n-1)*SquareSumVec(twoBits)-2.0/n*(1.0*n0*n0+n1*n1)+1;
	printf("n = %d\n", n);
	printf("n0 = %d\n", n0);
	printf("n1 = %d\n", n1);
	printf("n00 = %d\n", twoBits[0]);
	printf("n01 = %d\n", twoBits[1]);
	printf("n10 = %d\n", twoBits[2]);
	printf("n11 = %d\n", twoBits[3]);
	printf("x2 = %.06f\n", x2);
	printf("pass/fail = %s\n", (x2 <= THRESHOLD ? "pass" : "fail"));
}
