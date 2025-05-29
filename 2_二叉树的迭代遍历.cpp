#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 从根节点开始, 加入到栈中
void preordered_traversal(TreeNode *node, vector<int> &vec_res) {
    // 存放节点指针的栈
    stack<TreeNode *> st;
    st.push(node);
    while (!st.empty()) {
        TreeNode *cur = st.top();
        st.pop();
        if (cur == nullptr) {
            continue;
        }
        vec_res.push_back(cur->val);
        st.push(cur->right);
        st.push(cur->left);
    }
}

void postorder_traversal(TreeNode *node, vector<int> &vec_res) {
    // 存放节点指针的栈
    stack<TreeNode *> st;
    st.push(node);
    while (!st.empty()) {
        TreeNode *cur = st.top();
        st.pop();
        if (cur == nullptr) {
            continue;
        }
        vec_res.push_back(cur->val);
        st.push(cur->left);
        st.push(cur->right);
    }
    reverse(vec_res.begin(),vec_res.end());
}

void inorder_traversal(TreeNode* node, vector<int> &vec_res){
    // 栈
    stack<TreeNode *> st;
    // 中序遍历 左根右
    // 要一直访问到最左边的叶子节点, 此时要一直存储到栈里
    // cur为叶子节点进入到下一次循环后, 会为空, 进入else分支, 此时开始栈开始弹出指针, 加入其值到数组中,即左
    // 栈弹出的节点即为最左的叶子节点,此时复制
    // 退出循环条件 当前节点为空且栈为空
    TreeNode * cur = node;
    while(cur!=nullptr && !st.empty()){
        if(cur!=nullptr){
            st.push(cur);
            cur = cur->left;
        }
        else{

        }
    }


}

int main() {
    // 创建节点
    TreeNode *root = new TreeNode(3);
    TreeNode *node9 = new TreeNode(9);
    TreeNode *node20 = new TreeNode(20);
    TreeNode *node15 = new TreeNode(15);
    TreeNode *node7 = new TreeNode(7);

    // 构建树的结构
    // 3
    // | \
    // 9 20
    //   / \
    //  15  7
    root->left = node9;
    root->right = node20;
    node20->left = node15;
    node20->right = node7;
    
    // 非递归前序遍历
    vector<int> pre_result;
    preordered_traversal(root, pre_result);
    cout << "非递归前序遍历: ";
    for(auto i:pre_result){
        cout << i << " ";
    }
    cout << endl;
    // 非递归后序遍历
  
    vector<int> post_result;
    postorder_traversal(root, post_result);
    cout << "非递归后序遍历: ";
    for(auto i:post_result){
        cout << i << " ";
    }
    cout << endl;
    
    // 删除节点
    delete root;
    delete node9;
    delete node20;
    delete node15;
    delete node7;
}