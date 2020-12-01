#include <iostream>
#include <utility>
#include <vector>

using namespace std;

using Priority = pair<char, int>;

struct tree
{
    Priority value;
    tree* left;
    tree* right;
    tree(Priority k)
    {
        value = k;
        left = nullptr;
        right = nullptr;
    }
    /*void add_node(int val, bool d)
    {
        if(!d)
            this->left = new tree(val);//(*this).left
        else
            this->right = new tree(val);
    }*/
    void connect_node(tree ob, bool d)
    {
        if(!d)
            this->left = &ob;
        else
            this->right = &ob;
    }
    void obhod();
};

tree popmin(vector <tree> &v)
{
    tree tmp = v[0];
    int index = 0;
    for(int i = 1; i < v.size(); i++)
        if((tmp.value).second > (v[i].value).second)
        {
            tmp = v[i];
            index = i;
        }
    v.erase(v.begin() + index);
    return tmp;
}

void tree::obhod()
{
    if()
        cout << (this->value).first << endl;
    if(left != nullptr)
        left->obhod();
    if(right != nullptr)
        right->obhod();
    cout << (this->value).first << endl;
}

int main()
{

/*
    tree a(7);
    a.add_node(8, 0);
    tree b(10);
    a.connect_node(b, 1);
    cout << a.right->value;//(*(a.left)).value*/

    vector<Priority> v;

    int i = 0;
    int cnt[26] = {0};
    string word;
    cin >> word;
    while(word[i])
    {
        cnt[word[i] - 'a']++;
        i++;
    }
    Priority tmp;
    for(int i = 0; i < 26; i++)
    {
        if(cnt[i])
        {
            tmp = make_pair(i + 'a', cnt[i]);
            v.push_back(tmp);
        }
    }
    /*for(int i = 0; i < v.size(); i++)
    {
        cout << v[i].second << endl;
    }
    cout << v.size() << endl;
    v.erase(v.begin() + 0);
    cout << v.size() << endl;

    test(v);
    cout << v.size() << endl;*/
    vector<tree> vtree;
    for(int i = 0; i < v.size(); i++)
    {
        vtree.push_back(tree(v[i]));
    }


    //tree c(make_pair(' ', 4));

    while(vtree.size() > 1)
    {
        tree a = popmin(vtree);
        tree b = popmin(vtree);
        tree c(make_pair(' ', (a.value).second + (b.value).second));
        c.left  = &a;
        c.right = &b;
        vtree.push_back(c);
    }
    cout <<
    //vtree[0].obhod();
}
