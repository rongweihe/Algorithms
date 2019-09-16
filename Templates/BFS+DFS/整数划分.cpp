//Create By@herongwei 2019/09/16
//整数划分 回溯法

int counts(vector<int>& curData)
{
    int sum=0;
    for(int i=0; i<curData.size(); ++i)
    {
        sum += curData[i];
    }
    return sum;
}

void func(vector<vector<int>>& ret, vector<int>& curdata, int index,int n)
{
    if(counts(curdata)==n)
    {
        ret.push_back(curdata);
        return;
    }
    if(counts(curdata)>n) return;
    for(int i=index; i<=n; ++i)
    {
        curdata.push_back(i);
        func(ret,curdata,i,n);
        curdata.pop_back();
    }
}

int main()
{
	// freopen("in.txt","r",stdin);
	cin>>n;
	vector<vector<int> > ret;
	vector<int> curData;
	func(ret,curData,1,n);
	for(int i=0; i<ret.size(); ++i)
    {
        string t = "";
        int k= ret[i].size();
        for(int j=0; j<k-1; ++j)
        {
            t += to_string(ret[i][j]);
            t += "+";
        }
        t += to_string(ret[i][k-1]);
        cout<<t<<endl;
    }
    return 0;
}

/*
sample output
n=4
1+1+1+1
1+1+2
1+3
2+2
4
*/
