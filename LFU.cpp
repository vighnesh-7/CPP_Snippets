#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <algorithm>
#define ll long long
#define tot(a) a.begin(), a.end()
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define minii(a) *mini_element(tot(a))
#define maxi(a) *max_element(tot(a))
#define mod 1000000007
#define coutl(a) cout << a << endl
#define yes coutl("YES")
#define no coutl("NO")
#define vi vector<int>
#define vll vector<ll>

// yt : https://www.youtube.com/watch?v=0PSB9y8ehbk

// ------------------------------------------------------------------------------------

class Node
{
public:
    int key;
    int value;
    int freq;
    Node* next;
    Node* prev;
    Node(int key,int value)
    {
        this->freq = 1;
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList
{
public:
    int size;
    Node* head;
    Node* tail;

    DoublyLinkedList()
    {
        this->size = 0;
        this->head = new Node(-1,-1);
        this->tail = new Node(-1,-1);
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    void addFirst(Node* node)
    {
        node->next = this->head->next;
        node->prev = this->head;

        this->head->next->prev = node;
        this->head->next = node;
        this->size++;
    }


    void remove(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        this->size--;
    }

    Node* removeLast()
    {
        if(size > 0)
        {
            Node* node = tail->prev;
            remove(node);
            return node;
        }
        return NULL;
    }

};


class LFUCache {
public:
    int capacity;
    int minFreq;
    int size;
    map<int,Node*> keyNodeMap;
    map<int,DoublyLinkedList*> freqListMap;

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
        this->size = 0;
    }

    void updateFreq(Node* node){
        keyNodeMap.erase(node->key);
        freqListMap[node->freq]->remove(node);

        // the node is the only node in the list and the freq is the minFreq
        if(node->freq == minFreq && freqListMap[node->freq]->size == 0)
        {
            minFreq++;
        }
        node->freq++;

        DoublyLinkedList* nextHigherList;
        // if the next list exists
        if(freqListMap.find(node->freq) != freqListMap.end())
        {
            nextHigherList = freqListMap[node->freq];
        }
        else
        {
            nextHigherList = new DoublyLinkedList();
            freqListMap[node->freq] = nextHigherList;
        }

        nextHigherList->addFirst(node);
        keyNodeMap[node->key] = node;
    }

    int get(int key) {
        if(keyNodeMap.find(key) == keyNodeMap.end())
        {
            return -1;
        }


        Node* node = keyNodeMap[key];
        int val = node->value;
        updateFreq(node);
        return val;
    }

    void put(int key,int value) {
        if(capacity == 0)
        {
            return;
        }

        // if the key exists in the map then update the value and update the freq
        if(keyNodeMap.find(key) != keyNodeMap.end())
        {
            Node* node = keyNodeMap[key];
            node->value = value;
            updateFreq(node);
        }
        // if the key does not exist in the map then add the key and value 
        else
        {
            // if the capacity is full then remove the least freq node
            if(size == capacity)
            {
                // remove the least freq node
                Node* node = freqListMap[minFreq]->tail->prev;
                keyNodeMap.erase(node->key);
                freqListMap[minFreq]->remove(node);
                size--;
            }

            // new value has to be added who is not present previously
            minFreq = 1;

            DoublyLinkedList* newList = new DoublyLinkedList();
            // if the freq list exists
            if(freqListMap.find(minFreq) != freqListMap.end())
            {
                newList = freqListMap[minFreq];
            }


            Node* newNode = new Node(key,value);
            newList->addFirst(newNode);
            keyNodeMap[key] = newNode;
            freqListMap[minFreq] = newList;
            size++;
        }
    }
};

// ------------------------------------------------------------------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}

// ------------------------------------------------------------------------------------
/*














*/
