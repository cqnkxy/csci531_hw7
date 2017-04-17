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
size_t HexDumpInput(std::istream&);
void CountZeroOneBits(unsigned char byte, size_t &n0, size_t &n1);
void HexDumpVec(const std::vector<unsigned char>&);
void Fatal(const char *fmt, ...);
void Fprint(const char *fmt, ...);
bool AllHex(const std::string &);
bool AllDec(const std::string &);

#endif
