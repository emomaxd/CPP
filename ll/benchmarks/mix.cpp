#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

// Function to sum elements in an array
long sumArray(const int* arr, size_t size) {
    long sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Function to sum elements in an unrolled loop
long sumArrayUnrolled(const int* arr, size_t size) {
    long sum = 0;
    size_t i = 0;

    // Unroll the loop by a factor of 4
    for (; i + 4 <= size; i += 4) {
        sum += arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3];
    }

    // Handle any remaining elements
    for (; i < size; ++i) {
        sum += arr[i];
    }

    return sum;
}

// Prefetching demonstration
void prefetch(const int* arr, size_t size) {
    for (size_t i = 0; i < size; i += 16) {
        __builtin_prefetch(&arr[i + 16]); // Prefetch next block
    }
}

// Function to sum elements in a linked list
struct Node {
    int data;
    Node* next;
};

long sumLinkedList(Node* head) {
    long sum = 0;
    Node* current = head;
    while (current != nullptr) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

// Benchmarking function
void benchmark() {
    const size_t SIZE = 10000000; // 10 million elements
    std::vector<int> arr(SIZE);
    for (size_t i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100; // Initialize array with random values
    }

    // Timing sumArray
    auto start = std::chrono::high_resolution_clock::now();
    long sum1 = sumArray(arr.data(), SIZE);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end - start;
    std::cout << "Sum using sumArray: " << sum1 << " (Time: " << elapsed1.count() << " seconds)\n";

    // Timing sumArrayUnrolled
    start = std::chrono::high_resolution_clock::now();
    long sum2 = sumArrayUnrolled(arr.data(), SIZE);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end - start;
    std::cout << "Sum using sumArrayUnrolled: " << sum2 << " (Time: " << elapsed2.count() << " seconds)\n";

    // Prefetching demonstration
    prefetch(arr.data(), SIZE);
    start = std::chrono::high_resolution_clock::now();
    long sum3 = sumArray(arr.data(), SIZE);
    end = std::chrono::high_resolution_clock::now();
    elapsed2 = end - start; // Reuse the variable for another timing
    std::cout << "Sum with prefetching: " << sum3 << " (Time: " << elapsed2.count() << " seconds)\n";

    // Create a linked list for testing
    Node* head = new Node{arr[0], nullptr};
    Node* current = head;
    for (size_t i = 1; i < SIZE; ++i) {
        current->next = new Node{arr[i], nullptr};
        current = current->next;
    }

    // Timing sumLinkedList
    start = std::chrono::high_resolution_clock::now();
    long sum4 = sumLinkedList(head);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed4 = end - start;
    std::cout << "Sum using linked list: " << sum4 << " (Time: " << elapsed4.count() << " seconds)\n";

    // Clean up linked list
    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    benchmark();
    return 0;
}
