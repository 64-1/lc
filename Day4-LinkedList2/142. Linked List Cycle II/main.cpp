#include <iostream>
#include <vector>


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createCyclicList()
{
    ListNode* head = new ListNode(1);
    ListNode* current = head;
    
    for (int i = 2; i < 5; ++i)
    {
        /* code */
        current->next = new ListNode(i);
        current = current->next;
    }

    current ->next = head->next->next;

    return head;
}
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while(index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return nullptr;   
    }
};

int main()
{
    Solution sol;

    ListNode* head = createCyclicList();

    ListNode* result = sol.detectCycle(head);

    if(result!=nullptr)
    {
        std::cout << "Cycle detected, starting node value: " << result->val <<std::endl;
    }
    else
    {
        std::cout<< "No cycle detected." << std::endl;
    }

    ListNode* current = head;
    ListNode* next;
    while(current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }

    return 0;
}

