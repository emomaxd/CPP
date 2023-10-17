#include <vector>
#include <iostream>



   




    int hashFunction(int x,int bucket) {
        return x % bucket;
    }
   





void insertItem(std::vector<std::vector<int>>& table,int key,int& itemCount,int bucket) {
    int index = hashFunction(key,bucket);
    std::vector<int> current = table[index];
    current.push_back(key);
    table[index] = current;
    itemCount++;
}
void deleteItem(std::vector<std::vector<int>>& table,int key,int bucket) {
    int index = hashFunction(key,bucket);
    std::vector<int>::iterator it=table[index].begin();
    
    for (int i=0; i < table[index].size(); i++) {
        if (table[index][i] == key) {
            
            table[index].erase(it+i);
        }
            
    }

}
void display(std::vector<std::vector<int>>& table,int bucket) {

    for (int i = 0; i < bucket; i++) {

        for (int j = 0; j < table[i].size(); j++) {
            std::cout << table[i][j]<<" ";
        }
        std::cout << "\n";
    }
}

int main() {

    int bucket = 7;
    int itemCount = 0;
    std::vector<std::vector<int>> hashTable(bucket);







    
    insertItem(hashTable,3, itemCount, bucket);
    insertItem(hashTable,13, itemCount, bucket);
    insertItem(hashTable, 14, itemCount, bucket);
    insertItem(hashTable,7, itemCount, bucket);
    insertItem(hashTable,31, itemCount, bucket);
    insertItem(hashTable,5, itemCount, bucket);
    display(hashTable,bucket);
    std::cout << "---------\n";
    deleteItem(hashTable, 7, bucket);
    display(hashTable, bucket);

    return 0;
}