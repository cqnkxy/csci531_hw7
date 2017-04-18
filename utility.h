#ifndef __UTILITY_H_
#define __UTILITY_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// Print the first 256 bytes of the input in hex. You must print a '\n'
// character for every 32 hex characters you print. If the input has
// less than 256 bytes and the input size is not a multiple of 16 bytes, 
// please also print a \n' character after the last line of the printout.
void CountZeroOneBits(unsigned char byte, int &n0, int &n1);
void HexDumpVec(const std::vector<unsigned char>&);
void Fatal(const char *fmt, ...);
void Fprint(const char *fmt, ...);
bool AllHex(const std::string &);
bool AllDec(const std::string &);
// Return the ith bit of the bytes. Doesn't check for index out of range.
bool IthBit(const std::string &bytes, int i);
// Start at the ith bit and take len bits
unsigned RangeBits(const std::string &bytes, int i, int len);
double SquareSumVec(const std::vector<int> &vec);
// Padding 0 in front to meet length of len if necessary
std::string DecToBinary(unsigned num, int len);

#endif
