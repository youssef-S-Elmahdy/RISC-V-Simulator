//
//  J-Format.cpp
//  RISC-V Sim
//
//  Created by Youssef Elmahdy on 14/11/2023.
//

#include "J-Format.hpp"

void J_Format(string Instname, string rd, string address, vector<int> &RF, vector<vector<string>> &Mem, int &PC)
{
        int rdval = stoi(rd.substr(1, rd.size()+1));
        bool found = false;
    
        for (int i = 0; i < Mem.size(); i++)
        {
            if (Mem[i][0] == address)
            {
                found = true;
            }
        }
    
        if (found == false)
        {
            Mem.push_back({address, to_string(0)});
        }
    
        if (Instname == "jal")
        {
            RF[rdval] = PC;
            PC = stoi(address) - 4;
        }
    
        else
        {
            cout << "Entered J-Format, but did not find instruction!" << endl;
        }
}
