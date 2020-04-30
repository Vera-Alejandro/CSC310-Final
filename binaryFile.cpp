#include "binaryFile.h"

    //public 

binaryFile::binaryFile(/* args */)
{

}

binaryFile::~binaryFile()
{

}

bool binaryFile::_ReadData(int size)
{
    ifstream input_file;
    ofstream output_binary("employee_info.dat", ios::out | ios::binary);
    int inputCount, department, employee_id;
    string file_value, name, temp_string;
    Employee *new_Employee = NULL;

    if (size < 1 || size > 3)
    {
        throw myException("invalid size input", ERROR);
    }

    switch (size)
    {
        case 1:
            cout << "reading from smallOutput text file" << endl;
            input_file.open("smallOutput.txt", ios::in);
            break;
        case 2:
            cout << "reading from mediumOutput text file" << endl;
            input_file.open("mediumOutput.txt", ios::in);
            break;
        case 3:
            cout << "reading from largeOutput text file" << endl;
            input_file.open("largeOutput.txt", ios::in);
            break;
    }

    if (!input_file.is_open()) { throw myException("File Not Open", ERROR); }
    if (!output_binary) { throw myException("Can not open Binary File", ERROR); }
    
    int i = 1;
    while (getline(input_file, file_value))
    {
       stringstream ss(file_value);
       getline(ss, temp_string, ',');
       department = stoi(temp_string);
       getline(ss, temp_string, ',');
       employee_id = stoi(temp_string);
       getline(ss, name, ',');
        
        new_Employee = new Employee(employee_id, department, name);

        output_binary.write((char*)new_Employee, sizeof(Employee));
    }

    cout << endl << endl;

    output_binary.close();
    input_file.close();

    return false;
}


        //Private

///size: 
//1 - smallOutput 
//2 - mediumOutput
//3 - largeOutput
bool binaryFile::ReadData(int size)
{
    try
    {
        return _ReadData(size);
    }
    catch(myException &e)
    {
        cerr << e.what() << endl;
    }
}   