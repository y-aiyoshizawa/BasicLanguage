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
			return ret;
		}
	}

	static Scanner scan = new Scanner(System.in);
	static int row = 0;

	static void mergeSort(int[] a) {

		if (a.length > 1) {
			int m = a.length / 2;
			int n = a.length - m;
			int[] a1 = new int[m];
			int[] a2 = new int[n];

			for (int i = 0; i < m; i++)
				a1[i] = a[i];
			for (int j = 0; j < n; j++)
				a2[j] = a[m + j];

			mergeSort(a1);
			mergeSort(a2);
			merge(a1, a2, a);
		}
	}

	static void merge(int[] a1, int[] a2, int[] a) {
		int i = 0;
		int j = 0;

		while (i < a1.length && j < a2.length) {
			if (a1[i] < a2[j]) {
				a[i + j] = a1[i];
				i++;
			} else {
				a[i + j] = a2[j];
				j++;
			}
		}
		if (i < j) {
			while (i < a1.length) {
				a[i + j] = a1[i];
				i++;
			}
		} else {
			while (j < a2.length) {
				a[i + j] = a2[j];
				j++;
			}
		}
		disp(a);
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

		Collections.shuffle(temp);

		int[] a = temp.stream().mapToInt(i -> i).toArray();

		disp(a);
		mergeSort(a);
	}
}