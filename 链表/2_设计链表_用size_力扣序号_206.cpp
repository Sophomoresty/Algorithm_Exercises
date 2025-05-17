struct LinkNode {
    int val;
    struct LinkNode *next;
    // 构造函数体
    LinkNode() : val(0), next(nullptr) {}
    LinkNode(int x) : val(x), next(nullptr) {}
    LinkNode(int x, LinkNode *node) : val(x), next(node) {}
};