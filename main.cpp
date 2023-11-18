#include <iostream>
#include <cstring>
#include <string>
#include "RISC-V.hpp"
using namespace std;

void Exit()
{
    cout << "Thanks for using our Program" << endl;
    cout << "Created by Hussein Heggi and Yousef Elmahdy" << endl;
    exit(EXIT_SUCCESS);
}

void Operation()
{
    int PC = 0;
    int start = 0;
    char c;
    char T = 'y';
    int n = 0;
    int bad = 0;
    string value;
    int ValAdd;
    string instruction;
    vector<string> E(0);
    vector<vector<string>> Mem(0, vector<string>(2));
    vector<string>MemBin;
    vector<int> RF(32,0);

    cout << "Please specify the starting address:" << endl;
    cin >> start;
    cout << "---------------------------------------------------------------" << endl;
    
    ifstream File("/Users/s7s/Desktop/test.txt");
    string line;
    while (getline(File, line))
    {
        E.push_back(line);
    }
    File.close();
    
    
    for (int i = 0; i < E.size(); i++)
    {
        Mem.push_back({to_string(start + i*4), E[i]});
    }
    
    cout << "Press 'y' to initialize data in the memory:" << endl;
    cin >> c;
    tolower(c);
    cout << "---------------------------------------------------------------" << endl;
    
    while (c == 'y')
    {
        cout << "How many Values you want to intialize in the memory sequentially: ";
        cin >> n;
        cout << "---------------------------------------------------------------" << endl;
        
        cout << "Specify the base address of the values: ";
        cin >> ValAdd;
        cout << "---------------------------------------------------------------" << endl;
        
        cout << "Specify which register you want to hold the base address:";
        cin >> bad;
        cout << "---------------------------------------------------------------" << endl;
        
        RF[bad] = ValAdd;
        
        for (int i = 0; i < n; i++)
        {
            cout << "Enter Value " << i << " : ";
            cin >> value;
            Mem.push_back({to_string(ValAdd + i*4), value});
        }
        
        cout << "---------------------------------------------------------------" << endl;
        cout << "Press 'y' to initialize more data in the memory:" << endl;
        cin >> c;
        tolower(c);
        
    }
    
    PC = start;
    long int End = PC + E.size() * 4;
    
    while (PC <= End)
    {
        instruction = E[(PC - start)/4];
        
        if (instruction == "ecall" || instruction == "ebreak" || instruction == "fence")
            break;
        
        else if (T == 'n')
        {
            cout << "Error: Unidentified instruction Format in the program" << endl;
            break;
        }
        
        else
        {
            RISC_V(instruction, RF, Mem, PC, T);
            if (T != 'n')
            {
                cout << "===============================================================" << endl;
                for (int i = 0; i < 32; i++)
                {
                    cout << "Register " << i << " : " << RF[i] << endl;
                }
                cout << "---------------------------------------------------------------" << endl;
                for (int i = 0; i < Mem.size(); i++)
                {
                    cout << "Address: " << Mem[i][0] << " contains: " << Mem[i][1] << endl;
                }
            }
        }
    }
    
    cout << "---------------------------------------------------------------" << endl;
    cout << "Simulation Ended" << endl;
}

int main()
{
    cout << "===============================================================" << endl;
    cout << setw(40) << "RISC-V Simulator" << endl;
    int q = 0;

    cout << "===============================================================" << endl;
    cout << "How can I help you?" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "1- Simulate a RISC-V program" << endl;
    cout << "2- Exit" << endl;
    cin >> q;
    
    cout << "---------------------------------------------------------------" << endl;
    
    switch (q)
        {
            case 1:
                Operation();
                Exit();
                break;

            case 2:
                Exit();
                break;

            default:
                cout << "---------------------------------------------------------------" << endl;
                cout << "Wrong Input, please try again" << endl;
                cout << "---------------------------------------------------------------" << endl;
                break;
        }
}

