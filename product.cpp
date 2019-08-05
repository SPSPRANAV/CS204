#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main()
{	int T;
	//cout<<"Enter number of test cases required :";
	cin>>T;
	while(T--){
	string str1,str2;
	string str="";
  int arr[100][100];
	//cout<<"Enter first number : ";
	cin>>str1;
	//cout<<"Enter second number : ";
	cin>>str2;
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
		//"The product of two numbers is : "
		 cout << str<<endl;
	 }
     return 0;
}
