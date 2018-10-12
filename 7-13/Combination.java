import java.util.*;
import java.util.stream.*;

class Combination{
	private static int count;
	private static int n = 5;
	private static int m = 3;
	private static String[] mozi = {"A","B","C","D","E"};

	public static void main(String[] args) {
		ArrayList<Integer> list = IntStream.range(0, n).
			collect(ArrayList::new,ArrayList::add, ArrayList::addAll);

		disp(list, new ArrayList<>());
		System.out.println("count:" +  count);
	}

	private static void disp(ArrayList<Integer> color, ArrayList<Integer> print) {
		if (print.size() == m) {
			System.out.println(mozi[print.get(0)]+mozi[print.get(1)]+mozi[print.get(2)]);
			count++;
			return;
		}
		for (int i = 0; i < color.size(); i++) {
			ArrayList<Integer> tempColor = (ArrayList<Integer>) color.clone();
			ArrayList<Integer> tempPrint = (ArrayList<Integer>) print.clone();
			tempPrint.add(tempColor.get(i));
			tempColor.remove(i);
			disp(tempColor, tempPrint);
		}
	}
}