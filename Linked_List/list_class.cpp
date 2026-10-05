#include<iostream>
using namespace std;

class linkedlist{
private:
    int data;
    linkedlist* next;
public:
    linkedlist(){
        this->data = 0;
        this->next = nullptr;
    }

    linkedlist(int val){
        this->data = val;
        this->next = nullptr;
    }

    linkedlist(int val, linkedlist* ll){
        this->data = val;
        this->next = ll;
    }

    void convert(int arr[], int size){
        if(size < 1) return;
        linkedlist* temp = this;
        for(int i=1;i<size;i++){
            linkedlist* node = new linkedlist(arr[i]);
            temp->next = node;
            temp = temp->next;
        }
    }

    void deleteHead(linkedlist*& ll){
        if(ll == nullptr) return;
        linkedlist* temp = ll;
        ll = ll->next;
        delete temp;
        temp = nullptr;
    }

    void deleteTail(linkedlist*& ll){
        if(ll == nullptr || ll->next == nullptr) return;
        linkedlist* temp = ll;
        while(temp->next->next != nullptr) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteElement(linkedlist*& ll, int k){
        if(k < 1) return;
        if(ll == nullptr) return;
        if(k == 1){
            linkedlist* temp = ll;
            ll = ll->next;
            delete temp;
            temp = nullptr;
            return;
        }

        linkedlist* temp = ll;
        linkedlist* prev = nullptr;
        int count = 0;
        while(temp){
            count++;
            if(count == k){
                prev->next = temp->next;
                delete temp;
                temp = nullptr;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

    }

    void deleteValue(linkedlist*& ll, int k){
        if(ll == nullptr) return;
        if(ll->data == k){
            deleteHead(ll);
            return;
        }
        linkedlist* temp = ll;
        linkedlist* prev = nullptr;
        while(temp){
            if(temp->data == k){
                prev->next = temp->next;
                delete temp;
                temp = nullptr;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

    }

    void insertHead(linkedlist*& ll, int val){
        linkedlist* temp = new linkedlist(val);
        temp->next = ll;
        ll = temp;
        return;
    }

    void insertTail(linkedlist*& ll, int val){
        if(ll == nullptr){
            ll = new linkedlist(val);
            return;
        }
        linkedlist* temp = ll;
        while(temp->next) temp = temp->next;
        linkedlist* node = new linkedlist(val);
        temp->next = node;
    }

    void insertAtPos(linkedlist*& ll, int val, int pos){
        if(ll == nullptr && pos == 1){
            ll = new linkedlist(val);
            return;
        }
        if(pos == 1){
            insertHead(ll, val);
            return;
        }

        linkedlist* temp = ll;
        int count = 0;
        while(temp){
            count++;
            if(count == pos-1){
                linkedlist* node = new linkedlist(val,temp->next);
                temp->next = node;
                return;
            }
            temp = temp->next;
        }
    }

    void insertBeforeVal(linkedlist*& ll, int val, int x){
        if(ll == nullptr) return;
        if(ll->data == val){
            insertHead(ll, x);
            return;
        }

        linkedlist* temp = ll;
        int count = 0;
        while(temp->next){
            if(temp->next->data == val){
                linkedlist* node = new linkedlist(x,temp->next);
                temp->next = node;
                return;
            }
            temp = temp->next;
        }
    }

    void print(){
        if(this == nullptr) return;
        cout << this->data << " ";
        this->next->print();
    }

};

int main(){

    int arr[5] = {1,2,3,4,5};
    linkedlist* ll = new linkedlist(arr[0]);
    ll->convert(arr,5);
    ll->insertHead(ll, 50);
    ll->insertTail(ll,50);
    ll->insertAtPos(ll,99,8);
    ll->insertBeforeVal(ll,5,88);
    ll->print();

    return 0;
}