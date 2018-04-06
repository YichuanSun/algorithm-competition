#include<iostream>
#include<algorithm>
using namespace std;

int location[100005];
int n, c;

bool test(int len){
	int cur_p = 0;
	int cur_c = c-1;

	for(int i=1; i<n; i++){
		if( location[i] - location[cur_p] >= len ){
			cur_p = i;
			cur_c--;
			if(cur_c == 0) return true;
		}
	}
	return false;
}

int main() {

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while(cin>>n>>c, n||c){
		for(int i=0; i<n; i++){
				cin>>location[i];
			}

			sort(location, location+n);

			int l = 0;
			int r = location[n-1];
			int m = 0;

			while(r-l!=1){
					m = (l + r)>>1;
					if(test(m)){
						l = m;
					} else {
						r = m;
					}
			}
			cout << l << endl;
	}
	return 0;
}
