#include<bits/stdc++.h>
using namespace std;
//Creating a new datatype node containging userid ,amount, pointer to the node
struct node
{
  int uid;
  int amount;
  struct node* ptr;
};
int keyvalue(int uid)
{
  int kv=uid%7;
  return kv;
}
node* insertnode(node arr[] ,int usid,int num)
{
  node* next=new node;
  node* traverse;
  node * prev;
  traverse=&arr[keyvalue(usid)];prev=traverse;
  while(traverse!=NULL)
  {
        prev=traverse;
    traverse=traverse->ptr;
  }
  next=prev;
  next->uid=usid;
  next->amount=num;
  next->ptr=NULL;
  return next;
}
node* search(node arr[],int usid)
{
  int kv=keyvalue(usid);
  node* traverse;
  traverse=&arr[kv];
  while(traverse!=NULL)
  {
      if(traverse->uid==usid) {break;}
    traverse=traverse->ptr;
  }
  return traverse;
}
int recharge(node arr[],int usid,int value)
{
    int fv=0;
    if(search(arr,usid)!=NULL)
    {
      int iv=search(arr,usid)->amount;
      fv=search(arr,usid)->amount=iv+value;
    }
    return fv;
}
int main()
{ int n;
  node arr[6];
  for(int i=0;i<6;i++)
  {
    arr[i].ptr=NULL;
  }
  cin>>n;
  int max,maxid=0;
  max=0;
  int q;
  cin>>q;
  while(q--)
  {
    int a,id,cost;
    cin>>a;
    //cout<<q;
    if(a==1)
    { cin>>id>>cost;
      if(search(arr,id)==NULL) {insertnode(arr,id,cost);if(cost>max){max=cost;maxid=id;}}
      else
      {
        int pqr=recharge(arr,id,cost);
        if(pqr>max){max=pqr;maxid=id;}
      }
    }
    else if(a==2)
    {
      if(max==0)cout<<"No data available"<<endl;
      else cout<<maxid<<endl;
    }
    else
    {
      cout<<"Invalid Input.Please try again with argument as either 1 or 2"<<endl;break;
    }
  }
return 0;
}
