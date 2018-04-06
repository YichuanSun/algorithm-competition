import java.io.*;
import java.util.*;
import java.math.*;


public class q2 {
	static int MAX_SIZE=10000;
	static boolean[][] B;
	
	static void init(int n) {
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			B[i][j]=false;
	}
	
	static void flip(int x, int y) {
		B[x][y]=!(B[x][y]);
	}
	
	static void flip(int x1, int x2, int y1, int y2) {
		flip(x2,y2);
		if (x1>1) flip(x1-1,y2);
		if (y1>1) flip(x2,y1-1);
		if ((x1>1)&&(y1>1)) flip(x1-1,y1-1);
	}
	
	static boolean xor(boolean a,boolean b) {
		if (b==true)
			return (!a);
		else
			return a;
	}
	
	static int computeCount(int n) {
		for (int j=1;j<=n;j++) {
			//pushRowLeft(n,j)
			for (int z=n-1;z>=1;z--)
				B[z][j]=xor(B[z][j],B[z+1][j]);
		}
				
		for (int i=1;i<=n;i++) {
			//pushColDown(n,i);
			for (int z=n-1;z>=1;z--)
				B[i][z]=xor(B[i][z],B[i][z+1]);
		}
			
		int sum=0;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (B[i][j]==true)
				sum++;
		return sum;
	}
	
	static void print_matrix(boolean[][] B, int n) {
		for (int j=n;j>=1;j--) {
			for (int i=1;i<=n;i++) 
				System.out.printf("\t%d",(B[i][j]==true)?1:0);
			System.out.println();
		}
	}
	
	static void generate(int n,int k) {
		Random rand=new Random();
		
		int x1,x2,y1,y2,temp;

		System.out.printf("%d %d\n", n, k);
		for (int j=0;j<k;j++) {
			x1=rand.nextInt(n)+1;
			x2=rand.nextInt(n)+1;
			if (x1>x2)
			{ temp=x1; x1=x2; x2=temp; }
			
			y1=rand.nextInt(n)+1;
			y2=rand.nextInt(n)+1;
			if (y1>y2)
			{ temp=y1; y1=y2; y2=temp; }
			
			System.out.printf("%d %d %d %d\n", x1, x2, y1, y2);
		}
		
		System.exit(0);
	}
	
	
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		B=new boolean [MAX_SIZE+1][MAX_SIZE+1];
		
		int count,n,k;
		int x1,x2,y1,y2;
		
		//generate(9999,9999);
		
		count=in.nextInt();
		for (int i=0;i<count;i++) {
			n=in.nextInt();
			k=in.nextInt();			
			init(n);
			
			//System.out.printf("%d %d\n", n, k);
			for (int j=0;j<k;j++) {
				x1=in.nextInt();
				x2=in.nextInt();
				y1=in.nextInt();
				y2=in.nextInt();
				//System.out.printf("+ %d %d %d %d\n", x1, x2, y1, y2);
				flip(x1,x2,y1,y2);
			}
			//print_matrix(B,n);
			
			System.out.printf("%d\n", computeCount(n));
			//print_matrix(B,n);
		}
    }

}
