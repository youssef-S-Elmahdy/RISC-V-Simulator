//
//  U-Format.hpp
//  RISC-V Sim
//
//  Created by Youssef Elmahdy on 15/11/2023.
//

#ifndef U_Format_hpp
#define U_Format_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <stdexcept>
#include <cmath>
#include <vector>
using namespace std;

string To_Binary(int n);
int To_Decimal(string binary);
void U_Format(string Instname, string rd, string constant, vector<int> &RF, int &PC);

#endif /* U_Format_hpp */
