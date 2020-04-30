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

e_NODE* Employee::getCurrent(){
    return this->_first;
}

void Employee::Update(int ID, int department, string name)
{
    _Update(ID, department, name);
}

void Employee::Sort(int ID, int department){

    _Sort(ID, department);
}

bool Employee::Search(int ID, int department){

    int found;
    _Search(ID, department);

    if(found == -1){
        return false;
    }else{
        return true;
    }
}


        //Private

void Employee::_Update(int ID, int department, string name)
{
    this->_ID = ID;
    this->_Department = department;
    this->_Name = name;
}

void Employee::_Sort(int ID, int department){

    binaryFile inputFile;
    e_NODE *node = new NODE;
    node->value = department;
    node->secondValue = ID;

    e_NODE *tmp;
    e_NODE *search = _first;


    while(search->next->next != NULL){

        if(node->secondValue > node->next->secondValue){
            tmp->secondValue = node->current->secondValue;
            node->current->secondValue = node->next->secondValue;
            node->next->secondValue = tmp->secondValue;
        }
        search = search->next;
    }

    search = _first;

    while(search->next->next != NULL){

        if(node->value > node->next->value){
            tmp->value = node->current->value;
            node->current->value = node->next->value;
            node->next->value = tmp->value;
        }
        search = search->next;
    }

    search = _first;

    while(search->next->next != NULL){
        cout<<node->value<<", "<<node->secondValue<<endl;
    }


    /*while(department = 0){

        for(int i = 0; (inputFile.ReadData).length; i++){

            if(node->secondValue > node->next->secondValue){
            tmp = node->current;
            node->current = node->next;
            node->next = tmp;
            }
        }

    }
    while(department = 1){

        for(int i = 0; (inputFile.ReadData).length; i++){
            
            if(node->secondValue > node->next->secondValue){
            tmp = node->current;
            node->current = node->next;
            node->next = tmp;
            }
        }

    }
    while(department = 2){

        for(int i = 0; (inputFile.ReadData).length; i++){
            
            if(node->secondValue > node->next->secondValue){
            tmp = node->current;
            node->current = node->next;
            node->next = tmp;
            }
        }

    }

    while(department = 3){

        for(int i = 0; (inputFile.ReadData).length; i++){
            
            if(node->secondValue > node->next->secondValue){
            tmp = node->current;
            node->current = node->next;
            node->next = tmp;
            }
        }

    }

    while(department = 4){

        for(int i = 0; (inputFile.ReadData).length; i++){
            
            if(node->secondValue > node->next->secondValue){
            tmp = node->current;
            node->current = node->next;
            node->next = tmp;
            }
        }

    }*/


}

int Employee::_Search(int ID, int department){

    e_NODE *search;
    int count = 0;
    search = _first;

    while(search != NULL){
        if(search->value == department && search->secondValue == ID){
            return count;
        }
        search = search->next;
        count++;
    }
    return -1;

}


