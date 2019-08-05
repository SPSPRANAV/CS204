#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int compare(string a1,string b1)
{
  while(a1.at(0)=='0'&&a1.length()>1 )
  {
    a1.erase(a1.begin());
  }
  while(b1.at(0)=='0'&&b1.length()>1 )
  {
    b1.erase(b1.begin());
  }
  int length1=a1.length();
  int length2=b1.length();
  if(length1>length2) return 1;
  if(length1<length2) return 0;
  if (length1==length2)
  {
    for(int i=0;i<length1;i++)
    { if (a1.at(i)==b1.at(i))
      {
        if(i==length1-1) return 1;
        continue;
      }
      if(a1.at(i)<b1.at(i)) return 0;
      if(a1.at(i)>b1.at(i)) return 1;
    }
  }
}
string difference(string a,string c)
{

  	string str1=a,str2=c;
  	string str="";
  	int num;
  	int l1=str1.length();
  	int l2=str2.length();
  	int l;int b=0;
  	if(l1>l2) l=l1;
  	else l=l2;
  	for(int i=0;i<l;i++)
  	{
  		int s1,s2;
  		if(l1-1-i>=0) s1=str1.at(l1-1-i)-'0';
  		else s1=0;
  		if(l2-1-i>=0) s2=str2.at(l2-1-i)-'0';
  		else s2=0;
  		if((s1-s2+b)>=0){ num=s1-s2+b;b=0;}
  		else{ num=s1-s2+b+10;b=-1;}
  		std::string str3 = std::to_string(num);
  		str=str+str3;}

  reverse(str.begin(), str.end());
   return str;
}
int main()
{int T;
	//cout<<"Enter number of test cases required :";
	cin>>T;
	while(T--){
  string str1,str2,remainder,quotient;
  int count;
 // cout<<"Enter first number : ";
  cin>>str1;
  //cout<<"Enter second number : ";
  cin>>str2;
  int l1=str1.length();
	int l2=str2.length();
  int i,j=0;
  if(compare(str1.substr(0,l2),str2)==1)
  {
    remainder= str1.substr(0,l2);
    while(compare(remainder,str2)==1)
    {
      while(compare(remainder,str2)==1)
      {
        count=0;
        while(compare(remainder,str2)==1)
        {

          remainder=difference(remainder,str2);
          count++;
        }
        quotient.push_back(count+'0');
      }
      for(i=j;str1[l2+i]!='\0';i++)
      {
    if(compare(remainder=remainder+str1.substr(l2+i,1),str2)==1)
    {
      j=i+1;
      break;
    }
    else
     {
        quotient.push_back('0');
     }
    }
   }
  }else
  {
    remainder=str1.substr(0,l2+1);
      while(compare(remainder,str2)==1)
    {
      while(compare(remainder,str2)==1)
      {
        count=0;
        while(compare(remainder,str2)==1)
        {
          remainder=difference(remainder,str2);
          count++;
        }
  quotient.push_back(count+'0');
      }
      for(i=j;str1[l2+i+1]!='\0';i++)
      {
    if(compare(remainder=remainder+str1.substr(l2+i+1,1),str2)==1)
    {
      j=i+1;
      break;
    }
    else
     {
        quotient.push_back('0');
     }
    }
   }
  }
  if(quotient==""){quotient="0";}
//"The quotient of the division is : 
  cout <<quotient<< endl;
  while(remainder.at(0)=='0'&&remainder.length()>1 )
  {
    remainder.erase(remainder.begin());
  }
//"The remainder of the division is : 
  cout <<remainder<< endl;

}
  return 0;
}
