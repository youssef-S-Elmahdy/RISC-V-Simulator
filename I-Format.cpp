//
//  I-Format.cpp
//  RISC-V Sim
//
//  Created by Youssef Elmahdy on 17/11/2023.
//

#include "I-Format.hpp"

int UDec(string binary)
{
    int decimal = 0;
    int power = 1;

        for (long int i = binary.length() - 1; i >= 0; i--)
        {
            if (binary[i] == '1')
            {
                decimal += power;
            }
            power *= 2;
        }
    return decimal;
}

string to_Bin(int n)
{
    if (n >= 0) 
    {
        return bitset<32>(n).to_string();
    }

    bitset<32> positiveBits(-n);
    positiveBits.flip();

    positiveBits = positiveBits.to_ulong() + 1;

    return positiveBits.to_string();
}

int to_Dec(string binary) 
{
    long int n = binary.length();

    int sign = (binary[0] == '1') ? -1 : 1;

    int decimal = 0;
    for (long int i = n - 1; i > 0; --i) 
    {
        if (binary[i] == '1') {
            decimal += pow(2, n - i - 1);
        }
    }

    decimal *= sign;

    return decimal;
}


void I_Format(string Instname, string rd, string rs1, string imm, vector<int> &RF, vector<vector<string>> &Mem, int &PC)
{
    int rdval = stoi(rd.substr(1, rd.size()+1));
    int rs1val = stoi(rs1.substr(1, rs1.size()+1));
    int immval = stoi(imm);
    int MemLoc = RF[rs1val] + immval;
    bool found = false;
    
    for (int i = 0; i < Mem.size(); i++)
    {
        if (Mem[i][0] == to_string(MemLoc))
        {
            found = true;
        }
    }
    
    if (Instname == "addi")
    {
        RF[rdval] = RF[rs1val] + immval;
    }
    
    else if (Instname == "xori")
    {
        RF[rdval] = RF[rs1val] ^ immval;
    }
    
    else if (Instname == "ori")
    {
        RF[rdval] = RF[rs1val] | immval;
    }
    
    else if (Instname == "andi")
    {
        RF[rdval] = RF[rs1val] & immval;
    }
    
    else if (Instname == "slli")
    {
        RF[rdval] = RF[rs1val] << immval;
    }
    
    else if (Instname == "srli" || Instname == "srai")
    {
        RF[rdval] = RF[rs1val] >> immval;
    }
    
    else if (Instname == "slti")
    {
        if (RF[rs1val] < immval)
        {
            RF[rdval] = 1;
        }
        else
        {
            RF[rdval] = 0;
        }
    }
    
    else if (Instname == "sltiu")
    {
        string Binrs1 = to_Bin(RF[rs1val]);
        int decrs1 = UDec(Binrs1);
        
        if (decrs1 < immval)
        {
            RF[rdval] = 1;
        }
        else
        {
            RF[rdval] = 0;
        }
    }
    
    else if (Instname == "lw")
    {
        for (int i = 0; i < Mem.size(); i++)
        {
            if (Mem[i][0] == to_string(MemLoc))
            {
                RF[rdval] = stoi(Mem[i][1]);
            }
        }
    }
    
    else if (Instname == "lb")
    {
        int Value = 0;
        for (int i = 0; i < Mem.size(); i++)
        {
            if (Mem[i][0] == to_string(MemLoc))
            {
                Value = stoi(Mem[i][1]);
            }
        }
        string ValueBin = to_Bin(Value);
        string ValueToStore = ValueBin.substr(24,31);
        int DecValue = to_Dec(ValueToStore);
        
        RF[rdval] = DecValue;
    }
    
    else if (Instname == "lbu")
    {
        int Value = 0;
        for (int i = 0; i < Mem.size(); i++)
        {
            if (Mem[i][0] == to_string(MemLoc))
            {
                Value = stoi(Mem[i][1]);
            }
        }
        string ValueBin = to_Bin(Value);
        string ValueToStore = ValueBin.substr(24,31);
        int DecValue = UDec(ValueToStore);
        
        RF[rdval] = DecValue;
    }
    
    else if (Instname == "lh")
    {
        int Value = 0;
        for (int i = 0; i < Mem.size(); i++)
        {
            if (Mem[i][0] == to_string(MemLoc))
            {
                Value = stoi(Mem[i][1]);
            }
        }
        string ValueBin = to_Bin(Value);
        string ValueToStore = ValueBin.substr(16,31);
        int DecValue = to_Dec(ValueToStore);
        
        RF[rdval] = DecValue;
    }
    
    else if (Instname == "lhu")
    {
        int Value = 0;
        for (int i = 0; i < Mem.size(); i++)
        {
            if (Mem[i][0] == to_string(MemLoc))
            {
                Value = stoi(Mem[i][1]);
            }
        }
        string ValueBin = to_Bin(Value);
        string ValueToStore = ValueBin.substr(16,31);
        int DecValue = UDec(ValueToStore);
        
        RF[rdval] = DecValue;
    }
    else if (Instname == "jalr")
    {
        RF[rdval] = PC;
        PC = RF[rs1val] + immval - 4;
    }
    
    else
    {
        cout << "Entered I-Format, but did not find instruction!" << endl;
    }
    
}
