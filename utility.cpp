#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <vector>
#include "utility.h"

using namespace std;

const bool DEBUG = true;

void CountZeroOneBits(unsigned char byte, size_t &n0, size_t &n1) {
	for (int i = 0; i < 8; ++i) {
		unsigned char bit = (byte >> i) & 0x1;
		n0 += bit == 0;
		n1 += bit == 1;
	}
}

size_t HexDumpInput(istream &in) {
	unsigned char byte;
	int cnt = 0, total = 0;
	size_t bits = 0;
	while (in >> byte && total < 256) {
		printf("%02x", byte);
		cnt += 2;
		total++;
		bits += 8;
		if (cnt == 32) {
			cnt = 0;
			cout << endl;
		}
	}
	if (cnt != 0) {
		cout << endl;
	}
	return bits;
}

void HexDumpVec(const vector<unsigned char> &vec){
	for (size_t i=0; i < vec.size(); ++i) {
		printf("%02x", vec[i]);
	}
	cout << endl;
}

void Fatal(const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	exit(1);
}

void Dprint(const char *fmt, ...) {
	if (DEBUG) {
		va_list args;
		va_start(args, fmt);
		vprintf(fmt, args);
		va_end(args);
	}
}

bool AllHex(const string &str) {
	for (size_t i = 0; i < str.size(); ++i) {
		char ch = tolower(str[i]);
		if (!(('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'f'))) {
			return false;
		}
	}
	return true;
}

bool AllDec(const string &str) {
	for (size_t i = 0; i < str.size(); ++i) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}
