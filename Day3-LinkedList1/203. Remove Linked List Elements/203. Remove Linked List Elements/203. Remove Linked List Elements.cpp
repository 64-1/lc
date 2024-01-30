#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* insertHead(ListNode* head, int n)
{
    ListNode* aNewNode = new ListNode(n);
    aNewNode->next = head;
    return aNewNode;
}

void printList(ListNode* head)
{
    ListNode* temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        // Create a dummy node to simplify removal, initialized with value 0
        ListNode* dummy = new ListNode(0);
        dummy->next = head; // Connect dummy to the original head of the linked list
        ListNode* prev = dummy; // Initialize prev pointer to the dummy node
        ListNode* current = head; // Initialize current pointer to the original head

        // Traverse the linked list
        while (current != nullptr)
        {
            if (current->val == val)
            {
                // If the current node's value matches the specified value
                ListNode* temp = current; // Temporarily store the current node
                prev->next = current->next; // Update the next pointer of the previous node to skip the current node
                current = current->next; // Move to the next node
                delete temp; // Free the memory of the removed node
            }
            else
            {
                // If the current node's value does not match the specified value
                prev = current; // Update the prev pointer to the current node
                current = current->next; // Move to the next node
            }
        }

        // The modified linked list starts from the next of the dummy node
        return dummy->next;
    }
};

int main()
{
    Solution sol;
    vector<int> input = { 1, 2, 6, 3, 4, 5, 6 };
    ListNode* input1 = nullptr; // Start with an empty list
    for (int i = 6; i >= 0; --i)
    {
        input1 = insertHead(input1, input[i]); // Use the corrected insertHead function
    }

    cout << "Original List: ";
    printList(input1);

    ListNode* result = sol.removeElements(input1, 6);

    cout << "Modified List: ";
    printList(result);

    // Cleanup
    ListNode* temp = result;
    while (temp != nullptr)
    {
        ListNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
