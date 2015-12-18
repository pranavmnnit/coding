#include<iostream>
#include<map>
#include<vector>
using namespace	std;


int main(){
int n,x;
cin >> n;
map<int,int> m;
map<int,int> m1;
map<int,int> m2;
map<int,int>::iterator it;
int t=n;
while(t--){
	cin >> x;
	m[x]++;
}

t=n-1;
while(t--){
	cin >> x;
	m1[x]++;
}

for(it=m.begin();it!=m.end();it++){
		if( it->second != m1[it->first] ){
		    cout << it->first << endl;
		m.erase(it);
		break;
	}
}
//second 
t=n-2;
while(t--){
    cin >> x;
	m2[x]++;
}
for(it=m1.begin();it!=m1.end();it++){
		if(it->second != m2[it->first] ){
		cout << it->first << endl;
		m.erase(it);
		break;
	}
}

return 0;
}
