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


class BT {

private: Node* root;

public:

    BT() {
        root = NULL;
    }

    vector<int> inorder(Node* root) { // left -> root -> right
        vector<int> inorder;
        if(root == NULL) {
            return inorder;
        }

        stack<Node*> s;
        Node* curr = root;
        while(!s.empty()) {
            while(curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            inorder.push_back(curr->val);
            curr = curr->right;
        }

        return inorder;
    }



    vector<int> preorder(Node* root) {  // root -> left -> right
        vector<int> preorder;
        if(root == NULL) {
            return preorder;
        }

        stack<Node*> s;
        s.push(root);
        while(!s.empty()) {
            Node* node = s.top();
            s.pop();
            preorder.push_back(node->val);
            if(node->right != NULL) {
                s.push(node->right);
            }

            // left is pushed after right so that left is at the top of stack to get processed first
            if(node->left != NULL) {
                s.push(node->left);
            }
        }

        return preorder;
    }

    vector<int> postorder(Node* root) { // left -> right -> root
        vector<int> postorder;
        if(root == NULL) {
            return postorder;
        }

        stack<Node*> s1,s2;
        s1.push(root);
        while(!s1.empty()) {
            Node* node = s1.top();
            s1.pop();
            s2.push(node);

            if(node->left != NULL) {
                s1.push(node->left);
            }

            if(node->right != NULL) {
                s1.push(node->right);
            }
        }

        while(!s2.empty()) {
            postorder.push_back(s2.top()->val);
            s2.pop();
        }

        return postorder;
    }

    vector<vector<int>> levelOrderTraversal(Node* root) {
        vector<vector<int>> levelOrder;
        if(root == NULL) {
            return levelOrder;
        }

        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }

            levelOrder.push_back(level);
        }

        return levelOrder;
    }



    int height(Node* root) {
        if(root == NULL) {
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        return max(lh,rh) + 1;
    }



    vector<int> boundaryTraversal(Node* root){
        vector<int> boundary;
        if(root == NULL) {
            return boundary;
        }
        boundary.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            return boundary;
        }

        //first aquire the left boundary except the leaf node
        // then leaf nodes in inorder traversal
        // then right boundary except the leaf node using stack

        // left boundary
        Node* curr = root->left;
        while(curr != NULL) {
            if(curr->left != NULL || curr->right != NULL) {
                boundary.push_back(curr->val);
            }

            if(curr->left != NULL) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }

        // leaf nodes
        stack<Node*> s;
        s.push(root);
        while(!s.empty()) { // inorder traversal
            Node* node = s.top();
            s.pop();
            if(node->left == NULL && node->right == NULL) {
                boundary.push_back(node->val);
            }

            if(node->left != NULL) {
                s.push(node->left);
            }

            if(node->right != NULL) {
                s.push(node->right);
            }
        }


        // right boundary
        curr = root->right;
        stack<int> rightBoundary;

        while(curr != NULL) {
            if(curr->left != NULL || curr->right != NULL) {
                rightBoundary.push(curr->val);
            }

            if(curr->right != NULL) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }

        while(!rightBoundary.empty()) {
            boundary.push_back(rightBoundary.top());
            rightBoundary.pop();
        }


        return boundary;
    }


    vector<vector<int>> verticalTraversal(Node* root)
    {
        vector<vector<int>> vertical;
        if(root == NULL) {
            return vertical;
        }

        //queue of pair of node , and pair of horizontal distance and level(vertical distance)
        queue<pair<Node*,pair<int,int> >> q;

        //map to store the vertical order , level and node value which is multiset to store the values in sorted order in case of same level
        map<int,map<int,multiset<int>> > mp;

        q.push({ root,{ 0,0 } });
        while(!q.empty()) {
            Node* node = q.front().first;
            int hd = q.front().second.first;
            int level = q.front().second.second;
            q.pop();

            mp[hd][level].insert(node->val);

            if(node->left != NULL) {
                q.push({ node->left,{ hd - 1,level + 1 } });
            }

            if(node->right != NULL) {
                q.push({ node->right,{ hd + 1,level + 1 } });
            }
        }

        for(auto p : mp) {
            vector<int> verticalOrder;
            for(auto q : p.second) {
                for(auto val : q.second) {
                    verticalOrder.push_back(val);
                }
            }
            vertical.push_back(verticalOrder);
        }

        return vertical;
    }


    void rightSideViewUtil(Node* root,int level,vector<int>& rightSide) {
        if(root == NULL) {
            return;
        }

        if(rightSide.size() == level) {
            rightSide.push_back(root->val);
        }

        rightSideViewUtil(root->right,level + 1,rightSide);
        rightSideViewUtil(root->left,level + 1,rightSide);
    }

    vector<int> rightSideView(Node* root){
        vector<int> rightSide;
        rightSideViewUtil(root,0,rightSide);

        return rightSide;
    }



    int widthOfBinaryTree(Node* root) {
        if(root == NULL) {
            return 0;
        }

        int maxWidth = 0;
        queue<pair<Node*,long long int>> q;
        q.push({ root,0 });
        while(!q.empty()) {
            int size = q.size();
            int fmin = q.front().second; // strict left most node
            // fmin is not always 1 , it can be any positive value 
            int first = 0,last = 0;
            for(int i = 0; i < size; i++) {
                Node* node = q.front().first;
                int curr_id = q.front().second - fmin; // horizontal distance of the node from the first node in the queue
                // curr_id is subtracted from fmin to prevent overflow
                q.pop();
                if(i == 0) {
                    first = curr_id;
                }

                if(i == size - 1) {
                    last = curr_id;
                }

                if(node->left != NULL) {
                    q.push({ node->left,(long long int)2 * curr_id + 1 });
                }

                if(node->right != NULL) {
                    q.push({ node->right,(long long int)2 * curr_id + 2 });
                }
            }
            maxWidth = max(maxWidth,last - first + 1);

        }

        return maxWidth;
    }




    Node* buildTree(vector<int>& inorder,vector<int>& postorder) {
        if(inorder.size() != postorder.size()) {
            return NULL;
        }

        int n = inorder.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return buildTreeUtil(inorder,postorder,0,inorder.size() - 1,0,postorder.size() - 1,mp);
    }

    Node* buildTreeUtil(vector<int>& inorder,vector<int>& postorder,int inStart,int inEnd,int postStart,int postEnd,unordered_map<int,int>& mp) {
        if(inStart > inEnd || postStart > postEnd) {
            return NULL;
        }

        Node* root = new Node(postorder[postEnd]);
        int inRootIdx = mp[root->val];

        // left subtree from inStart to inRootIdx - 1
        int leftSubtreeSize = inRootIdx - inStart;

        // postStart + leftSubtreeSize - 1 is the last index of left subtree in postorder
        root->left = buildTreeUtil(inorder,postorder,inStart,inRootIdx - 1,postStart,postStart + leftSubtreeSize - 1,mp);

        // postStart + leftSubtreeSize is the first index of right subtree in postorder
        root->right = buildTreeUtil(inorder,postorder,inRootIdx + 1,inEnd,postStart + leftSubtreeSize,postEnd - 1,mp);

        return root;
    }


};






