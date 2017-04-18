#include <iostream>
#include <string>
#include <vector>
#include <openssl/md5.h>
#include "utility.h"
#include "rc4.h"

using namespace std;


void generateKey(const string &pphrase, vector<unsigned char> &res){
	const char *p = pphrase.c_str();
	unsigned char md5_buf[MD5_DIGEST_LENGTH];
	char *s = (char*)malloc(strlen(p)+3);
	cout << "Key= " << p << endl;
    for (int i = 0; i < 16; i++) {
        sprintf(s, "%02d%s", i, p);
        MD5((const unsigned char*)s, strlen(s), md5_buf);
        for (int j = 0; j < (int)sizeof(md5_buf); ++j) {
        	res.push_back(md5_buf[j]);
        }
    }
    free(s);
}

// for i from 0 to 255
//      S[i] := i
// j := 0
// for i from 0 to 255
//		j := (j + S[i] + key[i mod keylength]) mod 256
//		swap(S[i],S[j])
void keyScheduling(
	const vector<unsigned char> &key,
	vector<unsigned char> &S
){
	S.assign(256, 0);
	for (int i = 0; i < 256; ++i) {
		S[i] = (unsigned char)i;
	}
	int j = 0;
	for (int i = 0; i < 256; ++i) {
		j = (j + S[i] + key[i % key.size()]) % 256;
		swap(S[i], S[j]);
	}
}

//i := 0
//j := 0
//while GeneratingOutput:
//    i := (i + 1) mod 256
//    j := (j + S[i]) mod 256
//    swap(S[i],S[j])
//    output S[(S[i] + S[j]) mod 256]
void output(vector<unsigned char> &S, int len){
	int i = 0, j = 0;
	for (int c = 0; c < len; ++c) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(S[i],S[j]);
        cout << S[(S[i] + S[j]) % 256];
    }
}

void RC4(const string &pphrase, int len) {
	vector<unsigned char> key, S;
	generateKey(pphrase, key);
	keyScheduling(key, S);
	output(S, len);
}
