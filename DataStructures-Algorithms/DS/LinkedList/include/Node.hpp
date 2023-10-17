#pragma once
#include <iostream>
template <typename T>
class Node{
    private:
    Node* nextNode;
    T data;
    
    public:
    Node(T data){
        this->data=data;
        this->nextNode=NULL;
    }
    Node(){
        nextNode=NULL;
        data=NULL;
    }

    Node* getNextNode(){
        return this->nextNode;
    }
    T getData(){
        return this->data;
    }
    void setData(T* data){
        this->data=data;
    }
    void setNextNode(Node* nNode){
        this->nextNode=nNode;
    }

};