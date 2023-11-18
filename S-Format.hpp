//
//  S-Format.hpp
//  RISC-V Sim
//
//  Created by Youssef Elmahdy on 13/11/2023.
//

#ifndef S_Format_hpp
#define S_Format_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <stdexcept>
#include <cmath>
#include <vector>
using namespace std;


string to_Binary(int n);
int to_Decimal(string binary);
void S_Format(string Instname, string rs2, string rs1, string imm, vector<int> &RF, vector<vector<string>> &Mem);




#endif /* S_Format_hpp */
