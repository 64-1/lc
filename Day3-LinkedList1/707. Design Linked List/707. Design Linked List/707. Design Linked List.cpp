#include <iostream>

class MyLinkedList {
private:
    int value;
    int size;
    MyLinkedList* next;
public:
    MyLinkedList() {
        value = 0;
        size = 0;
        next = NULL;
    }

    int get(int index) {
        MyLinkedList* current = next;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        return current->value;
    }

    void addAtHead(int val) {
        MyLinkedList* aNewNode = new MyLinkedList();
        aNewNode->value = val;
        aNewNode->next = next;
        next = aNewNode;
        size++;
    }

    void addAtTail(int val) {
        MyLinkedList* tail = new MyLinkedList();
        tail->value = val;

        MyLinkedList* current = next;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = tail;
        size++;
    }

    void addAtIndex(int index, int val) {
        MyLinkedList* current = next;
        if (index == size)
        {
            current->addAtTail(val);
        }
        else if (index > size)
        {
            return;
        }
        else if (index == 0)
        {
            current->addAtHead(val);
        }
        else
        {
            MyLinkedList* insert = new MyLinkedList();
            insert->value = val;
            MyLinkedList* prev = nullptr;

            for (int i = 0; i < index - 1; ++i)
            {
                current = current->next;
            }
            prev = current->next;
            current->next = insert;
            insert->next = prev;
            size++;
        }

    }

    void deleteAtIndex(int index) {
        MyLinkedList* current = next;
        if (index > size)
        {
            return;
        }
        else if (index == 0)
        {
            MyLinkedList* temp = current->next;
            current = current->next;
        }
        else
        {
            MyLinkedList* prev = nullptr;

            for (int i = 0; i < index; ++i)
            {
                current = current->next;
            }
            prev = current->next;
            current->next = nullptr;
            current = prev;
            size++;
        }
    }

    void print()
    {
        MyLinkedList* temp = next;
        while (temp != nullptr)
        {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    MyLinkedList linkedlist;

    linkedlist.addAtHead(1);
    linkedlist.addAtTail(2);
    linkedlist.addAtTail(3);

    linkedlist.addAtIndex(0, 4);
    int x = linkedlist.get(1);
    std::cout << x << std::endl;
    linkedlist.print();
}
