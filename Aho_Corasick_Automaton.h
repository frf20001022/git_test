#include<bits/stdc++.h>
using namespace std;
const int kind = 26;
struct Aho_Corasick_Automaton{
	//const int kind = 26;//注意如果编译不是c++11的话需要把这句话写在外面	
	//queue<int> q;
	struct node{
		node *fail;
		node *next[kind];
		int count;
		node(){fail=NULL;count=0;memset(next,NULL,sizeof(next));}//有我搞不懂的waring
	};
	queue<node*> q;
	void insert(char *str,node *root){
		node *p=root;
		int i=0,index;
		while(str[i]){
			index=str[i]-'a';
			if(p->next[index]==NULL)
				p->next[index]=new node();
			p=p->next[index];
			i++;
		}
		p->count++;
	}

	void build_fail(node *root){
		int i;
		root->fail=NULL;
		q.push(root);
		while(!q.empty()){
			node *temp=q.front();q.pop();
			node *p=NULL;
			for(int i=0;i<kind;i++){
				if(temp->next[i]!=NULL){
					if(temp==root) temp->next[i]->fail=root;
					else{
						p=temp->fail;
						while(p!=NULL){
							if(p->next[i]!=NULL){
								temp->next[i]->fail=p->next[i];
								break;
							}
							p=p->fail;
						}
						if(p==NULL) temp->next[i]->fail=root;
					}
					q.push(temp->next[i]);
				}
			}
		}
	
	}

	int query(node *root,char *str){
		int i=0,index,cnt=0,len=strlen(str);
		node *p=root;
		while(str[i]){
			index=str[i]-'a';
			while(p->next[index]==NULL&&p!=root) p=p->fail;
			p=p->next[index];
			if(p==NULL) p=root;
			node *temp=p;
			while(temp!=root&&temp->count!=-1){
				cnt+=temp->count;
				temp->count=-1;
				temp=temp->fail;
			}
			i++;
		}
		return cnt;
	}
}
