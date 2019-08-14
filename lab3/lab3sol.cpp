#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct node
{
  char data;
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
  void push(char x)
  {
    struct node* entry=new node;
    struct node* next;
    entry->data=x;
    next=head;

    while(true)
    {
      if(head==NULL) {head=entry;entry->ptr=NULL;break;}
      else if(next->ptr==NULL)
      {
        next->ptr=entry;
        entry->ptr=NULL;
        //free(next);
        break;
      }
      else next=next->ptr;
  }

  }
  char pop()
  { char x;
    struct node* next;
    struct node* prev;
    if(head==NULL) return 'E';
    if(head->ptr==NULL)
    {  x=head->data;
    //  prev=NULL;
  //  delete(next);//free(head);
      head=NULL;return x;}
      next=head->ptr;
      prev=head;
    while(true)
    {
      if(next->ptr==NULL)
      {  x=next->data;
      //  prev=NULL;
      //  delete(next);
    //    delete(prev);
    prev->ptr=NULL;
      break;
      }
      else
      { prev=next;
        next=next->ptr;

      }
    }
    return x;
  }
  int isEmpty()
  {
    int a=0;
    if(head==NULL) a=1;
    return a;
  }
  bool Check(string p)
  {

    int count=0;
    for(int i=0;i<p.length();i++)
    {
      if((p[i]=='(')||(p[i]=='<')||(p[i]=='{')||(p[i]=='[')) {push(p[i]);}
      if((p[i]=='|')&&(count%2==0))
      {
        push(p[i]);
        count++;continue;
      }
      if((p[i]=='|')&&(count%2!=0))
      {
        char t;
          t=pop();
          count++;
          if(t=='|') continue;
          else return false;break;
      }
      if((p[i]==')'))
      { char t;
        t=pop();
        if(t=='(') continue;
        else return false;break;
      }
      if((p[i]=='}'))
      { char t;
        t=pop();
        if(t=='{') continue;
        else return false;break;
      }
      if((p[i]==']'))
      { char t;
        t=pop();
        if(t=='[') continue;
        else return false;break;
      }
      if((p[i]=='>'))
      { char t;
        t=pop();
        if(t=='<') continue;
        else return false;break;
      }

      //else return false;
    }
    if(isEmpty()==1) return true;
    else return false;
  }
};

int main()
{ int T;
  //Linked_List l;
 cin>>T;
 while(T--)
{  string p;
 cin>>p;
 Linked_List l;
if(l.Check(p)==true)cout<<"YES"<<endl;
 else cout<<"NO"<<endl;}
return 0;
}
