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
    //newEmployee.Update(74993, 0);


    return 0;
}