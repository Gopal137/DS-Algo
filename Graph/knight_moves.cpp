#include<bits/stdc++.h>
using namespace std;
bool isvalid(int x,int y,int n)
{
    return (x>=0) and (x<n) and y>=0 and y<n;
}
int knight(int xi,int yi,int n,int xf,int yf)
{
    vector<vector<int>> board(n+1,vector<int> (n+1,-1));
    queue<pair<int,int>> q;
    q.push(make_pair(xi,yi));
    board[xi][yi]=0;
    while(!q.empty())
    {
        int X[]={1,2,-1,-2,-1,1,2,-2};
        int Y[]={2,1,-2,-1,2,-2,-1,1};
        auto curr=q.front();
        int x=curr.first;
        int y=curr.second;
        for(int i=0;i<8;i++)
        {
            if(isvalid(x+X[i],y+Y[i],n)==true and board[x+X[i]][y+Y[i]]==-1)
            {
                board[x+X[i]][y+Y[i]]=1+board[x][y];
                q.push(make_pair(x+X[i],y+Y[i]));
            }
        }
        q.pop();
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<board[i][j]<<" ";
        cout<<endl;
    }*/
    return board[xf][yf];
}
int main()
 {
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int xi,yi,xf,yf;
	    cin>>xi>>yi;
	    cin>>xf>>yf;
	    cout<<knight(xi-1,yi-1,n,xf-1,yf-1)<<endl;
	}
	return 0;
}
