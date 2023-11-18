#include "RISC-V.hpp"


RISC_V::RISC_V(string instruction, vector<int> &RF, vector<vector<string>> &Mem, int &PC, char &T)
{
    long int space = instruction.find(" ");
    InstName = instruction.substr(0, space);
    
    if (InstName == "add" || InstName == "sub" || InstName == "xor" || InstName == "or" || InstName == "and" || InstName == "sll" || InstName == "srl" || InstName == "sra" || InstName == "slt" || InstName == "sltu")
    {
        R_Sim(instruction, RF);
    }
    else if (InstName == "addi" || InstName == "xori" || InstName == "ori" || InstName == "andi" || InstName == "slli" || InstName == "srli" || InstName == "srai" || InstName == "slti" || InstName == "sltiu" || InstName == "jalr" || InstName == "lw" || InstName == "lb" || InstName == "lbu" || InstName == "lh" || InstName == "" || InstName == "lhu")
    {
        I_Sim(instruction, RF, Mem, PC);
    }
    else if (InstName == "sb" || InstName == "sh" || InstName == "sw")
    {
        S_Sim(instruction, RF, Mem);
    }
    else if (InstName == "jal")
    {
        J_Sim(instruction, RF, Mem, PC);
    }
    else if (InstName == "lui" || InstName == "auipc")
    {
        U_Sim(instruction, RF, PC);
    }
    else if (InstName == "beq" || InstName == "bne" || InstName == "bge" || InstName == "blt" || InstName == "bgeu" || InstName == "bltu")
    {
        B_Sim(instruction, RF, Mem, PC);
    }
    else
        T = 'n';
    
    PC = PC + 4;
    RF[0] = 0;
    
}

void RISC_V::R_Sim(string instruction, vector<int> &RF)
{
    string rd = "", rs1 = "", rs2 = "";
    
    long int space = instruction.find(" ");
    instruction.erase(0, space+1);
    
    long int Firstcomma = instruction.find(",");
    rd = instruction.substr(0, Firstcomma);
    instruction.erase(0, Firstcomma+1);
    
    long int SecondComma = instruction.find(",");
    rs1 = instruction.substr(0, SecondComma);
    instruction.erase(0, SecondComma+1);
    
    rs2 = instruction;
    
    R_Format(InstName, rd, rs1, rs2, RF);
}

void RISC_V::I_Sim(string instruction, vector<int> &RF, vector<vector<string>> &Mem, int &PC)
{
    char Type;
    string rd = "", rs1 = "", immediate = "";
    
    if (instruction.find('(') != -1)
    {
        Type = 'O';
    }
    else
        Type = 'C';
    
    if (Type == 'O')
    {
        long int space = instruction.find(" ");
        instruction.erase(0, space+1);
        
        long int Firstcomma = instruction.find(",");
        rd = instruction.substr(0, Firstcomma);
        instruction.erase(0, Firstcomma+1);
        
        long int FirstBracket = instruction.find("(");
        immediate = instruction.substr(0, FirstBracket);
        instruction.erase(0, FirstBracket+1);
        
        long int SecondBracket = instruction.find(")");
        rs1 = instruction.substr(0, SecondBracket);
    }
    else
    {
        long int space = instruction.find(" ");
        instruction.erase(0, space+1);
        
        long int Firstcomma = instruction.find(",");
        rd = instruction.substr(0, Firstcomma);
        cout << rd << endl;
        instruction.erase(0, Firstcomma+1);
        
        long int SecondComma = instruction.find(",");
        rs1 = instruction.substr(0, SecondComma);
        cout << rs1 << endl;
        instruction.erase(0, SecondComma+1);
        
        immediate = instruction;
        cout << immediate << endl;
    }
    
    I_Format(InstName, rd, rs1, immediate, RF, Mem, PC);
}

void RISC_V::S_Sim(string instruction, vector<int> &RF, vector<vector<string>> &Mem)
{
    string rs2 = "", immediate = "",rs1 = "";
    
    long int space = instruction.find(" ");
    instruction.erase(0, space+1);
    
    long int Firstcomma = instruction.find(",");
    rs2 = instruction.substr(0, Firstcomma);
    instruction.erase(0, Firstcomma+1);
    
    long int FirstBracket = instruction.find("(");
    immediate = instruction.substr(0, FirstBracket);
    instruction.erase(0, FirstBracket+1);
    
    long int SecondBracket = instruction.find(")");
    rs1 = instruction.substr(0, SecondBracket);
    instruction.erase(SecondBracket, SecondBracket+1);
    
    S_Format(InstName, rs2, rs1, immediate, RF, Mem);
}

void RISC_V::J_Sim(string instruction, vector<int> &RF, vector<vector<string>> &Mem, int &PC)
{
    string rd = "", address = "";
    
    long int space = instruction.find(" ");
    instruction.erase(0, space+1);
    
    long int Firstcomma = instruction.find(",");
    rd = instruction.substr(0, Firstcomma);
    instruction.erase(0, Firstcomma+1);
    
    address = instruction;
    
    J_Format(InstName, rd, address, RF, Mem, PC);
}

void RISC_V::U_Sim(string instruction, vector<int> &RF, int &PC)
{
    string rd = "", constant = "";
    
    long int space = instruction.find(" ");
    instruction.erase(0, space+1);
    
    long int Firstcomma = instruction.find(",");
    rd = instruction.substr(0, Firstcomma);
    instruction.erase(0, Firstcomma+1);
    
    constant = instruction;
    
    U_Format(InstName, rd, constant, RF, PC);
}

void RISC_V::B_Sim(string instruction, vector<int> &RF, vector<vector<string>> &Mem, int &PC)
{
    string rs1 = "", rs2 = "", address = "";
    
    long int space = instruction.find(" ");
    instruction.erase(0, space+1);
    
    long int Firstcomma = instruction.find(",");
    rs1 = instruction.substr(0, Firstcomma);
    instruction.erase(0, Firstcomma+1);
    
    long int SecondComma = instruction.find(",");
    rs2 = instruction.substr(0, SecondComma);
    instruction.erase(0, SecondComma+1);
    
    address = instruction;
    
    B_Format(InstName, rs1, rs2, address, RF, PC);
}







