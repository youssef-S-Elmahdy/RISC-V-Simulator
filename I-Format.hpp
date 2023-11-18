//
//  I-Format.hpp
//  RISC-V Sim
//
//  Created by Youssef Elmahdy on 17/11/2023.
//

#ifndef I_Format_hpp
#define I_Format_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <stdexcept>
#include <cmath>
#include <vector>
using namespace std;

int UDec(string binary);
string to_Bin(int n);
int to_Dec(string binary);
void I_Format(string Instname, string rd, string rs1, string imm, vector<int> &RF, vector<vector<string>> &Mem, int &PC);

#endif /* I_Format_hpp */
