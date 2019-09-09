#include <bits/stdc++.h>
using namespace std;
int cnum(string X,string Y)
{
	string XY=X.append(Y);
	string YX=Y.append(X);
	return XY.compare(YX)>0 ? 1:0;
}
int main()
{
int t;
vector<string> out;
string s;
cin>>t;
	for(int i=0;i<t;i++)
 		{
  			int r;
  			cin>>r;
  			for(int j=0;j<r;j++)
			{
				cin>>s;
				out.push_back(s);
			}
			sort(out.begin(),out.end(),cnum);
			for(i=0;i<out.size();i++)
			{
				cout<<out[i];
			}
      out.clear();
 		}
