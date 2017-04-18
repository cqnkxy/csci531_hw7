#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "utility.h"
#include "x4.h"

using namespace::std;

static const int THRESHOLD_START = 2;
static const double THRESHOLDS[] = {
	5.9915,
	9.4877,
	12.5916,
	15.5073,
	18.3070,
	21.0261,
	23.6848,
	26.2962,
	28.8693,
	31.4104
};

void X4(istream &in) {
	size_t n = 0, total = 0, cnt = 0;
	unsigned char byte;
	string bytes;
	while (in >> noskipws >> byte && total < 256) {
		printf("%02x", byte);
		cnt += 2;
		n += 8;
		total++;
		bytes += byte;
		if (cnt == 32) {
			cnt = 0;
			cout << endl;
		}
	}
	if (cnt != 0) {
		cout << endl;
	}
	if (n < 79) {
		Fatal("n = %lu\nx4: insufficient data\n", n);
	}
	int k = 0;
	for (int i = 2; i <= 12; i++) {
		if ((n-i+3)/(1<<(i+2)) >= 5) {
			k = i;
		}
	}
	assert(k >= 2);
	if (k >= 12) {
		Fatal("n = %lu\nk = %d\nx4: k is too large\n", n, k);
	}
	printf("n = %lu\n", n);
	printf("k = %d\n", k);
	double x4 = 0;
	size_t total_bits = bytes.size() << 3;
	for (size_t i = 1; i <= k; i++) {
		unsigned Bi = 0, Gi = 0;
		for (size_t idx = 0; idx + i <= total_bits; idx++) {
			size_t start = idx, end = start+i;
			size_t bits = RangeBits(bytes, start, i);
			if (bits == 0 &&
					(start == 0 || IthBit(bytes, start-1) == 1) &&
					(end == total_bits || IthBit(bytes, end) == 1)) {
				Gi++;
			}
			if (bits == (1<<i)-1 &&
					(start == 0 || IthBit(bytes, start-1) == 0) &&
					(end == total_bits || IthBit(bytes, end) == 0)) {
				Bi++;
			}
		}
		double ei = (n-i+3)*1.0/(1<<(i+2));
		printf("e%lu = %.06f\n", i, ei);
		printf("B%lu = %d\n", i, Bi);
		printf("G%lu = %d\n", i, Gi);
		x4 += (Bi-ei)*(Bi-ei)/ei + (Gi-ei)*(Gi-ei)/ei;
	}
	printf("x4 = %.06f\n", x4);
	printf("pass/fail = %s\n", x4 <= THRESHOLDS[k-THRESHOLD_START] ? "pass" : "fail");
}
