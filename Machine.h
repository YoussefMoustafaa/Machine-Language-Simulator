#ifndef A2_MACHINE_MACHINE_H
#define A2_MACHINE_MACHINE_H

#include <bits/stdc++.h>

using namespace std;


class Register {
private:
    static int registers[16];
public:
    static int get_register(int indexR);
    static void write_register(int indexR, int value);
//    void initializeRegisters();
    static void DisplayRegisters();
};


// 14A3
// 20A3
// 35B1
// 40A4


class Memory {
private:
    static int memory[256];
public:
    static int get_memory(int index);
    static void write_memory(int regValue , int memoryIndex);
//    void initializeMemory();
    static void DisplayMemory();
};

// i
// 2 0 01  0
// 2 2 01  1
// 5 1 12  2
// B 1 02  3
// C 0 00  4

class InstructionsMemory {
private:
    vector<string> instList;
public:
    void addInstruction(string& inst);
    int getInstListSize();
    string getInstruction(int index);
};



class Machine {
protected:
    Register reg;
    Memory mem;
    InstructionsMemory instructions;
    static int pc;
    bool halt = false;
public:
    bool isValid(char code);
    bool checkValidInstruction(string& inst);
    void startMachine();
    void execute(string& inst);
    void fetchInstructionsFile(string& filename);
    void runInstructions();
    void displayMiniMenu();
};




class Instructions : public Machine {
public:
//    Instructions();
    void caseOne(int regs, int memo);
    void caseTwo(int regs, int value);
    void caseThree(int regs , int memo);
    void caseFour(string operand_value);
    void caseFive(int regs, string two_registers);
    void caseB(int regs, string& instCell);
    void caseC();
};



#endif //A2_MACHINE_MACHINE_H
