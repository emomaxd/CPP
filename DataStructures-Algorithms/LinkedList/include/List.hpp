#pragma once
#include "Node.hpp"
template <typename T>
class LinkedList{
    private:
    Node<T>* firstNode;
    Node<T>* lastNode;
    short length=0;
    bool isEmpty(){
        if(firstNode==NULL){
          return true;
      }
          return false;
    }
    
    

    public:
    LinkedList(){
        firstNode=lastNode=NULL;
    }
    void Add(T data){
        Node<T>* temp=new Node<T>(data);
        if(isEmpty()){
            firstNode=(temp);
            lastNode=(temp);
            length++;
            return;
        }
             lastNode->setNextNode(temp);
             lastNode=lastNode->getNextNode();
             length++; 
    }
    void removeFront(){
        if(isEmpty())
        return;
        if(length==1){
            firstNode=lastNode=NULL;
        return;
        }
        std::cout<<"LOG"<<std::endl;
        firstNode=firstNode->getNextNode();
        length--;
    }
    void removeLast(){
        if(isEmpty())
        return;
        if(length==1){
            firstNode=lastNode=NULL;
            return;
        }
         Node<T>* temp=firstNode;

        for(short i=0;i<length-2;i++){
            temp=temp->getNextNode();
        }
        temp->setNextNode(NULL);
        lastNode=temp;
        length--;
    }
    void Remove(short index){
        if(isEmpty())
        return;
        if(index>length){
            std::cout<<"index is out of bounds"<<std::endl;
            return;
        }
        if(index==0){
            removeFront();
            return;
        }
        if(index==1){
            firstNode->setNextNode(firstNode->getNextNode()->getNextNode());
            length--;
            return;
        }
        Node<T>* temp=firstNode;
        for(short i=0;i<index-1;i++){
            temp=temp->getNextNode();
            std::cout<<"LOG1 : "<<temp->getData()<<std::endl;
            temp->setNextNode(temp->getNextNode()->getNextNode());
            
        }
        length--;
    }
    void Print(){      
        if(isEmpty())
        return;
         Node<T>* temp=firstNode;
         for(short i=0;i<length;i++){
            std::cout<<i<<" : "<<temp->getData()<<std::endl;
            temp=temp->getNextNode();
         }         
        }
        
    
};