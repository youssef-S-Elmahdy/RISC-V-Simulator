//
//  B-Format.hpp
//  RISC-V Sim
//
//  Created by Youssef Elmahdy on 17/11/2023.
//

#ifndef B_Format_hpp
#define B_Format_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <stdexcept>
#include <cmath>
#include <vector>
using namespace std;

string To_UBin(int n);
int To_UDec(string binary);
void B_Format(string Instname, string rs1, string rs2, string address, vector<int> &RF, int &PC);
#endif /* B_Format_hpp */
