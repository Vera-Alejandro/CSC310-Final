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
        exit(2);
    }
    
}


void Employee::Update(int ID, int department)
{
    _Update(ID, department);
}

/////////////////////////////////////////////////Private//////////////////////////////////////////////////////////////

Employee Employee:: _RetrieveEmployee(int id_input, int department_input)
{
    string name_out;
    char flag = 'n';

    ifstream search("employee_info.dat", ios::in | ios::binary);

    Employee retrieve;

    if(!search) {
        cout << "Cannot open file!" << endl;
    }


    while(!search.eof())
    {
        search.read((char *)&retrieve, sizeof(retrieve));
        //cout << "ID test: " << retrieve.returnID() << " Department Test: " << retrieve.returnDepartment() << " Name Test: " << retrieve.returnName() << endl;
        if(retrieve.returnID() == id_input && retrieve.returnDepartment() == department_input)
        {
            flag = 'y';
            name_out = retrieve.returnName();
            break;
        }
    }
    if(flag == 'f')
    {
        cout<<"No Record in file"<<endl;
        exit(2);
    }

    search.close();
    if(!search.good()){
        cout << "Error Occured during read" << endl;
        exit(2);
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

void Employee::_Update(int id_input, int department_input)
{
    string name_out;
    char flag = 'n';

    ifstream search("employee_info.dat", ios::in | ios::binary);

    Employee retrieve;;

    if(!search) {
        cout << "Cannot open file!" << endl;
    }

    while(!search.eof())
    {
        search.read((char *)&retrieve, sizeof(retrieve));
        //cout << "ID test: " << retrieve.returnID() << " Department Test: " << retrieve.returnDepartment() << " Name Test: " << retrieve.returnName() << endl;
        if(retrieve.returnID() == id_input && retrieve.returnDepartment() == department_input)
        {
            flag = 'y';
            cout<< "Enter updated name: ";
            cin >> name_out;
            break;
        }
    }
    if(flag == 'f')
    {
        cout<<"No Record in file"<<endl;
        exit(2);
    }

    search.close();
    if(!search.good()){
        cout << "Error Occured during read" << endl;
        exit(2);
    }
    
}