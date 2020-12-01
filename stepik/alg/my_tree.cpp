#include <iostream>
#include <string>
#include <vector>

using namespace std;

using Priority = pair<string, int>;

template<typename T>
struct Node
{
    Node *pLeft;
    Node *pRight;
    T data;

    Node(T data=T(), Node *pLeft = nullptr, Node *pRight = nullptr)
    {
        this->data = data;
        this->pLeft = pLeft;
        this->pRight = pRight;
    }
};


Node<Priority>* popmin(vector <Node<Priority>*> &v)
{
    Node<Priority>* min = v[0];
    int index = 0;
    for(int i = 1; i < v.size(); i++)
        if((min->data).second > (v[i]->data).second)
        {
            min = v[i];
            index = i;
        }
    v.erase(v.begin() + index);
    return min;
}


void haffman(Node<Priority>* node, string text, vector<string> &vecString, int &counter)
{
    if(node->pLeft != nullptr){
        ((node->pLeft)->data).first += text + '0';
        haffman(node->pLeft, ((node->pLeft)->data).first, vecString, counter);
    }
    if(node->pRight != nullptr){
        ((node->pRight)->data).first += text + '1';
        haffman(node->pRight, ((node->pRight)->data).first, vecString, counter);
    }
    if(node->pLeft == nullptr && node->pRight == nullptr){
        vecString.push_back((node->data).first);
        counter += (((node->data).first).size() - 1) * (node->data).second;
    }
}


int main()
{
    vector<Node<Priority>*> v;
    vector<string> vecString;
    int counter = 0;
    int counterofletters = 0;
    string result = "";

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
    Node<Priority>* nodeTmp;

    for(int i = 0; i < 26; i++)
    {
        if(cnt[i])
        {
            tmp = make_pair(i + 'a', cnt[i]);
            nodeTmp = new Node<Priority>(tmp);
            v.push_back(nodeTmp);
            counterofletters -=- 1;
        }
    }

    if(v.size() > 1)
    {
        while(v.size() > 1)
        {
            Node<Priority>* a = popmin(v);
            Node<Priority>* b = popmin(v);
            Node<Priority>* c = new Node<Priority>(make_pair("", (a->data).second + (b->data).second));
            c->pLeft = a;
            c->pRight = b;
            v.push_back(c);
        }
        haffman(v[0], "", vecString, counter);
    }
    else
    {
        vecString.push_back((v[0]->data).first + "0");
        counter += (v[0]->data).second;
    }
    cout << counterofletters << ' ' << counter << endl;

    for(int i = 0; i < vecString.size(); i++)
    {
        cout << vecString[i][0] << ": " << (string)&((vecString[i])[1]) << endl;
    }

    i = 0;
    while(word[i])
    {
        for(int j = 0; j < vecString.size(); j++)
        {
            if(word[i] == vecString[j][0]){
                result += (string)&((vecString[j])[1]);//result += (string)&((vecString[i])[1]);
                break;
            }
        }
        i++;
    }
    cout << result << endl;
}
