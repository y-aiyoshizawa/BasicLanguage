import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Sortsite {
	//get時に中身を表示するList
	static class DispList extends ArrayList<Integer> {
		@Override
		public Integer get(int index) {
			Integer ret = super.get(index);
			disp(this);
			return ret;
		}
	}

	static Scanner scan = new Scanner(System.in);
	static int row = 0;

	static void sort(int a[]) {
		//TODO
	}

	static void disp(List<Integer> a) {
		disp(a.stream().mapToInt(i -> i).toArray());
	}

	static void disp(int a[]) {
		System.out.print(String.format("%3d : ", row));
		row++;
		for (int i = 0; i < a.length; i++) {
			System.out.print(String.format("%2d,", a[i]));
		}

		System.out.println();
		//Enterが押されるまで待機
		scan.nextLine();
	}

	public static void main(String[] args) {
		List<Integer> temp = new DispList();
		for (int i = 1; i <= 10; i++) {
			temp.add(i);
		}

		disp(temp);
		Collections.shuffle(temp);

		int[] a = temp.stream().mapToInt(i -> i).toArray();

		disp(a);
		sort(a);
		disp(a);
	}
}
