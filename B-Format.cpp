//
//  B-Format.cpp
//  RISC-V Sim
//
//  Created by Youssef Elmahdy on 17/11/2023.
//

#include "B-Format.hpp"

string To_UBin(int n) 
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



int To_UDec(string binary)
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

void B_Format(string Instname, string rs1, string rs2, string address, vector<int> &RF, int &PC)
{
    int rs1val = stoi(rs1.substr(1, rs1.size()+1));
    int rs2val = stoi(rs2.substr(1, rs1.size()+1));
    
    if (Instname == "beq")
    {
        if (RF[rs1val] == RF[rs2val])
            PC = stoi(address) - 4;
        else
            return;
    }
    
    else if (Instname == "bne")
    {
        if (RF[rs1val] != RF[rs2val])
            PC = stoi(address) - 4;
        else
            return;
    }
    
    else if (Instname == "bge")
    {
        if (RF[rs1val] >= RF[rs2val])
            PC = stoi(address) - 4;
        else
            return;
    }
    
    else if (Instname == "blt")
    {
        if (RF[rs1val] < RF[rs2val])
            PC = stoi(address) - 4;
        else
            return;
    }
    else if (Instname == "bgeu")
    {
        string Binrs1 = To_UBin(RF[rs1val]);
        string Binrs2 = To_UBin(RF[rs2val]);
        
        int decrs1 = To_UDec(Binrs1);
        int decrs2 = To_UDec(Binrs2);
        
        if (decrs1 >= decrs2)
            PC = stoi(address) - 4;
        else
            return;
    }
    
    else if (Instname == "bltu")
    {
        string Binrs1 = To_UBin(RF[rs1val]);
        string Binrs2 = To_UBin(RF[rs2val]);
        
        int decrs1 = To_UDec(Binrs1);
        int decrs2 = To_UDec(Binrs2);
        
        if (decrs1 < decrs2)
            PC = stoi(address) - 4;
        else
            return;
    }
    
    else
    {
        cout << "Entered B-Format, but did not find instruction!" << endl;
    }
}
