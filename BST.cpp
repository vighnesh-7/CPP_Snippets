#include<bits/stdc++.h>
using namespace std;


struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        val = data;
        left = right = NULL;
    }
};

class BST{
private: Node* root;

public:
    BST(){
        root = NULL;
    }


    Node* insert(Node* root,int val) {
        if(root == NULL) {
            return new Node(val);
        }

        if(val < root->val) {
            root->left = insert(root->left,val);
        }
        else {
            root->right = insert(root->right,val);
        }

        return root;
    }

    Node* search(Node* root,int val) {
        if(root == NULL) {
            return NULL;
        }

        if(root->val == val) {
            return root;
        }

        if(val < root->val) {
            return search(root->left,val);
        }
        else {
            return search(root->right,val);
        }
    }


    Node* LCA(Node* root,Node* p,Node* q){
        if(root == NULL) {
            return NULL;
        }

        int curr = root->val;
        if(curr > p->val && curr > q->val) {
            return LCA(root->left,p,q);
        }
        else if(curr < p->val && curr < q->val) {
            return LCA(root->right,p,q);
        }

        return root;
    }



    bool isValidBst(Node* root,long long min,long long max) {
        if(root == NULL) {
            return true;
        }

        if(root->val <= min || root->val >= max) {
            return false;
        }        if(root->left == NULL && root->right == NULL) {
            return true;
        }

        return isValidBst(root->left,min,root->val) && isValidBst(root->right,root->val,max);
    }

};


class BstIterator {
private:
    stack<Node*> st;
    bool reverse = true;
    // reverse = true -> before pointer // inorder predecessor
    // reverse = false -> next pointer // inorder successor

public:
    BstIterator(Node* root,bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next(){
        Node* top = st.top();
        st.pop();
        if(reverse) {
            pushAll(top->left);
        }
        else {
            pushAll(top->right);
        }

        return top->val;
    }

private:
    void pushAll(Node* root) {
        while(root != NULL) {
            st.push(root);

            if(reverse) {
                root = root->right;
            }
            else {
                root = root->left;
            }

        }
    }
};


