#include <bits/stdc++.h>
using namespace std;

class trienode{
    
    public:
    bool isend;
    trienode* Children[26];
    trienode()
    {
        isend=false;
        for(int i=0;i<26;i++)
        {
            Children[i]=NULL;
        }
    }
};

void insert(trienode* root, string s)
{
    trienode*temp=root;
    for(int i=0;i<s.size();i++)
    {
        int in=s[i]-'a';
        cout<<in<<endl;
        if(!temp->Children[in])
        {
            temp->Children[in]=new trienode;
        }
        temp=temp->Children[in];
    }
    temp->isend=true;
}
bool search(trienode* root,string s)
{
    trienode* temp=root;
    for(int i=0;i<s.size();i++)
    {
        int in=s[i]-'a';
        cout<<in<<endl;
        if(!temp->Children[in])
        {
            cout<<"break\n";
            return false;
        }
        temp=temp->Children[in];
    }
    if(temp->isend)
       return true;
    else
       return false;
}
int main() {
	// your code goes here
	trienode* root=new trienode;
	cout<<"Enter string\n";
	string s;
	cin>>s;
	insert(root,s);
	cout<<search(root,s)<<endl;
	cout<<search(root,"hell")<<endl;
	cout<<search(root,"sir")<<endl;
	
	return 0;
}


