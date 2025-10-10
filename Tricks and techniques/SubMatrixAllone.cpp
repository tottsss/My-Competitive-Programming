
int SubMatrixAll_one(vector<vector<int> > &a){
	vector< vector<int> > p(n, vector<int>(n,0));
	for(int i = 0;i < n; i++){
		for(int j = n-1; j >= 0; j--){
			if(a[i][j] == 0) continue;
			if(j != n-1)
			p[i][j] = p[i][j+1];
			p[i][j]++;
		}
	}
	int sub = 0;
	for(int j = 0;j < n; j++){
		int i = n-1, sum = 0;
		stack<pair<int, int> > st;
		while(i >= 0){
			int c = 0;
			while(st.empty()==false and st.top().first > p[i][j]){
				c += (st.top().second+1);
				sum-= (st.top().second+1)*(st.top().first-p[i][j]);
				st.pop();
			}
			sum+= p[i][j];
			st.push(make_pair(p[i][j], c));
			sub+= sum;
			i--;
		}	
	}
	return sub;
}

