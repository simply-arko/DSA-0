# Iterative Traversals
## Iterative Pre-Order Traversal
**`Approach:`** Using one stack.
```c++
vector <int> ans;
stack <TreeNode*> s;
if(root==NULL)
    return ans;
s.push(root);
while(!s.empty()){
    TreeNode *n = s.top();
    s.pop();
    if(n->right)  s.push(n->right);
    if(n->left)  s.push(n->left);
    ans.push_back(n->val);
}
return ans;
```
## Iterative In-Order Traversal
**`Approach:`** Using one stack.
```c++
stack <TreeNode*> s;
TreeNode *node = root;
vector <int> ans;
while(true){
    if(node){
        s.push(node);
        node = node->left;
    }
    else{
        if(s.empty())  break;
        node = s.top();
        s.pop();
        ans.push_back(node->val);
        node = node->right;
    }
}
return ans;
```