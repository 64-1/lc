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
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* current = dummyHead;

        while (current->next != nullptr && current->next->next != nullptr)
        {
            ListNode* temp = current->next;
            ListNode* temp1 = current->next->next;

            //current = current->next->next;
            //current->next->next = temp;
            //temp->next = temp1;

            //current = current->next->next;
            temp->next = temp1->next;
            temp1->next = temp;
            current->next = temp1;

            current = temp;
        }

        return dummyHead->next;
    }
};

int main()
{
    // Initialize the linked list
    std::vector<int> realInput = { 4,3,2,1 };
    ListNode* input = nullptr;
    for (const auto& val : realInput)
    {
        input = addHead(input, val);
    }
    print(input);

    // Swap pairs
    input = Solution().swapPairs(input);

    // Print the result
    print(input);

    // Delete the linked list to free memory
    while (input != nullptr) {
        ListNode* nextNode = input->next;
        delete input;
        input = nextNode;
    }

    return 0;
}
