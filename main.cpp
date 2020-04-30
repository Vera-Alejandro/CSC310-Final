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

    // inputFile.ReadData(0);
    inputFile.ReadData(1);
    // inputFile.ReadData(2);
    // inputFile.ReadData(3);
    inputFile.RetrieveEmployee(4,20);


    return 0;
}