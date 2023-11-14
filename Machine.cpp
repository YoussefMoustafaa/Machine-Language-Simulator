#include "Machine.h"
#include <bits/stdc++.h>
#include <fstream>




// 14A3
// 20A3
// 35B1
// 40A4
void Register::write_register(int indexR, int value) {
    registers[indexR] = value;
    cout << registers[indexR] << " found in R" << hex << indexR << endl;
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


// 3 0 B5
void Instructions::caseThree(int regs, int memo) {
    int regsValue = this->reg.get_register(regs);
    this->mem.write_memory(regsValue , memo);
}


int Machine::pc = 0x0;


Instructions::Instructions() {
    this->reg.initializeArr();
    this->mem.initializeMemory();
}

// R4 = RA
// 4 0 A4
void Instructions::caseFour(string operand_value) {
    string value1_string, value2_string;

    value1_string += operand_value[2]; // A
    value2_string += operand_value[3]; // 4

    int value1 = stoi(value1_string, nullptr, 16);
    int value2 = stoi(value2_string, nullptr, 16);

    int register_value = this->reg.get_register(value1);

    this->reg.write_register(value2, register_value);
}

// 012345678901
// 0x5 0x7 0x26
void Instructions::caseFive(int regs, string two_registers) {
    string register1_string, register2_string;

    register1_string += two_registers[2];
    register2_string += two_registers[3];

    int register1 = stoi(register1_string, nullptr, 16);
    int register2 = stoi(register2_string, nullptr, 16);

    int register_value1 = this->reg.get_register(register1);
    int register_value2 = this->reg.get_register(register2);

    int result = register_value1 + register_value2;

    this->reg.write_register(regs, result);
}

// B 4 3C
void Instructions::caseB(int regs, string& instCell) {

    int register0_value = this->reg.get_register(0);
    int registerN_value = this->reg.get_register(regs);

    if (register0_value == registerN_value) { // if true, then we want to jump to instList of index instCell

        int new_cell = stoi(instCell, nullptr, 16);

        pc = new_cell;

    }
    // else do nothing
}

void Instructions::caseC() {
    isRunning = true;
}

//            012345678901
//           "0x1 0x0 0xF3"

// B


void Machine::execute(string inst) {
    // 012345678901
    // 0x1 0x4 0xA3
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
            i.caseB(regs, operand_mem);
            break;
        case 12: // C
            i.caseC();
            break;
    }

}


void Machine::fetchInstructionsFile(string filename) {

    fstream instFile("./" + filename);

    string line;

    while (getline(instFile, line))
    {
        cout << line << endl;
        instructions.addInstruction(line);
    }

    runInstructions();

}

//Machine::Machine() {
//    pc = 0x0;
//}

void Machine::runInstructions() {
    int n = instructions.getInstListSize();
    while (pc < n) {

        string instruct = instructions.getInstruction(pc);

        pc++;

        execute(instruct);

        if (isRunning)
            break;
    }
}

void InstructionsMemory::addInstruction(string& inst) {
    instList.push_back(inst);
}

int InstructionsMemory::getInstListSize() {
    return instList.size();
}

string InstructionsMemory::getInstruction(int index) {
    return instList[index];
}
