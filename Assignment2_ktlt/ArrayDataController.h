//
//  ArrayDataController.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef ArrayDataController_h
#define ArrayDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Array
void print(Array& array) {
    if (!array.size) {
        std::cout << "Array is empty" << endl;
        return;
    }
    std::cout << "[";
    for (int i = 0; i < array.size; i++) {
        std::cout << array.arr[i].ID << " ";
    }
    std::cout << "]" << endl;
}

void initArray(Array& array, int cap) {
    //Init a new array with capacity equals to cap
    //TODO
    array.capacity = cap;
    array.arr = new Soldier[cap];
}

bool insertAt(Array& array, Soldier element, int pos) {
    //Insert element into a pos in the array
    //Return true if insert successfully, false otherwise
    //TODO
    if (pos < 0 || pos > array.size || array.capacity <0) {
        return false;
    }
    Array a;
    a.size = array.size + 1;
    a.arr = new Soldier[array.size + 1];
    for (int i = array.size; i > pos; i--) {
        a.arr[i] = array.arr[i - 1];
    }
    a.arr[pos] = element;
    for (int i = pos - 1; i >= 0; i--) {
        a.arr[i] = array.arr[i];
    }
    array.arr = new Soldier[array.size + 1];
    array.size++;
    for (int i = 0; i < a.size; i++) {
        array.arr[i] = a.arr[i];
    }
    a.arr = nullptr;
    delete a.arr;
    return true;
}

bool removeAt(Array& array, int idx) {
    //Remove element at index idx in the array
    //Return true if remove successfully, false otherwise
    //TODO
    if (idx < 0 || idx >= array.size) {
        return false;
    }
    else if ( array.size == 1) {
        array.size--;
        array.arr = nullptr;
        return true;
    }
    else {
        for (int i = idx; i < array.size - 1; i++) {
            array.arr[i] = array.arr[i + 1];
        }
        array.size--;
        return true;
    }
    array.arr = nullptr;
    delete array.arr;
}

bool removeFirstItemWithHP(Array& array, int HP) {
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    if (array.size <= 0 || array.arr == NULL) {
        return false;
    }
    int count = 0;
    for (int i = 0; i < array.size; i++) {
        if (array.arr[i].HP == HP) {
            count++;
        }
    }
    if (count == 0) {
        return false;
    }
    else {
        for (int i = 0; i < array.size; i++) {
            if (array.arr[i].HP == HP) {
                for (int j = i; j < array.size; j++) {
                    array.arr[j] = array.arr[j + 1];
                }
                array.size--;
                break;
            }
        }
        return true;
    }
}

void ensureCapacity(Array& array, int newCap) {
    //Extend the capacity of the array
    //TODO
    array.capacity = newCap;
    array.arr = new Soldier[newCap];
}

int indexOf(Array& array, Soldier soldier) {
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    for (int i = 0; i < array.size; i++) {
        if (array.arr[i].HP == soldier.HP && array.arr[i].isSpecial == soldier.isSpecial && array.arr[i].ID == soldier.ID) {
            return i;
            break;
        }
    }
    return -1;
    //return -2;
}

int size(Array& array) {
    //Return size of the array
    //TODO
    return array.size;
    //return -1;
}

bool empty(Array& array) {
    //Check whether the array is empty
    //TODO
    if (array.size <= 0 || array.arr == NULL) {
        return true;
    }
    return false;
}

string getIDAt(Array& array, int pos) {
    //Get ID of the Soldier at pos
    //TODO
    for (int i = 0; i < array.size; i++) {
        if (i == pos) {
            return array.arr[i].ID;
        }
    }
    return "-1";
}

int getHPAt(Array& array, int pos) {
    //Get HP of the Soldier at pos
    //TODO
    for (int i = 0; i < array.size; i++) {
        if (i == pos) {
            return array.arr[i].HP;
        }
    }
    return -1;
}

bool setHPAt(Array& array, int HP, int pos) {
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    if (pos < 0 || pos >= array.size || array.arr == NULL) {
        return false;
    }
    array.arr[pos].HP = HP;
    return true;
    //return false;
}

void clear(Array& array) {
    //Delete all of the elements in array
    //TODO
    for (int i = 0; i < array.size; i++) {
        removeAt(array, i);
    }
    array.size = 0;
    array.capacity = -1;
}

bool contains(Array& array, Soldier soldier) {
    //Check if array contains soldier
    //TODO
    for (int i = 0; i < array.size; i++) {
        if (array.arr[i].HP == soldier.HP && array.arr[i].isSpecial == soldier.isSpecial && array.arr[i].ID == soldier.ID) {
            return true;
        }
    }
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* ArrayDataController_h */
