#include <iostream>
#include "customErrorClass.h"
#include "binaryFile.h"

/////////////////////////////////////////////////////////////////////

    //read - ale 
    //sort - drew
    //search - drew
    //retreive from binary file - garrett
    //update - garrett
    //impliment exception handling - ale 

/////////////////////////////////////////////////////////////////////

int main()
{

    binaryFile inputFile;
    Employee newEmployee;
    Employee receipt;

    // inputFile.ReadData(0);
    inputFile.ReadData(1);
    // inputFile.ReadData(2);
    // inputFile.ReadData(3);
    receipt = newEmployee.RetrieveEmployee(74993,0);
    cout << "does it come outof the retreive function???" << endl;

    //sort.Sort()

    cout << endl << "this code works" << endl;


    return 69;
}