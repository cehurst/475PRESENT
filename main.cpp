#include <iostream>
#include <string>
#include "present.h"

using namespace std;
int main() {
    Present p("1234567890123456");
    string c = p.encrypt("12345678");
    cout << c << endl;
    string m = p.decrypt(c);
    cout << m << endl;
//    cout << p.convertToNumber("01");
}
