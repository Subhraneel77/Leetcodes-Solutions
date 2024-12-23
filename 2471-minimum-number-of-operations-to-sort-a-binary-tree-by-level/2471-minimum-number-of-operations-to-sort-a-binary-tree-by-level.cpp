class Solution {
public:
	int minimumOperations(TreeNode* root) {
		queue<TreeNode*>q;
		q.push(root);
		vector<vector<int>>v;
		while(!q.empty()){
			int l=q.size();
			vector<int>temp;
			for(int i=0; i<l; i++){
				root=q.front();
				temp.push_back(root->val);
				q.pop();
				if(root->left){q.push(root->left);}
				if(root->right){q.push(root->right);}
			}
			v.push_back(temp);
		}
		//for(int i=0; i<v.size(); i++){for(int j=0; j<v[i].size(); j++){cout<<v[i][j]<<" ";}}cout<<endl;
		long long int cnt=0;
		for(int i=0; i<v.size(); i++){
			//unordered_map<int, int>m;
			unordered_map<int, int>m1;
			vector<pair<int, int>>x;
			for(int j=0; j<v[i].size(); j++){
				x.push_back({v[i][j], j});
				//m[v[i][j]]=j;
			}
			sort(x.begin(), x.end());
			for(int k=0; k<x.size(); k++){
				//cout<<x[k].second<<" "<<k<<endl;
				m1[x[k].second]=k;
			}
			// for(int k=0; k<x.size(); k++){
			//     cout<<x[k].first<<" "<<x[k].second<<" "<<m1[x[k].second]<<endl;
			// }cout<<endl;
			for(int k=0; k<x.size(); k++){
				// cout<<endl;
				// cout<<x[k].first<<" "<<x[k].second<<" "<<cnt<<" "<<k<<endl;
				// cout<<endl;
				if(x[k].second==k){continue;}
				else{

					cnt++;
					int l=m1[x[k].second], r=m1[m1[x[k].second]], f2=x[r].second, f1=x[k].second, v1=m1[f1], v2=m1[f2], ind=x[k].second;
					//cout<<l<<" "<<r<<" "<<f1<<" "<<f2<<" "<<v1<<" "<<v2<<endl;
					x[r].second=f1;
					x[l].second=f2;
					m1[f1]=v2;
					m1[f2]=v1;
					//cout<<x[k].first<<" "<<x[k].second<<" "<<cnt<<" "<<k<<endl;
				}
			}
			// for(int k=0; k<x.size(); k++){
			//     cout<<x[k].first<<" "<<x[k].second<<" "<<m1[x[k].second]<<endl;
			// }cout<<endl;
		}
		return cnt;
	}
};