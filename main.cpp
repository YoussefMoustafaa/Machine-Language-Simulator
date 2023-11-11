#include <bits/stdc++.h>

using namespace std;


int main() {

// opcode  operand
    // 1 4 A3
    //          012345678901
    string m = "0xFF";

    string opCode = m.substr(0, 4);
    int n = stoi(opCode, nullptr, 16);

    cout << n;

    return 0;
}
