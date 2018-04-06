#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <ctime>
#define MAX_LEN 30*1000
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int s2xy(string& s, int& x, int& y){
	int sep = s.find(",");
	int sep2 = s.find(")");
	x = atoi(s.substr(1,sep-1).c_str());
	y = atoi(s.substr(sep+1,sep2-sep-1).c_str());
	return 0;
}

int gen_inst(const char* fname, int num){
	FILE *fp = fopen(fname, "w");
	srand(time(NULL));
	for (int k=0; k<num; k++){
		int m = rand() % 901 + 100;
		int n = rand() % 901 + 100;
		fprintf(fp, "%d %d\n", m, n);
		for (int i=0; i<m; i++){
			int x = -10000+rand() % 20001;
			int y = -10000+rand() & 20001;
			fprintf (fp, "(%d,%d)", x,y);
			if (i<m-1){
				fprintf(fp, " ");
			}
		}
		fprintf (fp, "\n");
		for (int j=0; j<n; j++){
			int x = -10000+rand() % 20001;
			int y = -10000+rand() & 20001;
			fprintf (fp, "(%d,%d)", x,y);
			if (j<n-1){
				fprintf(fp, " ");
			}
		}
		fprintf (fp, "\n");
		for (int j=0; j<n; j++){
			int s = rand() % 1000;
			fprintf(fp, "%d", s);
			if (j<n-1){
				fprintf (fp, " ");
			}
		}
		fprintf(fp, "\n");
	}
	fprintf (fp, "0 0\n");
	fclose (fp);
}

int main(int argc, char** argv) {
	//gen_inst(argv[1], atoi(argv[2]));
	//return 0;
	while (1){
		int n, m;
		scanf ("%d %d\n", &m,&n);
		if (n==0 && m==0){
			break;
		}
		vector<int> c(m),d(m);
		//c.resize(m); d.resize(m);
		char aline[MAX_LEN];
		fgets(aline, sizeof(aline), stdin);
		stringstream ss(aline);
		string s;
		int i=0;
		while (getline(ss,s,' ')){
			s2xy(s,c[i], d[i]);
			i++;
		}
		vector<int> a(n), b(n);
		//a.resize(n); b.resize(n);
		fgets(aline, sizeof(aline), stdin);
		stringstream ss2(aline);
		int j=0;
		while (getline(ss2,s,' ')){
			s2xy(s,a[j], b[j]);
			j++;
		}
		for (j=0; j<n; j++){
			int s;
			scanf ("%d", &s);
			int s2 =s*s;
			int res = 0;
			for (int i=0; i<m; i++){
				int dst21 = (c[i]-a[j])*(c[i]-a[j]);
				int dst22 = (d[i]-b[j])*(d[i]-b[j]);
				if (dst21+dst22<=s2){
					res++;
				}	
			}
			printf ("%d", res);
			if (j<n-1){
				printf (" ");
			}
		}
		printf ("\n");
	}
	return 0;
}
