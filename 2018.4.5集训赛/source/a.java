import java.io.*;
import java.util.*;
import java.math.*;


public class q1 {

	static int Ax,Ay;
	static BigInteger Adiff;

	static boolean compare(BigInteger a,BigInteger b) {
		if (b.compareTo(BigInteger.ZERO)<0)
			return true;
		
		return (a.compareTo(b)<0);
	}
	
	
	static void brute_solve(int n,int z) {
		Ax=Ay=-1;
		Adiff=BigInteger.valueOf(-1);
		boolean init=false;
		
		
		BigInteger bzN = (BigInteger.valueOf(z)).pow(n);
		
		for (int ix=1;ix<z;ix++) {
			BigInteger bx = BigInteger.valueOf(ix);
			BigInteger bxN=bx.pow(n);
			
			for (int iy=ix+1;iy<z;iy++) {
				BigInteger by = BigInteger.valueOf(iy);
				BigInteger byN = by.pow(n);
				
				BigInteger diff=((bxN.add(byN)).subtract(bzN)).abs();
				if (compare(diff,Adiff)==true) {
					Ax=ix;
					Ay=iy;
					Adiff=diff;
				}				
			}
		}
	}

	static void fast_solve(int n,int z) {
		Ax=Ay=-1;
		Adiff=BigInteger.valueOf(-1);
		boolean init=false;
		
		
		int pve_minpos=-1;
		BigInteger bzN = (BigInteger.valueOf(z)).pow(n);
		
		int min_pveY=z-1;
		
		for (int ix=1;ix<z;ix++) {
			BigInteger bx = BigInteger.valueOf(ix);
			BigInteger bxN=bx.pow(n);
			
			boolean is_neg=false;
			
			int start_y=min_pveY;
			for (int iy=start_y;iy>ix;iy--) {
				BigInteger by = BigInteger.valueOf(iy);
				BigInteger byN = by.pow(n);
				
				BigInteger diff=(bxN.add(byN)).subtract(bzN);
				
				int cmp=diff.compareTo(BigInteger.ZERO);
				if (cmp<0)
					is_neg=true;
				
				if (cmp>0)
					if (iy<min_pveY)
						min_pveY=iy;
				
				diff=diff.abs();
				if (compare(diff,Adiff)==true) {
					Ax=ix;
					Ay=iy;
					Adiff=diff;
				}				
				
				if (is_neg) {
					//if (ix%1000==0)
					//	System.out.printf("~ %d %d %s\n",ix,iy, Adiff.toString());
					break;
				}
			}
		}
	}
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
		
		int count,n,z;
		
		count=in.nextInt();
			
		for (int i=0;i<count;i++) {
			n=in.nextInt();
			z=in.nextInt();
			fast_solve(n,z);
			System.out.printf("%d %d %s\n", Ax, Ay, Adiff.toString());
		}
    }

}
