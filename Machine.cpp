#include "Machine.h"
#include <bits/stdc++.h>
#include <fstream>




// 14A3
// 20A3
// 35B1
// 40A4
void Register::write_register(int indexR, int value) {
    registers[indexR] = value;
    cout << registers[indexR] << " found in register " << hex << indexR << endl;
}



int Register::get_register(int indexR) {
    int regsValue = registers[indexR] ;
    return regsValue;
}

void Register::initializeArr() {
    for (int i = 0; i < 16; ++i) {
        registers[i] = 0;
    }
}


int Memory::get_memory(int index) {
    return memory[index];
}



void Memory::write_memory(int regValue, int memoryIndex) {
    memory[memoryIndex] = regValue;
    cout << memory[memoryIndex] << " found in memory " << hex << memoryIndex << endl;
}

void Memory::initializeMemory() {
    for (int i = 0; i < 256; ++i) {
        memory[i] = 0;
    }
}


// 1 4 A3
void Instructions::caseOne(int regs, int memo) {
    int memory_value = this->mem.get_memory(memo);
    this->reg.write_register(regs, memory_value);
}

// 2 0 A3
void Instructions::caseTwo(int regs, int value) {
    this->reg.write_register(regs, value);
}



void Instructions::caseThree(int regs, int memo) {
    int regsValue = this->reg.get_register(regs);
    this->mem.write_memory(regsValue , memo);
}



Instructions::Instructions() {
    this->reg.initializeArr();
    this->mem.initializeMemory();
}


// A3
void Instructions::caseFour(string operand_value) {
    string value1_string, value2_string;

    value1_string += operand_value[2];
    value2_string += operand_value[3];

    int value1 = stoi(value1_string, nullptr, 16);
    int value2 = stoi(value2_string, nullptr, 16);

    int register_value = this->reg.get_register(value1);

    this->reg.write_register(value2, register_value);
}

void Instructions::caseFive(int regs, string two_values) {
    string value1_string, value2_string;

    value1_string += two_values[2];
    value2_string += two_values[3];

    int value1 = stoi(value1_string, nullptr, 16);
    int value2 = stoi(value2_string, nullptr, 16);

    int result = value1 & value2;

    this->reg.write_register(regs, result);
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

    static Instructions i;

    // 2 0 A3

    switch (opCode) {
        case 1:
            i.caseOne(regs, memo);
            break;
        case 2:
            i.caseTwo(regs, memo);
            break;
        case 3:
            i.caseThree(regs , memo);
            break;
        case 4:
            i.caseFour(operand_mem);
            break;
        case 5:
            i.caseFive(regs, operand_mem);
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

    fstream instFile("./" + filename);

    string line;

    while (getline(instFile, line))
    {
        cout << line << endl;
        execute(line);
    }

}

Machine::Machine() {
    pc = 0x0;
}

