#include "present.h"

Present::Present(string key) {
    if (key.size() == 10) {
        uberzahl u = convertToNumber(key);
        for (int i = 0; i < 32; i++) {
            keys[i] = u >> 16;
            u = ((u & (uberzahl(1) << 19) - 1) << 61) + (u >> 19);
            u = (uberzahl(sbox[(u >> 76) % 16]) << 76) +  (u & ((uberzahl(1) << 76)- 1));
            u = u ^ (uberzahl(i + 1) << 15);
        }
    }
}

string Present::encrypt(string message) {
    return message;
}

string Present::decrypt(string cipher) {
    return cipher;
}

uberzahl Present::convertToNumber(string s) {
    uberzahl result;
    for (int i = 0; i < s.length(); i++) {
        result = (result << 8) + s[i];
    }
    return result;
}

string Present::convertToString(uberzahl u) {
    return "";
}
