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
        }
        if(root->left == NULL && root->right == NULL) {
            return true;
        }

        return isValidBst(root->left,min,root->val) && isValidBst(root->right,root->val,max);
    }




    Node* findLastRight(Node* root) {
        if(root == NULL) {
            return NULL;
        }

        while(root->right != NULL) {
            root = root->right;
        }

        return root;
    }

    Node* merger(Node* root){
        if(root->left == NULL) {
            return root->right;
        }
        else if(root->right == NULL) {
            return root->left;
        }

        Node* rightChild = root->right;
        Node* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;

        return root->left;
    }



    Node* deleteNode(Node* root,int key) {
        if(root == NULL) {
            return NULL;
        }

        if(root->val == key) {
            return merger(root);
        }

        Node* curr = root;
        while(curr != NULL) {
            if(curr->val > key) {
                if(curr->left != NULL && curr->left->val == key) {
                    curr->left = merger(curr->left);
                    break;
                }
                else {
                    curr = curr->left;
                }
            }
            else {
                if(curr->right != NULL && curr->right->val == key) {
                    curr->right = merger(curr->right);
                    break;
                }
                else {
                    curr = curr->right;
                }
            }
        }

        return root;
    }


};


class BstIterator {
private:
    stack<Node*> st;
    bool reverse = true;
    // reverse = true -> before pointer // inorder predecessor // largest element
    // reverse = false -> next pointer // inorder successor // smallest element 

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


