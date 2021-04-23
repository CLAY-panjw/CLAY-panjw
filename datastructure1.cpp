#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#include<iostream>
using namespace std;

typedef int Status;
typedef int ElemType;
typedef struct ListNode{
    ElemType data[MAXSIZE];
    int length;
}*SqList;
//表的初始化
SqList InitList(){
    SqList L;
    L=(SqList)malloc(sizeof(struct ListNode));
    L->length=0;
    return L;
}
//表的输出
Status Output(SqList L){
    int i;
    for(i=0;i<L->length;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
    return OK;
}
//获得元素的操作，返回第i个数据元素的值
Status GetElem(SqList L,int i,ElemType *e){
    if(L->length==0||i<1||i>L->length){
        return ERROR;
    }
    *e=L->data[i-1];
    return OK;
}
//插入元素的操作
Status ListInsert(SqList L,int i,ElemType e){
    int k;
    if(L->length==MAXSIZE){
        return ERROR;
    }
    if(i<1||i>L->length+1){
        return ERROR;
    }
    if(i<=L->length){
        for(k=L->length-1;k>=i-1;k--){
            L->data[k+1]=L->data[k];
        }
    }
    L->data[i-1]=e;
    L->length++;
    return OK;
}
//删除元素的操作
Status ListDelete(SqList L,int i,ElemType *e){
    int k;
    if(L->length==0){
        return ERROR;
    }
    if(i<1||i>L->length){
        return ERROR;
    }
    if(i<L->length){
        for(k=i;k<L->length;k++){
            L->data[k-1]=L->data[k];
        }
    }
    L->length--;
    return OK;
}


//单链表的基本操作

typedef struct Node
{
    ElemType data;
    struct Node *Next;
}Node;
typedef struct Node *Linklist;

//头插法创建单链表

void CreatListHead(Linklist *L, int n)
{
	*L = (Linklist)malloc(sizeof(Node));//头结点申请地址  注意malloc的用法
	(*L)->Next = NULL;
    Linklist p;
	srand(time(0));//初始化随机数种子，后续用于生成随机数
	for (int i = 0; i < n; i++)
	{
		p = (Linklist)malloc(sizeof(Node));//生成新结点
		p->data = rand() % 100 + 1;//生成两位随机数
		p->Next = (*L)->Next;
		(*L)->Next = p;
	}
}

//尾插法创建单链表

void CreateListTail(Linklist *L, int n)
{
    *L=(Linklist)malloc(sizeof(Node));
    Linklist p,r;
    r=*L;
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        p=(Linklist)malloc(sizeof(Node));
        p->data=rand() % 100 +1;
        r->Next=p;
        r=p;
    }
    r->Next=NULL;
}

//遍历单链表输出元素
void  OutputList(Linklist L)
{
	Linklist p;
	for (p = L->Next; p != NULL; p = p->Next)//遍历链表
	{
		cout << p->data << " ";
	}
	cout << endl;
}
//单链表查找操作
//用e返回单链表中第i个元素的值
int GetListElem(Linklist L, ElemType *e, int i)
{
	int j = 1;
	Linklist p;
	p = L->Next;
	while (p&&j<i)
	{
		p = p->Next;
		j++;
	}
	if (!p || j < i)//存在性判断 
	{
		return 1;
	}
	*e = p->data;
    cout<<*e<<endl;
	return 0;
}

//单链表的插入操作
//在L中第i个位置之前插入元素e，表长度加1；
int  LinklistInsert(Linklist *L,int i,ElemType e)
{
   Linklist p, r;
 
	p = *L;
	int j=1;
	while (p&&j<i)//p非空，寻找j=i的结点；
	{
		p= p->Next;
		++j;
	}
	if (!p || j > i)//存在性判断 ，p为空，或者j>i则不存在
	{
		return 1;
	}
	r = (Linklist)malloc(sizeof(Node));
	r->data = e;
	r->Next = p->Next;
	p->Next = r;
    return 0;
}

//单链表的删除操作
//在L中删除第i个元素之前的元素，并释放该节点
int LinklistDelete(Linklist *L,int i,ElemType *e)
{
    Linklist p,r;
    r=*L;
    p=(*L)->Next;
    int j=1;
    while(p&&j<i)
    {
        r=p;
        p=p->Next;
        j++;
    }
    if(!p||j>i)
        return 1;
    r->Next=p->Next;
    *e=p->data;
    cout<<"被删除的数是："<<*e<<endl;
    free(p);
    return 0;

}











int main()
{
 /*
    //顺序表测试
    SqList L;
    L=InitList();
    int n,i,x;
    cout<<"请输入元素个数n："<<endl;
    cin>>n;
    cout<<"请输入元素值："<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        ListInsert(L,i,x);
    }

    Output(L);
    ListInsert(L,5,8);
    Output(L);

*/

    //单链表测试
    int n;
	Linklist list1;
    ElemType *e;
	cout << "输入单链表的长度：" << endl;
	cin >> n;
	CreatListHead(&list1, n);
	OutputList(list1);
    GetListElem(list1,e,6);
    LinklistInsert(&list1,5,0);
    cout<<"插入后的单链表："<<endl;
    OutputList(list1);
    LinklistDelete(&list1,10,e);
    cout<<"删除后的单链表："<<endl;
    OutputList(list1);
    return 0;
}

