#include <iostream>
using namespace std;
int flag;
class tNode{
    public:
        tNode();
        tNode(int value);
        int val;
        int counts;
        tNode * lch, * rch;
};
tNode::tNode() {
    val = 0;
    counts = 0;
    lch = rch = NULL;
}
tNode::tNode(int value) {
    val = value;
    counts = 1;
    lch = rch = NULL;
}
class BSTree {
    public:
        BSTree();
        tNode * insert(tNode *);
        void mfs(tNode *);
        tNode * root;
};
BSTree::BSTree() {
    root = NULL;
}
//二叉树中插入节点一定是作为叶子节点插入的
tNode * BSTree::insert(tNode * z) {
    tNode * y = NULL;
    tNode * x = root;
    while (x!=NULL) {
        y = x;
        if (z->val == x->val) {
            ++x->counts; 
            break;
        } else if (z->val < x->val) {
            x = x->lch;
        } else {
            x = x->rch;
        }
    }
	//满足条件说明待插入的节点是不同的
    if (NULL==x) {
        if (NULL==y) root = z;
        else {
            if (z->val < y->val) 
                y->lch = z;
            else 
                y->rch = z;
        }
    }
    return z;
}
void BSTree::mfs(tNode * tn) {
    if (NULL==tn) return;
    mfs(tn->lch);
    if (tn->counts>1) {
        if (!flag) flag = 1;
        cout.width(3);
        cout<<tn->val/10000;
        cout<<"-";
        cout.width(4);
        cout<<tn->val%10000;
        cout<<" "<<tn->counts<<endl;
    }
    mfs(tn->rch);
}

int main() {
    int i,N,val;
    char c;
    BSTree * bst = new BSTree();
    flag = 0;
    cin>>N;
    c = cin.get(); // remove ' '
    for (i=0;i<N;++i) {
                val = 0;
        while ((c=cin.get())!='\n') {
            if (c>='0' && c<='9')
                val=val*10+c-'0';
            else if (c>='A' && c<'Q')
                val=val*10+(c-'A')/3+2;
            else if (c>'Q' && c<'Z')
                val=val*10+(c-'Q')/3+7;
        }
        bst->insert(new tNode(val));
           }
    cout.fill('0');
    bst->mfs(bst->root);
    if (!flag) cout<<"No duplicates. ";
    delete bst;
    return 0;
}