/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:


    TreeNode* max_val(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }

        //if tree has nodes > 0 count
        TreeNode* temp = root;
        while(temp->right != NULL) {
            temp = temp->right;
        }
        return temp;
    }

    TreeNode* solve(TreeNode* root,int key){

        if(root == NULL)return NULL;

        if(root->val == key){

            if(root->left == NULL && root->right ==  NULL){
                delete root;
                return NULL;
            }

            else if (root->left == NULL && root->right != NULL){

                TreeNode* childnode = root->right;
                delete root;
                return childnode;

            }

            else if(root->left != NULL && root->right == NULL){

                  TreeNode* childnode = root->left;
                     delete root;
                return childnode;


            }

            else{


                    //left subtree ke max value
                TreeNode* maxi = max_val(root->left);

                //replace

                root->val = maxi->val;


                 root->left = solve(root->left,maxi->val);

                 return root;


            }

        }

        else if(root->val > key){

            //left me jao

            root->left = solve(root->left,key);
        }

        else{

            //right me jao

            root->right = solve(root->right,key);
        }

        return root;


    }
    TreeNode* deleteNode(TreeNode* root, int key) {


         TreeNode* ans = solve(root,key);

         return ans;
        
    }
};