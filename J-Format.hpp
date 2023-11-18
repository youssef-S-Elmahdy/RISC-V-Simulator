//
//  J-Format.hpp
//  RISC-V Sim
//
//  Created by Youssef Elmahdy on 14/11/2023.
//

#ifndef J_Format_hpp
#define J_Format_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <stdexcept>
#include <cmath>
#include <vector>
using namespace std;

void J_Format(string Instname, string rd, string address, vector<int> &RF, vector<vector<string>> &Mem, int &PC);


#endif /* J_Format_hpp */
