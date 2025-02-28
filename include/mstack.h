
#include <iostream>

template <typename T>
struct linked_node {
    T data;
    linked_node* next;

    linked_node(const T& val, linked_node* next = nullptr) {
        data = val;
        this->next = next;
    }
};

template <typename T>
class mstack {
private:
    linked_node<T>* head;
    int size;

public:
    mstack();

    mstack(const T& val);

    ~mstack() {};
    
    bool isEmpty();

    void push(const T& val);

    T& pop();

    T& top();

    bool clear();

    void printVal();
};

template <typename T>
mstack<T>::mstack()
{
    linked_node<T>* head = new linked_node(T());
    this->head = head;
    this->size = 0;
}

template <typename T>
mstack<T>::mstack(const T& val) : head(new linked_node<T>(T())), size(0)
{
    linked_node<T>* node = new linked_node<T>(val);
    this->head->next = node;
    this->size++;
}

template <typename T>
bool mstack<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
void mstack<T>::push(const T& val)
{
    linked_node<T>* node = new linked_node<T>(val);
    node->next = head->next;
    head->next = node;
    size++;
}

template <typename T>
T& mstack<T>::pop()
{
    if (size == 0) {
        throw std::out_of_range("Stack is empty"); // 抛出异常而不是返回默认值
    }
    linked_node<T>* cur = head->next;
    head->next = cur->next;
    T& val = cur->data;
    delete cur;
    size--;
    return val;
}

template <typename T>
inline T &mstack<T>::top()
{
    if (size == 0) {
        throw std::out_of_range("Stack is empty"); // 抛出异常而不是访问空指针
    }
    return head->next->data;
}

template <typename T>
bool mstack<T>::clear()
{
    if (size == 0) {
        return true;
    }
    linked_node<T>* cur = head->next;
    while (size > 0) {
        linked_node<T>* tmp = cur;
        cur = cur->next;
        delete tmp;
        size--;
    }
    return true;
}