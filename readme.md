basic binary tree by Python.

简单二叉树的Python实现

//function  //实现函数

public:	//公有方法

​	init(int maxitems=20)		//二叉树初始化,默认最大节点数为20

​	TreeIsEmpty()	//检查树是否为空

​	TreeIsFull()	//检查树是否已满

​	TreeItemCount()	//检查节点数

​	AddItem(string item)		//添加项目

​	DeleteItem(string item) 	//删除项目

​	DeleteAll()	//清空树

​	Search(item)  #search item   #搜索项目

​	Traverse()	#traverse interface  #遍历接口函数



private:	//私有方法

​	Pair SeekItem(string item)	//寻找项目

​	int Toleft(string item1,string item2)	//判断左

​	int Toright(string item1,string item2)	 //判断右

​	int AddNode(string node,Node * root)	//添加项目,传入两个参数

​	int DeleteNode(Node * node)	//删除节点,传入指针

​	void DeleteAllNodes(Node * root)	//删除所有节点,传入指针

​	void InOrder(Node * root)	//遍历方法实现.传入指针
