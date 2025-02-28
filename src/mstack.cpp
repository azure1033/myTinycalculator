#include "mstack.h"

template <>
void mstack<int>::printVal()
{
    int i = 0;
    linked_node<int>* cur = head->next;
    while (i < size) {
        std::cout << cur->data << "->";
        cur = cur->next;
        i++;
    }
    std::cout << "NULL";
}
