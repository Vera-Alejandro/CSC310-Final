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
    e_NODE* first = _createNode(0);
    _first = first;
}

NODE* Employee::getCurrent()
{
    return this->_first;
}

int Employee::returnID()
{
    return this->_ID;
}

int Employee::returnDepartment()
{
    return this->_Department;
}

void Employee::Sort(int ID, int department)
{
    _Sort(ID, department);
}

bool Employee::Search(int ID, int department)
{
    int found = _Search(ID, department);

    if (found == -1) {
        return false;
    }
    else {
        return true;
    }
}

void Employee::Update(int ID, int department)
{
    _Update(ID, department);
}


//Private

string Employee::returnName()
{
    return this->_Name;
}

void Employee::showData()
{
    cout << "ID: " << returnID() << endl;
    cout << "Department: " << returnDepartment() << endl;
    cout << "Name: " << returnName() << endl;
}

Employee Employee::RetrieveEmployee(int ID, int department)
{
    try
    {
        return _RetrieveEmployee(ID, department);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(2);
    }
}


/////////////////////////////////////////////////Private//////////////////////////////////////////////////////////////

Employee Employee::_RetrieveEmployee(int id_input, int department_input)
{
    string name_out;
    char flag = 'n';

    ifstream search("employee_info.dat", ios::in | ios::binary);

    // Employee* retrieve = new Employee;
    Employee retrieve;

    if (!search) { throw myException("Cannot open file!", INFORMATIONAL); }


    while (!search.eof())
    {
        search.read((char*)&retrieve, sizeof(&retrieve));

        if (retrieve.returnID() == id_input && retrieve.returnDepartment() == department_input)
        {
            flag = 'y';
            name_out = retrieve.returnName();
            break;
        }
    }

    if (flag == 'f') { throw myException("No Record in file", INFORMATIONAL); }

    search.close();

    if (!search.good()) { throw myException("Error Occured during read", INFORMATIONAL); }

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

    if (!search) { throw myException("Cannot open file!", INFORMATIONAL); }

    while (!search.eof())
    {
        search.read((char*)&retrieve, sizeof(&retrieve));
        if (retrieve.returnID() == id_input && retrieve.returnDepartment() == department_input)
        {
            flag = 'y';
            cout << "Enter updated name: ";
            cin >> name_out;
            break;
        }
    }

    if (flag == 'f') { throw myException("No Record in file", INFORMATIONAL); }

    search.close();

    if (!search.good()) { throw myException("Error Occured during read", INFORMATIONAL); }
}

NODE* Employee::_createNode(int value)
{
    NODE* new_node = new NODE;

    if (new_node == NULL) { throw myException("node creation failed", INFORMATIONAL); }

    new_node->value = value;
    new_node->next = NULL;

    return new_node;
}

void Employee::_addNode(NODE* insert_node)
{
    NODE* move = _first;

    while (_first->next != NULL)
    {
        move = _first->next;
    }

    move->next = insert_node;

    return;
}
void Employee::_loadEmployees()
{
    string name_out;
    char flag = 'n';

    ifstream search("employee_info.dat", ios::in | ios::binary);

    Employee retrieve;;

    if (!search) { throw myException("Cannot open file!", INFORMATIONAL); }

    while (!search.eof())
    {
        search.read((char*)&retrieve, sizeof(&retrieve));
        _addNode(_createNode(retrieve._ID));
    }

    if (flag == 'f') { throw myException("No Record in file", INFORMATIONAL); }

    search.close();

    if (!search.good()) { throw myException("Error Occured during read", INFORMATIONAL); }
}


void Employee::_Sort(int ID, int department)
{
    NODE* node = new NODE;
    node->value = department;
    node->secondValue = ID;

    NODE* tmp = NULL;
    NODE* search = _first;


    while (search != NULL && search->next != NULL) 
    {

        if (node->secondValue > node->next->secondValue) 
        {
            tmp->secondValue = node->current->secondValue;
            node->current->secondValue = node->next->secondValue;
            node->next->secondValue = tmp->secondValue;
        }
        if (search->next != NULL) {
            search = search->next;
        }

    }

    search = _first;

    while (search != NULL && search->next != NULL)
    {

        if (node->value > node->next->value)
        {
            tmp->value = node->current->value;
            node->current->value = node->next->value;
            node->next->value = tmp->value;
        }
        if (search->next != NULL) {
            search = search->next;
        }
    }

    search = _first;

    while (search != NULL && search->next != NULL) 
    {
        cout << node->value << ", " << node->secondValue << endl;
        if (search->next != NULL) {
            search = search->next;
        }
    }
}

int Employee::_Search(int ID, int department) {

    NODE* search;
    int count = 0;
    search = _first;

    while (search != NULL) {
        if (search->value == department && search->secondValue == ID) {
            return count;
        }
        search = search->next;
        count++;
    }
    return -1;

}