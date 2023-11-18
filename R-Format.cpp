//
//  R-Format.cpp
//  RISC-V Sim
//
//  Created by Youssef Elmahdy on 12/11/2023.
//

#include "R-Format.hpp"

string to_UBin(int n)
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



int to_UDec(string binary)
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

void R_Format(string Instname, string rd, string rs1, string rs2, vector<int> &RF)
{
    int rs1val = stoi(rs1.substr(1, rs1.size()+1));
    int rs2val = stoi(rs2.substr(1, rs1.size()+1));
    string rdvalTemp = rd.substr(1, rd.size()+1);
    int rdval = stoi(rdvalTemp);
    
    if (Instname == "add")
    {
        RF[rdval] = RF[rs1val] + RF[rs2val];
    }
    else if (Instname == "sub")
    {
        RF[rdval] = RF[rs1val] - RF[rs2val];
    }
    else if (Instname == "xor")
    {
        RF[rdval] = RF[rs1val] ^ RF[rs2val];
    }
    else if (Instname == "or")
    {
        RF[rdval] = RF[rs1val] | RF[rs2val];
    }
    else if (Instname == "and")
    {
        RF[rdval] = RF[rs1val] & RF[rs2val];
    }
    else if (Instname == "sll")
    {
        RF[rdval] = RF[rs1val] << RF[rs2val];
    }
    else if (Instname == "srl")
    {
        RF[rdval] = RF[rs1val] >> RF[rs2val];
    }
    else if (Instname == "sra")
    {
        RF[rdval] = RF[rs1val] >> RF[rs2val];
    }
    else if (Instname == "slt")
    {
        if (RF[rs1val] < RF[rs2val])
        {
            RF[rdval] = 1;
        }
        else
        {
            RF[rdval] = 0;
        }
    }
    else if (Instname == "sltu")
    {
        string Binrs1 = to_UBin(RF[rs1val]);
        string Binrs2 = to_UBin(RF[rs2val]);
        
        int decrs1 = to_UDec(Binrs1);
        int decrs2 = to_UDec(Binrs2);
        
        if (decrs1 < decrs2)
        {
            RF[rdval] = 1;
        }
        else
        {
            RF[rdval] = 0;
        }
    }
    else
    {
        cout << "Entered R-Format, but did not find instruction!" << endl;
    }
}
