//
//  R-Format.hpp
//  RISC-V Sim
//
//  Created by Youssef Elmahdy on 12/11/2023.
//

#ifndef R_Format_hpp
#define R_Format_hpp

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string to_UBin(int);
int to_UDec(string);
void R_Format(string Instname, string rd, string rs1, string rs2, vector<int> &RF);



#endif /* R_Format_hpp */
