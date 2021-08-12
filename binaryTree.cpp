#include<iostream>
using namespace std;

class Node{
public:
	string item;
	Node *left = 0;
	Node *right = 0;
};


class Pair{
public:
	Node *parent = 0;
	Node *child = 0;
};


class CreateTree{	//创建二叉树类方法
	private:	//私有
		Node *Root;		//根节点指针
		int size;	//树包含节点数
		int maxitems;	//可包含最大节点
		
		Pair SeekItem(string item){		//寻找项目方法
			Pair look;
			look.child = Root;
			if (look.child == 0){
				return look;
			}
			while(look.child != 0){
				if (Toleft(item, look.child->item)){
					look.parent = look.child;
					look.child = look.child->left;
				}
				else if(Toright(item, look.child->item)){
					look.parent = look.child;
					look.child = look.child->right;
				}
				else{
					break;
				}
			}
			return look;
		}

		int Toleft(string item1, string item2){		//判断左
			if (item1 < item2){
				return 1;
			}
			else{
				return 0;
			}
		}

		int Toright(string item1, string item2){	//判断右
			if (item1 > item2){
				return 1;
			}
			else{
				return 0;
			}
		}

		int AddNode(string item, Node * root){	//添加节点,传入两个参数
			if (Toleft(item,root->item)){
				if (root->left == 0){
					root->left = new Node;
					root->left->item = item;
					size += 1;
					cout<<"节点添加成功!\n"<< root->left->item <<'\n';
				}
				else{
					AddNode(item, root->left);
				}
			}
			else if (Toright(item, root->item)){
				if (root->right == 0){
					root->right = new Node;
					root->right->item = item;
					size += 1;
					cout<<"节点添加成功!\n"<<root->right->item<<'\n';
				}
				else{
					AddNode(item,root->right);
				}
			}else{
				cout<<"节点添加失败!\n";
			}
			return 0;
		}

		int DeleteNode(Node * node){	//删除节点,传入指针参数
			Node *temp;
			cout<<"Delete item:"<< node->item <<'\n';
			if (node->left == 0){
				temp = node;
				node = node->right;
				delete temp;
				size -= 1;
				return 1;
			}
			else if(node->right == 0){
				temp = node;
				node = node->left;
				delete temp;
				size -= 1;
				return 1;
			}
			else{
				temp = node->left;
				while(temp->right != 0){
					temp = temp->right;
				}
				temp->right = node->right;
				node = node->left;
				size -= 1;
				return 1;
			}
		}

		void InOrder(Node *root){	//遍历方法实现.传入指针
			if (root != 0){
				cout<< root->item <<'\n';
				InOrder(root->left);
				InOrder(root->right);
			}
		}

		void DeleteAllNodes(Node *root){	//删除所有节点,传入指针
			if (root != 0 ){
				Node *temp = root->right;
				DeleteAllNodes(root->left);
				delete root;
				DeleteAllNodes(temp);
			}
		}

	public:		//公有方法
		void init(int maxitems=20){		//初始化树
			Root = 0;
			size = 0;
			this->maxitems = maxitems;
		}

		int TreeIsFull(){	//检查树是否已满
			if (size == maxitems){
				cout<<"Tree is full!\n";
				return 1;
			}else{
				return 0;
			}
		}

		void TreeIsEmpty(){		//检查树是否为空
			if (size == 0){
				cout<<"Tree is empty.\n";
			}
			else{
				cout<<"Tree is not empty.\n";
				}
		}

		void TreeItemCount(){	//节点数
			cout<<"当前节点数: "<< size <<'\n';
		}

		int Additem(string item){	//添加项目
			if (TreeIsFull()){
				return 0;
			}
			else if(SeekItem(item).child != 0){
				cout<<"Attempted to add duplicate item.\n";
				return 0;
			}
			else{
				if (Root == 0){
					Root = new Node;
					Root->item = item;
					size += 1;
					cout<<"根节点添加成功!\n"<< Root->item <<'\n';
				}
				else{
					AddNode(item,Root);
				}
			}
			return 0;
		}

		int DeleteItem(string item){	//删除项目
			Pair look = SeekItem(item);
			if (look.child == 0){
				cout<<"树中无此项目!\n";
				return 0;
			}
			if (look.parent == 0){
				if(DeleteNode(Root)){
					cout<<"删除成功!\n";
					return 1;
				}
			}
			else if (look.parent->left == look.child){
				if (DeleteNode(look.parent->left)){
					cout<<"删除成功!\n";
					return 1;
				}
			}
			else{
				if(DeleteNode(look.parent->right)){
					cout<<"删除成功!\n";
					return 1;
				}
			}
			return 0;
		}

		void Traverse(){	//遍历二叉树
			cout<<"二叉树遍历:\n";
			InOrder(Root);
		}

		void DeleteAll(){	//清空树
			if (Root != 0){
				DeleteAllNodes(Root);
			}
		}

		int Search(string item){	//搜索二叉树
			cout<<"Search item: "<<item<<'\n';
			cout<<"Result:\n";
			Pair look;
			look.child = Root;
			if (look.child == 0){
				cout<<"此树为空,请添加项目\n";
				return 0;
			}
			while(look.child != 0){
				if (Toleft(item,look.child->item)){
					look.parent = look.child;
					look.child = look.child->left;
				}
				else if(Toright(item,look.child->item)){
					look.parent = look.child;
					look.child = look.child->right;
				}
				else{
					cout<< look.child->item <<'\n';
					break;
				}
			}
			return 0;
		}
};

int main(){
	CreateTree Tree;
	Tree.init(10);	//初始化最大节点数为10的二叉树
	Tree.Additem("123");	//添加项目
	Tree.Additem("12444");
	Tree.Additem("123");
	Tree.Additem("12544");
	//Tree.Additem("12544");
	Tree.TreeItemCount();	//节点数
	Tree.Traverse();	//二叉树遍历
}