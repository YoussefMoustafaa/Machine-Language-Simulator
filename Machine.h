#ifndef A2_MACHINE_MACHINE_H
#define A2_MACHINE_MACHINE_H

#include <bits/stdc++.h>

using namespace std;


class Register {
private:
    int arr[16] = {0};
public:
    int get_register();
    void write_register(int indexR, int value);
};


// 14A3
// 20A3
// 35B1
// 40A4


class Memory {
private:
    int memory[256] = {0};
public:
    int get_memory(int index);
    void write_memory();
};



class Machine {
protected:
    Register reg;
    Memory mem;
public:
    void execute(string inst);
    void fetchInstructions(string filename);
};




class Instructions : public Machine {
private:
    Register regIn = reg;
    Memory memIn = mem;
public:
    void caseOne(int reg, int mem);
};



#endif //A2_MACHINE_MACHINE_H
