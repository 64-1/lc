// 24. Swap Nodes in Pairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

//definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addHead(ListNode* head, int val)
{
    ListNode* aNewNode = new ListNode(val);
    aNewNode->next = head;
    return aNewNode;
}

void print(ListNode* head)
{
    ListNode* current = head;
    while (current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* dummyHead = new ListNode();
        ListNode* current = new ListNode();
        dummyHead = head;
        current = dummyHead;

        while (current->next != nullptr && current->next->next != nullptr)
        {
            ListNode* temp = current->next;
            ListNode* temp1 = current->next->next->next;

            current = current->next->next;
            current->next->next = temp;
            temp->next = temp1;

            current = current->next->next;
        }

        return dummyHead->next;
    }
};

int main()
{
    ListNode* input = new ListNode(4);
    std::vector<int> realInput = { 3,2,1 };
    for (int i= 0; i < realInput.size(); ++i)
    {
        input = addHead(input, realInput[i]);
    }
    print(input);
    
    Solution sol;
    input = sol.swapPairs(input);

    print(input);
}
