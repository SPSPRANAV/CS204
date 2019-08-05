#include<iostream>
#include<cmath>
using namespace std;
struct point
{
  int a;
  int b;
};
struct node
{
  struct point pt;
  struct node* ptr;
};
class Linked_List
{


public:
    struct node* head;
  Linked_List()
  {
    head=NULL;
  }
  void AddFirst(int x,int y)
  {
    struct point P;
    P.a= x   ;  P.b= y;
    struct node* next =new node;
    struct node* tmp;
    next->pt=P;
    tmp=head;//tmp->pt=head->pt;
    head=next;//head->pt=next->pt;
    next->ptr=tmp;//next->pt=tmp->pt;
  //  cout<<P.a<<P.b;
  }
  int DelFirst()
  { if(head==NULL) return -1;
    else
    {
      struct node* tmp;
      tmp=head->ptr;
      head=tmp;
      free(tmp);
      delete(tmp);
      return 0;
    }
  }
  int Del(int x,int y)
  {
    struct node* next;
    struct node* prev;
    if(head==NULL){return -1;}
    else{next=head;
    	prev=NULL;
    while(next!=NULL)
    {


    			if( (next->pt.a==x)&&(next->pt.b==y)&&prev!=NULL )
    			{

    				prev->ptr=next->ptr
    		;return 0;
    				free(next);delete(next);

    				break;
    			}
    			else if((next->pt.a==x)&&(next->pt.b==y)&&prev==NULL)
    			{
    				struct node* tmp;
    				tmp=head->ptr;
    				head=tmp;
    				free(tmp);
    				delete(tmp);
            break;
    			}
    			else{

    				prev=next;
    				next=next->ptr;}

    }}


  }
float  Distance(struct point p)
  {
    int x,y;
    x=p.a;
    y=p.b;
    float d=sqrt(x*x+y*y);
    return d;
  }
  int Search(int x,int y)
  { int count=0;
    struct node* next;
    ;
  //struct node* prev;
  if(head==NULL){return -1;}
next=head;
//  prev=NULL;
  while(next!=NULL)
  {
  /*  cout<<x<<'\t'<<next->pt.a<<'\t';*/
  if( (next->pt.a==x)&&(next->pt.b==y) )
      {
          count=count+1;
          next=next->ptr;

      }
        else{  next=next->ptr;}
}
return count;}

  int Length()
  {
    int count=0;
      struct node* next;
    //  struct node* prev;
          if(head==NULL){return 0;}
      next=head;
      while(next!=NULL)
      {
        count++;
next=next->ptr;

     }
    return count;
  }
void Search(float d)
{ int x,y,count=0;
  struct node* next;
//  struct node* prev;
  if(head==NULL){cout<<"No Linked List";}
  else
  {next=head;
  //prev=head;
  while(next!=NULL)
  {
  x=next->pt.a;y=next->pt.b;
  if(  Distance(next->pt)<=d){ //return prev->pt;}

cout<<x<<","<<y<<"\n";
  next=next->ptr;
  //prev=prev->ptr;

  }
else{next=next->ptr;}

}}
}};
int main()
{ //struct node* head=NULL;
  int T;
  Linked_List list;
  cin>>T;
  while(T--)
  { int f;
    cin>>f;
    if(f==1)
    { int a,b;
      cin>>a>>b;
      list.AddFirst(a,b);
    }
    if(f==2)
    {
  /*  cout<<*/list.DelFirst();
    }
    if(f==3)
    { int p,q;
      cin>>p>>q;
    /*cout<<*/
    list.Del(p,q);
    }
    if(f==4)
    { int e;
      cin>>e;
      list.Search(e);
    }
    if(f==5)
    {
      int p,q;
        cin>>p>>q;
        cout<<list.Search(p,q);
    }
    if(f==6)
    {
      cout<<list.Length();
    }
  }
return 0;
}
