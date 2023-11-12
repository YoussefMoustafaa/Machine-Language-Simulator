#ifndef A2_MACHINE_MACHINE_H
#define A2_MACHINE_MACHINE_H

#include <bits/stdc++.h>

using namespace std;


class Register {
private:
    int arr[16];
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



class Machine {
protected:
    Register reg;
    Memory mem;
public:
    void execute(string inst);
    void fetchInstructions(string filename);
    void startMachine();
};




class Instructions : public Machine {
public:
    void caseOne(int regs, int memo);
    void caseTwo(int regs, int value);
    void caseThree(int regs , int memo);
};



#endif //A2_MACHINE_MACHINE_H
