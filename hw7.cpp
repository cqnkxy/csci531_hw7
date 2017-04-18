#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "utility.h"
#include "rc4.h"
#include "x1.h"
#include "x2.h"
#include "x3.h"
#include "x4.h"
#include "x5.h"

using namespace std;

void malformed_command() {
	const string USAGE = 
		"\b\thw7 rc4 -p=pphrase [-l=len]\n"
    	"\b\thw7 x1 [file]\n"
    	"\b\thw7 x2 [file]\n"
    	"\b\thw7 x3 [file]\n"
    	"\b\thw7 x4 [file]\n"
    	"\b\thw7 x5 -d=dval [file]\n";
	cerr << "Malformed command. Use it as:" << endl << USAGE << endl;
	exit(1);
}

void parse_rc4(int argc, char *argv[]) {
	if (argc != 3 && argc != 4) {
		malformed_command();
	}
	string pphrase;
	int len = 0;
	for (int i = 2; i <= argc-1; ++i) {
		string opt(argv[i]);
		if (opt.substr(0, 3) == "-p=") {
			pphrase = opt.substr(3, -1);
		} else if (opt.substr(0, 3) == "-l=") {
			len = atoi(opt.substr(3, -1).c_str());
		} else {
			malformed_command();
		}
	}
	if (argc == 3) {
		len = -1;
	}
	RC4(pphrase, len);
}

void parse_x1(int argc, char *argv[]) {
	if (argc != 2 && argc != 3) {
		malformed_command();
	}
	if (argc == 2) {
		X1(cin);
	} else {
		ifstream in(argv[2]);
		if (!in.is_open()) {
			Fatal("%s can't be opened!\n");
		}
		X1(in);
		in.close();
	}
}

void parse_x2(int argc, char *argv[]) {
	if (argc != 2 && argc != 3) {
		malformed_command();
	}
	if (argc == 2) {
		X2(cin);
	} else {
		ifstream in(argv[2]);
		if (!in.is_open()) {
			Fatal("%s can't be opened!\n");
		}
		X2(in);
		in.close();
	}
}

void parse_x3(int argc, char *argv[]) {
	if (argc != 2 && argc != 3) {
		malformed_command();
	}
	if (argc == 2) {
		X3(cin);
	} else {
		ifstream in(argv[2]);
		if (!in.is_open()) {
			Fatal("%s can't be opened!\n");
		}
		X3(in);
		in.close();
	}
}

void parse_x4(int argc, char *argv[]) {
	if (argc != 2 && argc != 3) {
		malformed_command();
	}
	if (argc == 2) {
		X4(cin);
	} else {
		ifstream in(argv[2]);
		if (!in.is_open()) {
			Fatal("%s can't be opened!\n");
		}
		X4(in);
		in.close();
	}	
}

void parse_x5(int argc, char *argv[]) {
	if (argc != 4 && argc != 3) {
		malformed_command();
	}
	string opt(argv[2]);
	if (opt.substr(0, 3) != "-d=" || !AllDec(opt.substr(3, -1))) {
		malformed_command();
	}
	if (argc == 3) {
		X5(cin, atoi(opt.substr(3, -1).c_str()));
	} else {
		ifstream in(argv[3]);
		if (!in.is_open()) {
			Fatal("%s can't be opened!\n");
		}
		X5(in, atoi(opt.substr(3, -1).c_str()));
		in.close();
	}	
}

void parse_cmd_run(int argc, char *argv[]) {
	if (argc < 2) {
		malformed_command();
	} else if (strcmp(argv[1], "rc4") == 0) {
		parse_rc4(argc, argv);
	} else if (strcmp(argv[1], "x1") == 0) {
		parse_x1(argc, argv);
	} else if (strcmp(argv[1], "x2") == 0) {
		parse_x2(argc, argv);
	} else if (strcmp(argv[1], "x3") == 0) {
		parse_x3(argc, argv);
	} else if (strcmp(argv[1], "x4") == 0) {
		parse_x4(argc, argv);
	} else if (strcmp(argv[1], "x5") == 0) {
		parse_x5(argc, argv);
	} else {
		malformed_command();
	}
}

int main(int argc, char *argv[]) 
{
	parse_cmd_run(argc, argv);
	return 0;
}
