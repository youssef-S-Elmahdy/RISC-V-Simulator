//
//  S-Format.cpp
//  RISC-V Sim
//
//  Created by Youssef Elmahdy on 13/11/2023.
//

#include "S-Format.hpp"

string to_Binary(int n) 
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



int to_Decimal(string binary) 
{
    long int n = binary.length();

    int sign = (binary[0] == '1') ? -1 : 1;

    int decimal = 0;
    for (long int i = n - 1; i > 0; --i) 
    {
        if (binary[i] == '1') 
        {
            decimal += pow(2, n - i - 1);
        }
    }

    decimal *= sign;

    return decimal;
}

void S_Format(string Instname, string rs2, string rs1, string imm, vector<int> &RF, vector<vector<string>> &Mem)
{
    int rs1val = stoi(rs1.substr(1, rs1.size()+1));
    int rs2val = stoi(rs2.substr(1, rs2.size()+1));
    int immediate = stoi(imm);
    int MemLoc = RF[rs1val] + immediate;
    bool found = false;
    
    for (int i = 0; i < Mem.size(); i++)
    {
        if (Mem[i][0] == to_string(MemLoc))
        {
            found = true;
        }
    }
    if (found == false)
    {
        Mem.push_back({to_string(MemLoc), to_string(0)});
    }
    
    if (Instname == "sb")
    {
        int Value = RF[rs2val];
        string ValueBin = to_Binary(Value);
        string ValueToStore = ValueBin.substr(24,31);
        int DecValue = to_Decimal(ValueToStore);
        for (int i = 0; i < Mem.size(); i++)
        {
            if (Mem[i][0] == to_string(MemLoc))
            {
                Mem[i][1] = to_string(DecValue);
            }
        }
    }
    
    else if (Instname == "sh")
    {
        int Value = RF[rs2val];
        string ValueBin = to_Binary(Value);
        string ValueToStore = ValueBin.substr(16,31);
        int DecValue = to_Decimal(ValueToStore);
        for (int i = 0; i < Mem.size(); i++)
        {
            if (Mem[i][0] == to_string(MemLoc))
            {
                Mem[i][1] = to_string(DecValue);
            }
        }
    }
    
    else if (Instname == "sw")
    {
        int Value = RF[rs2val];
        
        for (int i = 0; i < Mem.size(); i++)
        {
            if (Mem[i][0] == to_string(MemLoc))
            {
                Mem[i][1] = to_string(Value);
            }
        }
    }
    
    else
    {
        cout << "Entered S-Format, but did not find instruction!" << endl;
    }
}
