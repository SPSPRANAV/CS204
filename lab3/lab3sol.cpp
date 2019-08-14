#include<iostream>
#include<string>
using namespace std;
//Creating a node for creation of Stack using Linked List
struct node
{
  char data;
  struct node* ptr;
};
//Creating a class name Linked_List which contains functions named push,pop(which has inbuilt top function in it),isEmpty
//Also has Check function which checks the correctness of the expression entered
class Linked_List
{
public:
  struct node* head;
  Linked_List()
  {
    head=NULL;
  }
 //PUSH FUNCTION WHICH INTAKES A char variable x and returns nothing
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
        break;
      }
      else next=next->ptr;
  }

  }
   //POP FUNCTION WHICH INTAKES nothing and returns the character which was popped out
  char pop()
  { char x;
    struct node* next;
    struct node* prev;
    if(head==NULL) return 'E';
    if(head->ptr==NULL)
    {  x=head->data;
      head=NULL;return x;}
      next=head->ptr;
      prev=head;
    while(true)
    {
      if(next->ptr==NULL)
      {  x=next->data;
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
   //isEmpty FUNCTION WHICH INTAKES nothing and returns 1 if the stack is empty and returns 0 otherwise
  int isEmpty()
  {
    int a=0;
    if(head==NULL) a=1;
    return a;
  }
   //CHECK FUNCTION WHICH INTAKES A string input p and returns whether the expression is legitimate or not
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
    }
    if(isEmpty()==1) return true;
    else return false;
  }
};
//MAIN FUNCTION
int main()
{ int T;
 //Inputting the no.of test cases
 cin>>T;
 while(T--)
{  string p;
 cin>>p;
 Linked_List l;
if(l.Check(p)==true)cout<<"YES"<<endl;
 else cout<<"NO"<<endl;}
return 0;
}
