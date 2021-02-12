#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main()
{ int T;
	//cout<<"Enter number of test cases required :";
	cin>>T;
	while(T--){
  int flag=0;
  long long int num,i=2;
 // cout<<"Enter  any number : ";
  cin>>num;
  if(num==4){flag=1;}
  while(i*i<num)
  {if(num%i==0) {flag=1;break;}
        i++;
  }
  if(flag==1){cout<<"Not A prime \n";}
  else cout<<"Number entered is a prime \n";}
return 0;
}
