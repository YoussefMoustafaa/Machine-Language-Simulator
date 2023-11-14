#include <bits/stdc++.h>
#include "Machine.h"

using namespace std;


int main() {
    
// opcode  operand
    // 1 4 A3
    //          012345678901
    string file;
    cout << "Enter file name: ";
    cin >> file;
    cout << file << endl;
    Machine M;
    M.fetchInstructionsFile(file);
    return 0;
}
