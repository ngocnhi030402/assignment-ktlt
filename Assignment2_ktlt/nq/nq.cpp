//
//  main.cpp
//  2021S_KTLT_CLC4_W2b
//

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pNext;
};

void inputList(Node*& pHead);
void displayList(Node* pH);
void deleteList(Node*& pHead);
void insertAtBegin(Node*& pHead, int value);
void insert_after_k(Node*& pHead, int x, int k);
void insertBeforeK(Node*& pHead, int x, int k);
void DeleteANode(Node*& pHead, int k);
void delete_X_all(Node*& pHead, int x);
void insertXOrderedList(Node*& pHead, int x);

int main() {
    Node* pHead = nullptr;

    inputList(pHead);
    displayList(pHead);
    int x;
    cout << "pls input number you want to add at beginning\n";
    cin >> x;
    insertAtBegin(pHead, 3); 
    deleteList(pHead);
    return 0;
}

void inputList(Node*& pHead) {
    Node* pCur = nullptr;
    int t;
    cout << "Pls input an integer number (0.Stop): ";
    cin >> t;

    while (t != 0) {
        if (pHead == nullptr) {
            pHead = new Node;
            pCur = pHead;
        }
        else {
            pCur->pNext = new Node;
            pCur = pCur->pNext;
        }
        pCur->data = t;
        pCur->pNext = nullptr;
        cout << "Pls input an integer number (0.Stop): ";
        cin >> t;
    }
}

void displayList(Node* pH) {
    cout << "This is the list: ";
    while (pH != nullptr) {
        cout << pH->data << " ";
        pH = pH->pNext;
    }
    cout << endl;
}

void deleteList(Node*& pHead) {
    Node* pCur = pHead;
    while (pHead != nullptr) {
        pHead = pHead->pNext;
        delete pCur;
        pCur = pHead;
    }
}

void insertAtBegin(Node*& pHead, int value)
{
    Node* temp;
    temp = new Node;
    temp->data = value;
    temp->pNext = pHead;
    pHead = temp;
}

//void insert_after_k(Node*& pHead, int x, int k) {
//    Node* pcur = pHead;
//    while (pcur != nullptr) {
//        if (pcur->data == k) {
//            Node* temp1 = pcur;
//            pcur = new Node;
//            pcur->data = x;
//            pcur->pNext = temp1->pNext;
//            temp1->pNext = pcur;
//            break;
//        }
//        pcur = pcur->pNext;
//    }
//}

void insertAfterK(Node* pCur, int x, int k) {
    while (pCur != nullptr && pCur->data != k)
        pCur = pCur->pNext;
    if (pCur != nullptr) { //pCur->data==k
        Node* pTmp = new Node;
        pTmp->data = x;
        pTmp->pNext = pCur->pNext;
        pCur->pNext = pTmp;
    }
}
void insertBeforeK(Node*& pHead, int x, int k)
{
    if (pHead == nullptr) return;
    if (pHead->data == k)
        insertAtBegin(pHead, x);
    else {
        Node* pCur = pHead;
        while (pCur->pNext != nullptr && pCur->pNext->data != k)
            pCur = pCur->pNext;
        if (pCur->pNext != nullptr) {
            Node* pTmp = new Node;
            pTmp->data = x;
            pTmp->pNext = pCur->pNext;
            pCur->pNext = pTmp;
        }
    }
}

void DeleteANode(Node*& pHead, int k) {
    if (pHead == nullptr) return;

    Node* pCur = pHead;
    if (pHead->data == k) {
        pHead = pHead->pNext;
        delete pCur;
        return;
    }

    while (pCur->pNext != nullptr) {
        if (pCur->pNext->data == k) {
            Node* temp = pCur->pNext;
            pCur->pNext = pCur->pNext->pNext;
            delete temp;
            return;
        }
        pCur = pCur->pNext;
    }
}

void delete_X_all(Node*& pHead, int x) {
    //if (pHead==nullptr) return;

    Node* pNow = pHead;
    while (pNow != nullptr && pNow->pNext != nullptr) {
        if (pNow->pNext->data == x) {
            Node* pLink;
            pLink = pNow->pNext->pNext;
            delete pNow->pNext;
            pNow->pNext = pLink;
        }
        else pNow = pNow->pNext;
    }

    if (pHead != nullptr && pHead->data == x) {
        Node* pLink;
        pLink = pHead;
        pHead = pHead->pNext;
        delete pLink;
    }
}

void insertXOrderedList(Node*& pOH, int x) {
    Node* p = new Node;
    p->data = x;
    if (pOH == nullptr || x <= pOH->data) {
        p->pNext = pOH;
        pOH = p;
    }
    else {
        Node* pCur = pOH;
        while (pCur->pNext != nullptr && pCur->pNext->data < x) pCur = pCur->pNext;
        p->pNext = pCur->pNext;
        pCur->pNext = p;
    }
}
