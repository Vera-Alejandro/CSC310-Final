#ifndef __BINARY_FILE__H__
#define __BINARY_FILE__H__

#include "customErrorClass.h"
#include <iostream>
#include <typeinfo>
#include <fstream>
#include <sstream>

using namespace std;

typedef struct NODE {
    int value, secondValue;
    bool isSorted = false;
    NODE* current;
    NODE* next;
}e_NODE;

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
    e_NODE* _first;
    NODE* _createNode(int value);
    void _addNode(NODE* insert_node);
    int _Search(int ID, int department);
    void _Update(int ID, int department);
    void _Sort(int ID, int department);
    Employee _RetrieveEmployee(int ID, int department);
    void _loadEmployees();

public:
    Employee();
    Employee(int ID, int department, string name);
    ~Employee();
    bool Search(int ID, int department);
    int returnDepartment();
    int returnID();
    void showData();
    void Sort(int ID, int department);
    void Update(int ID, int department);
    Employee RetrieveEmployee(int ID, int department);
    NODE* getCurrent();
    string returnName();
};

#endif