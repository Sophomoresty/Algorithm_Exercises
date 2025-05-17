// 定义链表
struct LinkNode {
    int val;
    struct LinkNode *next;
    // 构造函数体
    LinkNode() : val(0), next(nullptr) {}
    LinkNode(int x) : val(x), next(nullptr) {}
    LinkNode(int x, LinkNode *node) : val(x), next(node) {}
};

class MyLinkedList {
private:
    LinkNode *head;
    // 定义头指针

public:
    // 构造函数初始化
    MyLinkedList() { head = nullptr; }
    // index的值: 0 - 链表长度-1
    int get(int index) {
        if (index < 0) {
            return -1;
        }
        LinkNode *current = head;
        // 完整的遍历需要从1 到 index, 一共index个

        for (int i = 1; i <= index && current != nullptr; i++) {
            current = current->next;
        }
        // 出来两种情况, index对应的位置在链表中, current不为空
        // index对应的位置 > 链表的长度, current为空
        return current != nullptr ? current->val : -1;

        // current不需要手动指向空
    }

    void addAtHead(int val) {
        LinkNode *new_node = new LinkNode(val);
        new_node->next = head;
        head = new_node;
        // pre_head 和new_node指针在栈中, 会自动销毁, 不需要手动指向空
    }

    void addAtTail(int val) {
        // 找到最后一个节点

        LinkNode *new_node = new LinkNode(val);
        // 需要考虑到链表为空
        if (head == nullptr) {
            head = new_node;
        } else {
            LinkNode *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void addAtIndex(int index, int val) {
        // 找到index前一个节点
        // 从1 - index-1, 共index-1

        if (index < 0) { // 规则: index < 0 等同于 index 0
            index = 0;
        }
        // 没有考虑到在头结点插入
        LinkNode *pre_head = new LinkNode();
        pre_head->next = head;
        LinkNode *current = pre_head;

        // 退出情况
        // 1.index的位置1 - 链表长度-1
        // 2.index的位置在链表位置时和1的处理相同
        // 3.index的位置超出链表位置, 即等于nullptr
        for (int i = 0; i < index && current != nullptr; i++) {

            current = current->next;
        }
        if (current == nullptr) {
            return;
        }

        LinkNode *new_node = new LinkNode(val);
        new_node->next = current->next;
        current->next = new_node;
        head = pre_head->next;
    }

    void deleteAtIndex(int index) {
        if (index < 0) {
            return;
        }
        LinkNode *pre_head = new LinkNode();
        pre_head->next = head;
        // 找到index的前一个节点
        // 0 - index-1
        LinkNode *current = pre_head;
        for (int i = 0; i < index && current->next != nullptr; i++) {
            // index位置超过链表长度 退出条件: current->next = nullpter
            // index位置不超过链表 退出条件: i = index-1完成后退出, 即退出时i
            // =index
            current = current->next;
        }
        if (current->next != nullptr) {
            LinkNode *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        // 更换头结点
        head = pre_head->next;
        delete pre_head;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */