#include "present.h"

Present::Present(string key) {
    //TODO set custom rounds
    if (key.size() == 10) {
        uberzahl u = convertToNumber(key);
        for (int i = 0; i < 32; i++) {
            keys[i] = u >> 16;
            u = ((u & (uberzahl(1) << 19) - 1) << 61) + (u >> 19);
            u = (uberzahl(sbox[(u >> 76) % 16]) << 76) +  (u & ((uberzahl(1) << 76)- 1));
            u = u ^ (uberzahl(i + 1) << 15);
        }
    } else if (key.size() == 16) {
        uberzahl u = convertToNumber(key);
        for (int i = 0; i < 32; i++) {
            keys[i] = u >> 64;
            u = ((u & (uberzahl(1) << 67) - 1) << 61) + (u >> 67);
            u = (uberzahl(sbox[(u >> 124) % 16]) << 124)
                    + (uberzahl(sbox[(u >> 120) % 16]) << 120)
                    + (u & ((uberzahl(1) << 120)- 1));
            u = u ^ (uberzahl(i + 1) << 62);
        }
    } else {
        cout << "key size should be either 80bits or 128 bits" << endl;
    }
}

string Present::encrypt(string message) {
    return message;
}

string Present::decrypt(string cipher) {
    uberzahl u = convertToNumber(cipher);
    cout <<  cipher.size() << endl;
    cout << u << endl;
    for (int i = 0; i < 31; i++) {
        u = u ^ keys[31 - i];
        uberzahl u2;
        for (int j = 0; j < 64; j++) {
            u2 = u2 + (((u >> j) & 1) << pbox_inv[j]);
        }
        uberzahl u3;
        for (int j = 0; j < 16; j++) {
            u3 = u3 + (uberzahl(sbox_inv[(u2 >> (j * 4)) % 16]) << (j * 4));
        }
        u = u3;
    }
    u = u ^ keys[0];
    return convertToString(u);
}

uberzahl Present::convertToNumber(string s) {
    uberzahl result;
    for (int i = 0; i < s.length(); i++) {
        result = (result << 8) + s[i];
    }
    return result;
}

string Present::convertToString(uberzahl u) {
    string result = "";
    while (u != uberzahl()) {
        result = result + (char)(u % 256);
        u = u >> 8;
    }
    reverse(result.begin(), result.end());
    return result;
}
