#include<iostream>
#include<string>
#include <bits/stdc++.h>
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
int main()
{	int T;
	//cout<<"Enter number of test cases required :";
	cin>>T;
	while(T--){
	string str1,str2,temp;
	string str="";
	int num;
	//cout<<"Enter first number : ";
	cin>>str1;
	//cout<<"Enter second number : ";
	cin>>str2;
	if(compare(str1,str2)==0){temp=str1;str1=str2;str2=temp;}
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
		//"Difference between two numbers is : "
 cout <<str<<endl;
}
 return 0;}
