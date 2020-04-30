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

int Employee:: returnID()
{
    return this->_ID;
}

int Employee:: returnDepartment()
{
    return this->_Department;
}

string Employee:: returnName()
{
    return this->_Name;
}

void Employee:: showData()
{
    cout << "ID: " << returnID() << endl;
    cout << "Department: " << returnDepartment() << endl;
    cout << "Name: " << returnName() << endl;
}


Employee Employee:: RetrieveEmployee(int ID, int department)
{
    Employee bad;
    try
    {
        return _RetrieveEmployee(ID, department);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return bad;
    }
    
}


void Employee::Update(int ID, int department)
{
    _Update(ID, department);
}

/////////////////////////////////////////////////Private//////////////////////////////////////////////////////////////

Employee Employee:: _RetrieveEmployee(int ID, int department)
{
    int id_input;
    int department_input;
    string name_out;

    ifstream search("employee_info.dat", ios::binary);

    Employee retrieve;
    Employee bad;

    if(!search) {
        cout << "Cannot open file!" << endl;
    }



    while(search.read((char*)&retrieve, sizeof(retrieve)))
    {
        if(retrieve.returnID() == id_input && retrieve.returnDepartment() == department_input)
        {
            name_out = retrieve.returnName();
        }
    }

    search.close();
    if(!search.good()){
        cout << "Error Occured during read" << endl;
        return bad;
    }



    cout << "Employee Details: " << endl;
    cout << "ID: " << id_input << endl;
    cout << "Department: " << department_input << endl;
    cout << "Name: " << name_out << endl;

    retrieve._ID = id_input;
    retrieve._Department = department_input;
    retrieve._Name = name_out;

    return retrieve;
    
}

void Employee::_Update(int ID, int department)
{
    string name;
    int id_input;
    int department_input;

    fstream update;
    update.open("employee_info.dat", ios::binary);

    Employee updatedEmployee;

    while(update.read((char*)&updatedEmployee, sizeof(updatedEmployee)))
    {
        if(updatedEmployee.returnID() == id_input && updatedEmployee.returnDepartment() == department_input)
        {
            cout << "Enter new name: ";
            cin >> updatedEmployee._Name;

            int pos = -1 * sizeof(updatedEmployee);
            update.seekp(pos, ios::cur);

            update.write((char*)&updatedEmployee, sizeof(updatedEmployee));
        }
    }

    
}