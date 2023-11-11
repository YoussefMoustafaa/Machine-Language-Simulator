#include "Machine.h"
#include <bits/stdc++.h>
#include <fstream>




// 14A3
// 20A3
// 35B1
// 40A4
void Register::write_register(int indexR, int value) {
    arr[indexR] = value;
    cout << arr[indexR] << endl;
}

int Memory::get_memory(int index) {
    return memory[index];
}


// 1 4 A3
void Instructions::caseOne(int reg, int mem) {

    int memory_value = memIn.get_memory(mem);

}

//            012345678901
//           "0x1 0x0 0xF3"

// B

void Machine::execute(string inst) {

    string code = inst.substr(0, 3);
    int opCode = stoi(code, nullptr, 16);

    string operand_reg = inst.substr(4, 3);
    int regs = stoi(operand_reg, nullptr, 16);

    string operand_mem = inst.substr(8, 4);
    int memo = stoi(operand_mem, nullptr, 16);

    Instructions i;

    switch (opCode) {
        case 1:
            i.caseOne(regs, memo);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 11: // B
            break;
        case 12: // C
            break;
        default:
            break;
    }

}


void Machine::fetchInstructions(string filename) {

    fstream instructionsFile("./" + filename);

    string line;
    while (getline(instructionsFile, line))
    {
        execute(line);
    }

}
