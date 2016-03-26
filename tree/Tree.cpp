#include "Tree.h"
#include <queue>


std::string to_string(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

Tree::Tree(){
	p_str=NULL;
}

//judge is the two trees has the same root node and the same part
bool hasTree(Node* p1,Node* p2){
	if (p2==NULL)return true;
	if(p1==NULL)return false;

	if(p1->val!=p2->val)return false;

	bool result=false;
	result=hasTree(p1->lchild,p2->lchild)&&hasTree(p1->rchild,p2->rchild);
	return result;
}


//judge if the two trees has the same part
bool isHaveSubTree(Node* p1,Node* p2){
	if(p2==NULL)return true;
	if(p1==NULL)return false;
	bool result=false;
	result=hasTree(p1,p2);
	if(!result)
		result=isHaveSubTree(p1->lchild,p2->lchild);
	if(!result)
		result=isHaveSubTree(p1->rchild,p2->rchild);
	return result;
}

Node* Tree::create(Node* head){
	
	int input;
	cin>>input;
	//if the input is -1,make the node null
	if(input==-1){
		head=NULL;
		return NULL;
	}
	head=new Node(input);
	//head->val=input;
	cout<<"left child:"<<endl;
	head->lchild=create(head->lchild);
	cout<<"right child:"<<endl;
	head->rchild=create(head->rchild);
	return head;
}


void Tree::preOrder(Node* const head){
	if(head==NULL)return;
	cout<<head->val<<endl;

	if(head->lchild)
		preOrder(head->lchild);
	if(head->rchild)
		preOrder(head->rchild);
}


void Tree::inOrder(Node* const head){
	if(head==NULL)return;
	if (head->lchild)
		inOrder(head->lchild);
	cout<<head->val<<endl;
	if (head->rchild)
		inOrder(head->rchild);
}

void Tree::postOrder(Node* const head){
	if(head==NULL)return;
	if (head->lchild)
		postOrder(head->lchild);
	if (head->rchild)
		postOrder(head->rchild);
	cout<<head->val<<endl;
}

int Tree::getDepth(Node* head){
	if (head==NULL)return 0;
	int lDepth=getDepth(head->lchild);
	int rDepth=getDepth(head->rchild);
	int max=lDepth>rDepth?lDepth:rDepth;
	return max+1;
}


void Tree::BFS(Node* head){

}

Node* Tree::reConstructBinaryTree(vector<int> pre,vector<int> in){
    if(pre.size()==0||in.size()==0)return NULL;
	int rootVal=pre[0];
	int preLen=pre.size();
	int inLen=in.size();

	Node *node=new Node(rootVal);
	if(preLen==1)
		return node;
	
	
	vector<int> leftPreTree,rightPreTree;
	vector<int> leftMidTree,rightMidTree;
	int tmp=0;

	//get the left mid tree and left pre tree
	for(int i=0;i<preLen;i++){
		if(rootVal==in[i]){
			tmp=i;
			break;
		}
		leftMidTree.push_back(in[i]);
		leftPreTree.push_back(pre[i+1]);
	}

	//get the right mid tree and right pre tree
	for(int i=tmp+1;i<preLen;i++){

		rightMidTree.push_back(in[i]);
		rightPreTree.push_back(pre[i]);
	}
	

	Node *lt = reConstructBinaryTree(leftPreTree,leftMidTree);
	Node *rt = reConstructBinaryTree(rightPreTree,rightMidTree);
	node->lchild=lt;
	node->rchild=rt;

	return node;
}


int testReConstructBinaryTree(){
	Tree t;
	vector<int> pre,in;
	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(3);
	pre.push_back(4);
	pre.push_back(5);
	pre.push_back(6);
	pre.push_back(7);

	in.push_back(3);
	in.push_back(2);
	in.push_back(4);
	in.push_back(1);
	in.push_back(6);
	in.push_back(5);
	in.push_back(7);

	// in.push_back(2);
	//in.push_back(1);
	// in.push_back(3);


	Node *p=t.reConstructBinaryTree(pre,in);
	t.preOrder(p);
}


Node* Tree::Deserialize(char *str) {
        if(str==NULL)return NULL;
        if(p_str==NULL)p_str=str;
        if(*p_str=='$'){
            p_str++;
            return NULL;
        }
        
        //get the value
        int val=0;
        while(*p_str!=',')
        	val=val*10+(*(p_str++)-'0');

        Node *node=new Node(val);
        p_str++;
        node->lchild=Deserialize(p_str);
        p_str++;
        node->rchild=Deserialize(p_str);
        return node;
    }


char* Serialize(Node *root) {    
        if(!root) return "$,";
        string r = to_string(root->val);
        r.push_back(',');
        char *left = Serialize(root->lchild);
        char *right = Serialize(root->rchild);
        char *ret = new char[strlen(left) + strlen(right) + r.size()];
        strcpy(ret, r.c_str());
        strcat(ret, left);
        strcat(ret, right);
        return ret;
    }

void testDeserialize(){
	char arrayS[]="1,11232,32,$,$,4,$,$,5,78,$,$,$";
	char *array=arrayS;
	Tree t;
	Node *node=t.Deserialize(array);
	
	t.preOrder(node);
}

int main(int argc, char const *argv[])
{
	cout<<"test the reConstructBinaryTree:"<<endl;
	testReConstructBinaryTree();

	cout<<"test the Deserialize:"<<endl;
	testDeserialize();

	Node *node;
	Tree t;

	cout<<"create the binaryTree:"<<endl;
	node=t.create(node);

	cout<<"Serialize test:"<<endl;
	char *re=Serialize(node);
	cout<<re<<endl;

	//get the depth of the tree
	int depth=t.getDepth(node);
	cout<<"the depth of tree:"<<depth<<endl;

	//preOrder search
	cout<<"preOrder:"<<endl;
	t.preOrder(node);

	//inOrder search
	cout<<"inOrder:"<<endl;
	t.inOrder(node);

	//inOrder search
	cout<<"postOrder:"<<endl;
	t.postOrder(node);

	//test the function isHaveSubTree
	Tree t2;
	Node *node2;
	node2=t2.create(node2);
	if(isHaveSubTree(node,node2))
		cout<<"the two trees have same part"<<endl;
	else
		cout<<"the two trees don't have same part"<<endl;
	return 0;
}


