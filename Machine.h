#ifndef A2_MACHINE_MACHINE_H
#define A2_MACHINE_MACHINE_H

#include <bits/stdc++.h>

using namespace std;


class Register {
private:
    int registers[16];
public:
    int get_register(int indexR);
    void write_register(int indexR, int value);
    void initializeArr();
};


// 14A3
// 20A3
// 35B1
// 40A4


class Memory {
private:
    int memory[256];
public:
    int get_memory(int index);
    void write_memory(int regValue , int memoryIndex);
    void initializeMemory();
};


class InstructionsMemory {
private:
    string inst[256];
public:
    string get_instruction();
};



class Machine {
protected:
    Register reg;
    Memory mem;
    InstructionsMemory instructions;
    static int pc;
public:
    Machine();
    void execute(string inst);
    void fetchInstructions(string filename);
};




class Instructions : public Machine {
public:
    Instructions();
    void caseOne(int regs, int memo);
    void caseTwo(int regs, int value);
    void caseThree(int regs , int memo);
    void caseFour(string operand_value);
    void caseFive(int regs, string two_values);
};



#endif //A2_MACHINE_MACHINE_H
