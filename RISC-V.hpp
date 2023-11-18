
#ifndef RISC_V_hpp
#define RISC_V_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <fstream>
#include <iostream>
#include "R-Format.hpp"
#include "S-Format.hpp"
#include "J-Format.hpp"
#include "U-Format.hpp"
#include "I-Format.hpp"
#include "B-Format.hpp"
#include <vector>
using namespace std;
class RISC_V
{
public:
    string InstName;
    RISC_V(string, vector<int> &, vector<vector<string>> &, int &, char &);
    void R_Sim(string, vector<int> &);
    void I_Sim(string, vector<int> &, vector<vector<string>> &, int &);
    void S_Sim(string, vector<int> &, vector<vector<string>> &);
    void J_Sim(string, vector<int> &, vector<vector<string>> &, int &);
    void U_Sim(string, vector<int> &, int &);
    void B_Sim(string, vector<int> &, vector<vector<string>> &, int &);
};
#endif
