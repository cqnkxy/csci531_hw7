#include <iostream>
#include <string>
#include <vector>
#include "utility.h"
#include "x3.h"

using namespace std;

static const double THRESHOLDS[] = {
	3.8415,
	7.8147,
	14.0671,
	24.9958,
	44.9853,
	82.5287,
	154.3015,
	293.2478,
	564.6961,
	1098.5208
};

void X3(istream &in) {
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
	if (n < 10) {
		Fatal("n = %lu\nx1: insufficient data\n", n);
	}
	int m = 0;
	for (int i = 1; i <= 11; i++) {
		if (n/i >= 5*(1<<i)) {
			m = i;
		}
	}
	if (m > 10) {
		// Should never happen
		Fatal("n = %lu\nm =%d\nx3: m is too large", n, m);
	}
	int k = n/m;
	vector<size_t> mbits(1<<m, 0);
	for (size_t i = 0; i < k; i++){
		mbits[RangeBits(bytes, i*m, m)]++;
	}
	double x3 = 1.0*(1<<m)/k*SquareSumVec(mbits)-k;
	printf("n = %lu\n", n);
	printf("m = %d\n", m);
	printf("k = %d\n", k);
	for (size_t i = 0; i < mbits.size(); i++) {
		printf("n%s = %lu\n", DecToBinary((unsigned)i, m).c_str(), mbits[i]);
	}
	printf("x3 = %.06f\n", x3);
	printf("pass/fail = %s\n", (x3 <= THRESHOLDS[m-1] ? "pass" : "fail"));
}
