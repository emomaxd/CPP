#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BinaryTree {
    private:
        Node *root;

    public:
        BinaryTree() {
            root = NULL;
        }

        void insert(int value) {
            Node *node = new Node(value);

            if (root == NULL) {
                root = node;
                return;
            }

            Node *current = root;
            Node *parent = NULL;

            while (true) {
                parent = current;

                if (value < current->data) {
                    current = current->left;

                    if (current == NULL) {
                        parent->left = node;
                        return;
                    }
                } else {
                    current = current->right;

                    if (current == NULL) {
                        parent->right = node;
                        return;
                    }
                }
            }
        }


    //DFS 

    void preOrderTraversal(Node *node) {
        if (node == NULL) 
            return;
            
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);

    }


    void inOrderTraversal(Node *node) {
        if (node == NULL) 
            return;
        
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);

    }

       
    void postOrderTraversal(Node *node) {
        if (node == NULL) 
            return;
        
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";

    }
    
    
    void BFS(){
    
        std::queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* current = q.front();
            
            std::cout << q.front()->data << " ";
            
            q.pop();

        
            if(current->left)
                q.push(current->left);
        
            if(current->right)
                q.push(current->right);


        }
    }
};

int main() {
    BinaryTree tree;

    tree.insert(38);
    tree.insert(19);
    tree.insert(12);
    tree.insert(24);
    tree.insert(69);
    tree.insert(59);
    tree.insert(95);

    tree.BFS();

    return 0;
}
