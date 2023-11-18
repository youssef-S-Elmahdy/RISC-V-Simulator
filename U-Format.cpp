//
//  U-Format.cpp
//  RISC-V Sim
//
//  Created by Youssef Elmahdy on 15/11/2023.
//

#include "U-Format.hpp"

string To_Binary(int n) 
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



int To_Decimal(string binary) 
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


void U_Format(string Instname, string rd, string constant, vector<int> &RF, int &PC)
{
    int rdval = stoi(rd.substr(1, rd.size()+1));
    int constValue = stoi(constant);
    
    if (Instname == "lui")
    {
        string ConstBin = To_Binary(constValue);
        string ValueToStore = ConstBin.substr(0, 19);
        string zeros = "000000000000";
        int DecValue = To_Decimal(ValueToStore+zeros);
        RF[rdval] = DecValue;
    }
    
    else if (Instname == "auipc")
    {
        string ConstBin = To_Binary(constValue);
        string ValueToStore = ConstBin.substr(0, 19);
        string zeros = "000000000000";
        int DecValue = To_Decimal(ValueToStore+zeros);
        RF[rdval] = DecValue + PC;
    }
    
    else
    {
        cout << "Entered U-Format, but did not find instruction!" << endl;
    }
}
