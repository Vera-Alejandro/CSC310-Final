#ifndef __BINARY_FILE__H__
#define __BINARY_FILE__H__

#include "customErrorClass.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class binaryFile
{
private:
    bool _ReadData(int size);
public:
    binaryFile();
    ~binaryFile();
    bool ReadData(int size);
    bool RetrieveData(int ID, int department);
};

class Employee
{
private:
    int _ID;
    int _Department;
    string _Name;

    void _Update(int ID, int department);
    Employee _RetrieveEmployee(int ID, int department);
public:
    Employee();
    Employee(int ID, int department, string name);
    ~Employee();
    void Update(int ID, int department);
    Employee RetrieveEmployee(int ID, int department);
    void showData();
    int returnID();
    int returnDepartment();
    string returnName();

};

#endif