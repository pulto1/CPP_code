class Solution {
public:

    void _tree2str(TreeNode* root, string& s)
    {
        if (root == nullptr)
            return;

        s += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
            return;

        s += '(';
        _tree2str(root->left, s);
        s += ')';

        if (root->right != nullptr)
        {
            s += '(';
            _tree2str(root->right, s);
            s += ')';
        }

    }

    string tree2str(TreeNode* root)
    {
        string s;
        _tree2str(root, s);

        return s;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> vv;
        if (root == nullptr)
            return vv;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size(); //获取当前层的数据个数

            //一层层出，并且把下一层的结点都入到队列
            //当前层出完以后，队列中存的就是下一层的多有结点
            vector<int> v;
            while (levelSize--)
            {
                TreeNode* front = q.front();
                q.pop();
                v.push_back(front->val);
                if (front->left)
                    q.push(front->left);

                if (front->right)
                    q.push(front->right);
            }
            vv.push_back(v);
        }

        return vv;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> vv;
        if (root == nullptr)
            return vv;

        vector<TreeNode*> curV;
        vector<TreeNode*> nextV;

        curV.push_back(root);
        while (!curV.empty())
        {
            vector<int> v;
            for (auto e : curV)
            {
                v.push_back(e->val);
                if (e->left)
                    nextV.push_back(e->left);

                if (e->right)
                    nextV.push_back(e->right);
            }
            vv.push_back(v);

            curV.swap(nextV);
            nextV.clear();
        }

        return vv;
    }
};

class Solution {
public:
    bool TreeFind(TreeNode* root, TreeNode* x)
    {
        if (root == NULL)
            return false;

        if (root == x)
            return true;

        return TreeFind(root->left, x) || TreeFind(root->right, x);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
            return nullptr;

        if (p == root || q == root)
            return root;

        bool pInLeft, pInRight, qInLeft, qInRight;
        pInLeft = TreeFind(root->left, p);
        pInRight = !pInLeft;

        qInLeft = TreeFind(root->left, q);
        qInRight = !qInLeft;

        //1. 一个在做，一个在→，root就是最近公共祖先
        //2. 都在左
        //3. 都在右
        if ((pInLeft && qInRight) || (pInRight && qInLeft))
            return root;
        else if (pInLeft && qInLeft)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};

class Solution {
public:
    bool FindPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
    {
        if (root == NULL)
            return false;

        path.push(root);
        if (root == x)
        {
            return true;
        }

        if (FindPath(root->left, x, path))
            return true;

        if (FindPath(root->right, x, path))
            return true;

        //到这里，说明root左树，右树都没有x结点
        //说明root不会是路径中的一个结点，所以弹出
        path.pop();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        stack<TreeNode*> pPath;
        stack<TreeNode*> qPath;
        FindPath(root, p, pPath);
        FindPath(root, q, qPath);

        while (pPath.size() > qPath.size())
        {
            pPath.pop();
        }

        while (pPath.size() < qPath.size())
        {
            qPath.pop();
        }

        while (pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }

        return pPath.top();
    }
};

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    void _Convert(TreeNode* cur, TreeNode*& prev)
    {
        if (cur == NULL)
            return;

        _Convert(cur->left, prev);
        cur->left = prev;
        if (prev)
            prev->right = cur;

        prev = cur;

        _Convert(cur->right, prev);
    }

    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL)
            return NULL;

        TreeNode* prev = nullptr;
        _Convert(pRootOfTree, prev);

        TreeNode* head = pRootOfTree;
        while (head->left)
        {
            head = head->left;
        }

        return head;
    }
};