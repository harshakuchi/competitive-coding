#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArrToDLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++) {
        Node* temp = new Node(arr[i]);
        temp->back = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printDLL(Node* head) {
    Node* temp = head;
    while(temp!=nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

void* insertStart(Node* &head, int data) {
    Node* newNode = new Node(data);
    if(head == nullptr) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head->back = newNode;
        head = newNode;
    }
}

void insertEnd(Node* &head, int data) {
    Node* newNode = new Node(data);
    if(head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->back = temp;
    }
}

void insertAtPosK(Node* &head, int data, int k) {
    if(k == 1) {
        insertStart(head, data);
        return;
    }
    Node* temp = head;
    int cnt = 0;
    while(temp!=nullptr) {
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(data);
    newNode->back = prev;
    newNode->next = temp;
    prev->next = newNode;
    temp->back = newNode;
}

Node* deleteStart(Node* head) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* deleteEnd(Node* head) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head;
    Node* prev = head;
    while(temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }
    temp->back = nullptr;
    prev->next = nullptr;
    delete temp;
    return head;
}

Node* deleteAtPosK(Node* head, int k) {
    if(head == nullptr) return nullptr;
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr) {
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    // case1: empty DLL
    if(prev == nullptr && front == nullptr) {
        return nullptr;
    }
    // case2: prev is null, that means the kth node is head
    else if(prev == nullptr) {
        return deleteStart(head);
    }
    // case3: front == null, so kth node is tail
    else if(front == nullptr) {
        return deleteEnd(head);
    }
    // case4: in the middle
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

void reverse(Node* &head) {
    if(head == nullptr || head->next == nullptr) return;
    Node* prev = nullptr, *cur = head;
    while(cur != nullptr) {
        prev = cur->back;
        cur->back = cur->next;
        cur->next = prev;

        cur = cur->back;
    }
    head = prev->back;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArrToDLL(arr);
    insertStart(head, 0);
    insertEnd(head, 6);
    deleteAtPosK(head, 4);
    insertAtPosK(head, 3, 4);
    reverse(head);
    printDLL(head);
    return 0;
}