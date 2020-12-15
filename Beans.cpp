/*Link to the problem: https://putka-upm.acm.si/tasks/t/fizol/ */

#include<iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int mx=1e5+9;
int meals[mx];
int farts[mx];
string mealsnames[mx];
int cnts[mx];
map<string,pair<int,int>>totals;
int main(){
    //freopen("file.in","r",stdin);
    int n,m;
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=0;i<n;++i){
        cin>>farts[i];
    }
    for (int i=0;i<m;++i){
        cin>>meals[i];
    }
    for (int i=0;i<m;++i){
        cin>>mealsnames[i];
    }
    for (int i=0;i<n;++i){
        int st=lower_bound(meals,meals+m,farts[i]-720)-meals;
        int en=upper_bound(meals,meals+m,farts[i]-180)-meals;
        if (st<en){
            cnts[st]+=1;
            cnts[en]-=1;
        }
    }
    vector<string> ans;
    int cur=0;
    for (int i=0;i<m;++i){
        cur+=cnts[i];
        if (cur>0){
            totals[mealsnames[i]].first+=1;
        }
        totals[mealsnames[i]].second+=1;
        //cout<<"score "<<i<<" "<<mealsnames[i]<<" "<<cur<<endl;
 
    }
    for (auto&it:totals){
        //cout<<"found "<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        if (it.second.first>=(it.second.second+1)/2){
            ans.push_back(it.first);
        }
    }
    sort(ans.begin(),ans.end());
    for (int i=0;i<ans.size();++i){
        cout<<ans[i]<<" \n"[i==ans.size()-1];
    }

}


