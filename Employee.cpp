#include "binaryFile.h"

        //Public

Employee::Employee(int ID, int department, string name)
{
    this->_ID = ID;
    this->_Department = department;
    this->_Name = name;
}

Employee::~Employee()
{
}

Employee::Employee()
{
}

void Employee::Update(int ID, int department, string name)
{
    _Update(ID, department, name);
}

        //Private

void Employee::_Update(int ID, int department, string name)
{
    this->_ID = ID;
    this->_Department = department;
    this->_Name = name;
}