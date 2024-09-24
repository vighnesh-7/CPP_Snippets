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

// ------------------------------------------------------------------------------------

class Node
{
public:
    int key;
    int value;
    Node *next;
    Node *prev;
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};


class LRUCache
{
public:
    int capacity;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> mp;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        
    }

    int get(int key)
    {
        if(mp.find(key) == mp.end())
            return -1;

        Node *node = mp[key];

        // remove the node from the list
        node->prev->next = node->next;  
        node->next->prev = node->prev;

        // move the node to the front
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;

        return node->value;        
    }

    void put(int key,int value)
    {
        // Write your code here
        if(mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            node->value = value;

            // remove the node from the list
            node->prev->next = node->next;
            node->next->prev = node->prev;

            // move the node to the front
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
        }
        else
        {
            if(mp.size() == capacity)
            {
                Node *node = tail->prev;
                mp.erase(node->key);
                node->prev->next = tail;
                tail->prev = node->prev;
                delete node;
            }

            Node *node = new Node(key, value);
            mp[key] = node;

            // move the node to the front
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
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