#include <iostream>
#include <atomic>
#include <thread>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LockFreeStack {
    std::atomic<Node*> head;

public:
    LockFreeStack() : head(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        Node* oldHead = head.load();
        
        do {
            newNode->next = oldHead;
        } while (!head.compare_exchange_weak(oldHead, newNode));

        std::cout << "Pushed: " << value << std::endl;
    }

    bool pop(int &value) {
        Node* oldHead = head.load();
        
        do {
            if (oldHead == nullptr) {
                return false;
            }
        } while (!head.compare_exchange_weak(oldHead, oldHead->next));

        value = oldHead->data;
        delete oldHead;
        return true;
    }
};

void producer(LockFreeStack& stack) {
    for (int i = 1; i <= 5; ++i) {
        stack.push(i);
    }
}

void consumer(LockFreeStack& stack) {
    int value;
    for (int i = 1; i <= 5; ++i) {
        if (stack.pop(value)) {
            std::cout << "Popped: " << value << std::endl;
        } else {
            std::cout << "Stack is empty!" << std::endl;
        }
    }
}

int main() {
    LockFreeStack stack;

    std::thread t1(producer, std::ref(stack));
    std::thread t2(consumer, std::ref(stack));

    t1.join();
    t2.join();

    return 0;
}
