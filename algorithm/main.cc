#include <iostream>
#include <stack>
#include <queue>

using namespace std::cout;


namespace ns_binarytree_tranverse
{
template<typename T>
struct TreeNode
{
    TreeNode(const T& d)
        :data(d)//, lchild(nullptr),rchild(nullptr)
    {
        lchild = nullptr;
        rchild = nullptr;
    }
    TreeNode* lchild;
    TreeNode* rchild;
    T data;
};

typedef TreeNode<char> CharTreeNode;

template<typename T>
void postOrderTranverse(TreeNode<T>* root, void (*visit)(const T&))
{
    if (root == nullptr)
    {
        cout<<"empty tree\n";
        return;
    }
    std::stack<TreeNode<T>*> s;
    s.push(root);

    TreeNode<T>* lastVisited = nullptr;
    while (!s.empty())
    {
        TreeNode<T>* cur = s.top();
        bool isChildVisited = ((cur->rchild==lastVisited ||cur->lchild==lastVisited) && lastVisited!=nullptr);
        if (cur->rchild && !isChildVisited)
        {
            s.push(cur->rchild);
        }
        if (cur->lchild && !isChildVisited)
        {
            s.push(cur->lchild);
        }
        if ((cur->rchild==nullptr && cur->lchild==nullptr) || isChildVisited)
        {
            visit(cur->data);
            lastVisited = cur;
            s.pop();
        }
    }
    cout<<"\n";
}

template<typename T>
void preOrderTranverse(TreeNode<T>* root, void (*visit)(const T&))
{
    if (root == nullptr)
    {
        cout<<"empty tree\n";
        return;
    }
    std::stack<TreeNode<T>*> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode<T>* cur = s.top();
        visit(cur->data);
        s.pop();
        if (cur->rchild)
        {
            s.push(cur->rchild);
        }
        if (cur->lchild)
        {
            s.push(cur->lchild);
        }
    }
    cout<<"\n";
}

template<typename T>
void inOrderTranverse(TreeNode<T>* root, void (*visit)(const T&))
{
    if (root == nullptr)
    {
        cout<<"empty tree\n";
        return;
    }
    std::stack<TreeNode<T>*> s;

    TreeNode<T>* cur = root;
    s.push(cur);
    while (!s.empty())
    {
        //Go to mostly left
        while ((cur=s.top())&&cur)
        {
            s.push(cur->lchild);
        }

        //pop null
        s.pop();

        if (!s.empty())
        {
            //visit and go to right
            cur = s.top();
            s.pop();
            visit(cur->data);
            s.push(cur->rchild);
        }
    }

    cout<<"\n";
}

template<typename T>
void levelOrderTranverse(TreeNode<T>* root, void (*visit)(const T&))
{
    if (root == nullptr)
    {
        cout<<"empty tree\n";
        return;
    }
    std::queue<TreeNode<T>*> q;

    TreeNode<T>* cur = root;
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        visit(cur->data);
        if (cur->lchild)
        {
            q.push(cur->lchild);
        }
        if (cur->rchild)
        {
            q.push(cur->rchild);
        }
    }

    cout<<"\n";
}

void visitTreeNode(const char& data)
{
    cout<<data<<",";
}
void test()
{

    CharTreeNode* root = new CharTreeNode('a');
    CharTreeNode* b = new CharTreeNode('b');
    CharTreeNode* c = new CharTreeNode('c');
    root->lchild = b;
    root->rchild = c;

    CharTreeNode* d = new CharTreeNode('d');
    CharTreeNode* e = new CharTreeNode('e');
    b->lchild = d;
    b->rchild = e;

    CharTreeNode* f = new CharTreeNode('f');
    c->rchild = f;

    CharTreeNode* g = new CharTreeNode('g');
    e->lchild = g;
    preOrderTranverse(root, visitTreeNode);
    inOrderTranverse(root, visitTreeNode);
    postOrderTranverse(root, visitTreeNode);
    levelOrderTranverse(root, visitTreeNode);
}

}

int main(int argc, char* argv[])
{
    ns_binarytree_tranverse::test();

    return 0;
}
