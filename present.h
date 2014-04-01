#include <string>
#include <iostream>
#include "uberzahl/uberzahl.h"
using namespace std;
class Present {
public:
    Present(string key);
    string encrypt(string message);
    string decrypt(string cipher);
    uberzahl convertToNumber(string s);
private:
    string convertToString(uberzahl u);
    unsigned char sbox[16] = {0xc,0x5,0x6,0xb,0x9,0x0,0xa,0xd,0x3,0xe,0xf,0x8,0x4,0x7,0x1,0x2};
    uberzahl keys[32];
};
