bool checkBFS(int start,int **matrix,int n){
	bool *vis=new bool[n];
	memset(vis,false,sizeof(vis));
	vis[start]=true;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int head=q.front;
		q.pop();
		for(int j=0;j<n;j++)
			if(matrix[head][j]==1&&vis[j]=false){
			vis[j]=true;
			q.push(j);
		}
	}
	//检查所有节点是否都被访问过
	for(int i=0;i<n;i++)
		if(!vis[i]){
			return false;
	}
	return true;
}
