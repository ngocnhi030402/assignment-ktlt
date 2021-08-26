//
//  SLLDataControler.h
//  KTLT ASS 3
//
//  Created by Nhan Nguyen on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Singly Linked List
void print(SLinkedList& list) {
    if (!list.size) {
        std::cout << "List is empty" << endl;
        return;
    }
    SoldierNode* head = list.head;
    while (head) {
        std::cout << head->data.ID << "->";
        head = head->next;
    }
    std::cout << "NULL" << endl;
}
SoldierNode* create_node(Soldier soldier) {
    SoldierNode* temp;
    temp = (SoldierNode*)new(struct SoldierNode);
    temp->next = NULL;
    temp->data = soldier;
    return temp;
}
bool insertAt(SLinkedList& list, Soldier element, int pos) {
    //Insert element into a pos in the SLL
    //Return true if insert successfully, false otherwise
    //TODO
    if (pos < 0 || pos > list.size) {
        return false;
    }
    else if (pos == 0 || list.head==NULL) {
        SoldierNode* temp = create_node(element);
        if (list.head == NULL) {
            list.head = temp;
        }
        else {
            temp->next = list.head;
            list.head = temp;
        }
        list.size++;
        return true;
    }
    else {
        SoldierNode* p = list.head;
        for (int i = 0; i < pos - 1; i++) {
            p = p->next;
        }
        SoldierNode* temp = new SoldierNode;
        temp->data = element;
        temp->next = p->next;
        p->next = temp;
        list.size++;
        return true;
    }
}

bool removeAt(SLinkedList& list, int idx) {
    //Remove element at index idx in the SLL
    //Return true if remove successfully, false otherwise
    //TODO
    if (idx<0 || idx>= list.size || list.head == NULL) {
        return false;
    }
    if (idx == 0) {
        SoldierNode* del = list.head;
        list.head = list.head->next;
        delete del;
        list.size--;
        return true;
    }
    else {
        SoldierNode* p = list.head;
        for (int i = 0; i < idx - 1; i++) {
            p = p->next;
        }
        SoldierNode* temp = p->next;
        p->next = p->next->next;
        delete(temp);
        p = nullptr;
        list.size--;
        return true;
    }
}

bool removeFirstItemWithHP(SLinkedList& list, int HP) {
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    int count = 0;
    if (list.head == NULL || list.size <= 0) return false;
    SoldierNode* temp = list.head;
    for (int i = 0; i < list.size; i++) {
        if (temp->data.HP == HP) {
            count++;
            break;
        }
        temp = temp->next;
    }
    if (count == 0) {
        temp = nullptr;
        return false;
    }
    SoldierNode* pCur = list.head;
    if (pCur->data.HP == HP) {
        list.head = list.head->next;
        delete pCur;
        list.size--;
        return true;
    }
    while (pCur->next != NULL) {
        if (pCur->next->data.HP == HP) {
            SoldierNode* temp = pCur->next;
            pCur->next = pCur->next->next;
            pCur = nullptr;
            delete temp;
            list.size--;
            return true;
        }
        pCur = pCur->next;
    }
    temp = nullptr;
    pCur = nullptr;
    return true;
}

int indexOf(SLinkedList& list, Soldier soldier) {
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    if (list.head == NULL || list.size <= 0) { 
        return -1; 
    }
    SoldierNode* pCur = list.head;
    int count = 0;
    while (pCur != NULL) {
        if (pCur->data.HP == soldier.HP && pCur->data.isSpecial == soldier.isSpecial && pCur->data.ID == soldier.ID) {
            return count;
            break;
        }
        count++;
        pCur = pCur->next;
    }
    pCur = nullptr;
    delete pCur;
    return -1;
}

int size(SLinkedList& list) {
    //Return size of the list
    //TODO
    return list.size;
    //return -1;
}

bool empty(SLinkedList& list) {
    //Check whether the list is empty
    //TODO
    SoldierNode* temp = list.head;
    if (list.head == NULL) {
        delete temp;
        return true;
    }
    temp = nullptr;
    return false;
}

void clear(SLinkedList& list) {
    //Delete all of the elements in list
    //TODO
    SoldierNode* pCur = list.head;
    while (list.head != NULL) {
        list.head = list.head->next;
        delete pCur;
        pCur = list.head;
    }
    delete pCur;
    list.size = 0;
}

string getIDAt(SLinkedList& list, int pos) {
    //Get ID of the Soldier at pos
    //TODO
    //string s = "";
    SoldierNode* temp = list.head;
    int count = 0;
    while (temp != NULL) {
        if (count == pos) {
            return temp->data.ID;
        }
        count++;
        temp = temp->next;
    }
    temp = nullptr;
    return "-1";
}

int getHPAt(SLinkedList& list, int pos) {
    //Get HP of the Soldier at pos
    //TODO
    SoldierNode* temp = list.head;
    int count = 0;
    while (temp != NULL) {
        if (count == pos) {
            return temp->data.HP;
        }
        count++;
        temp = temp->next;
    }
    temp = nullptr;
    delete temp;
    return -1;
}
bool setHPAt(SLinkedList& list, int HP, int pos) {
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    if (pos < 0 || pos>list.size-1 || list.head == NULL) {
        return false;
    }
    else {
        SoldierNode* p = list.head;
        for (int i = 0; i < pos; i++) {
            p = p->next;
        }
        p->data.HP = HP;
        p = nullptr;
        delete p;
        return true;
    }
}

bool contains(SLinkedList& list, Soldier soldier) {
    //Check if array contains soldier
    //TODO
    SoldierNode* temp = list.head;
    while (temp != NULL) {
        if (temp->data.HP == soldier.HP && temp->data.isSpecial == soldier.isSpecial && temp->data.ID == soldier.ID) {
            return true;
        }
        temp = temp->next;
    }
    temp = nullptr;
    delete temp;
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* SLLDataControler_h */

