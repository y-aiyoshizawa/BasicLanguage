import java.util.*;

class Wa{
	public static void main(String[] args) {
		int n = 3;
		int[][] ary = new int[n+1][n];
		for(int i = 0; i < ary.length; i++){
			for(int j = 0; j < ary[0].length; j++){
			}
		}
		for(int i = 0 ; i < n + 1; i++){
			show("■","_");
			if(i == n /2){
				System.out.print("+");
			}else{
				System.out.print(" ");
			}

			show("_","□");
			if(i == n /2){
				System.out.print("=");
			}else{
				System.out.print(" ");
			}

			show("■","□");
			System.out.println();
		 }
	}

	void show(String s1,String s2){
			for(int j = 0 ; j < n - i; j++){
				System.out.print(s1);
			}
			for(int j = 0 ; j < i + 1; j++){
				System.out.print(s2;
			}
	}
}