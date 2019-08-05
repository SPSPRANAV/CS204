#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
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
string add(string str1,string str2)
{
	string str="";
	int l1=str1.length();
	int l2=str2.length();
	int l;int c=0;
	if(l1>l2) l=l1;
	else l=l2;
	for(int i=0;i<l+1;i++)
	{  if (l1==l2)
	     {int s1,s2;
   		if(l1-1-i>=0) s1=str1.at(l1-1-i)-'0';
   		else s1=0;
   		if(l2-1-i>=0) s2=str2.at(l2-1-i)-'0';
   		else s2=0;
   		std::string str3 = std::to_string(s1+s2+c-((s1+s2+c)/10)*10);
   		c=(s1+s2+c)/10;
   		str=str+str3;}
	   else{
		int s1,s2;
		if(l1-1-i>=0) s1=str1.at(l1-1-i)-'0';
		else s1=0;
		if(l2-1-i>=0) s2=str2.at(l2-1-i)-'0';
		else s2=0;
		std::string str3 = std::to_string(s1+s2+c-((s1+s2+c)/10)*10);
		c=(s1+s2+c)/10;
		str=str+str3;}}

reverse(str.begin(), str.end());
while(str.at(0)=='0'&&str.length()>1 )
{
  str.erase(str.begin());
}
 return str;
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
  while(str.at(0)=='0'&&str.length()>1 )
  {
  	str.erase(str.begin());
  }
   return str;
}
string product(string str1,string str2)
{	string str="";
  int arr[100][100];
	int l1=str1.length();
	int l2=str2.length();
	int l;int c=0;
	if(l1>l2) l=l1;
	else l=l2;
  for(int i=0;i<l;i++)
  {
    for(int j=0;j<l;j++)
    {int s1,s2;
      if(l1-1-i>=0) s1=str1.at(l1-1-i)-'0';
   		else s1=0;
   		if(l2-1-j>=0) s2=str2.at(l2-1-j)-'0';
   		else s2=0;
      arr[i][j]=s1*s2;
    }
  }
for(int k=0;k<2*l;k++)
{ int s=0,p;
   for(int i=0;i<l;i++)
  {
    for(int j=0;j<l;j++)
      {
      if (k==i+j) s=s+arr[i][j];
      }
    }
    std::string str3 = std::to_string(s+c-((s+c)/10)*10);
    c=((s+c)/10);
    str=str+str3;}
    reverse(str.begin(), str.end());
    while(str.at(0)=='0'&&str.length()>1 )
		{
			str.erase(str.begin());
		}
     return str;
}
string remainder(string str1,string str2)
{
  string remainder,quotient;
  int count;
  int l1=str1.length();
	int l2=str2.length();
  int i,j=0;
  if(compare(str1.substr(0,l2),str2)==1)
  {
    remainder = str1.substr(0,l2);
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
  while(remainder.at(0)=='0'&&remainder.length()>1 )
  {
    remainder.erase(remainder.begin());
  }
return remainder;
}
int main()
{ int T;
	//cout<<"Enter number of test cases required :";
	cin>>T;
	while(T--){
  int flag=0;
  string num,i="2",d="0",next="1";
 // cout<<"Enter  any number : ";
  cin>>num;
  auto start = high_resolution_clock::now();
  if(num=="4"){flag=1;}
  while(compare(product(i,i),num)==0)
  {
      if(remainder(num,i)==d) {flag=1;break;}
        i=add(i,next);

  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  if(flag==1){cout<<"Not A prime \n";}
  else cout<<"Number entered is a prime \n";
//  cout <<"Time taken to verify in microseconds is : " <<duration.count() << endl; 
}
return 0;
}
