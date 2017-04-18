#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <vector>
#include "utility.h"

using namespace std;

const bool DEBUG = true;

void CountZeroOneBits(unsigned char byte, int &n0, int &n1) {
	for (int i = 0; i < 8; ++i) {
		unsigned char bit = (byte >> i) & 0x1;
		n0 += bit == 0;
		n1 += bit == 1;
	}
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

bool IthBit(const string &bytes, int i) {
	return bytes[i/8] & (1 << (7-i%8));
}

unsigned RangeBits(const string &bytes, int i, int len) {
	unsigned ans = 0;
	for (int c = i; c < i+len; c++) {
		ans = (ans << 1) | IthBit(bytes, c);
	}
	return ans;
}

double SquareSumVec(const vector<int> &vec) {
	double sum = 0;
	for (size_t i = 0; i < vec.size(); i++){
		sum += 1.0*vec[i]*vec[i];
	}
	return sum;
}

string DecToBinary(unsigned num, int len) {
	string ans;
	while (num) {
		ans += '0' + (num & 0x1);
		num >>= 1;
	}
	while ((int)ans.size() < len) {
		ans += '0';
	}
	return string(ans.begin(), ans.end());
}
