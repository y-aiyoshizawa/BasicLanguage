import java.util.*;
import java.util.stream.*;

class Irowake1 {
	private static int count;
	private static int n = 5;
	private static int m = 3;

	public static void main(String[] args) {
		ArrayList<Integer> list = IntStream.rangeClosed(1, n).mapToObj(Integer::new)
			.collect(ArrayList::new,ArrayList::add, ArrayList::addAll);

		disp(list, new ArrayList<>());
		System.out.println("count:" +  count);
	}

	private static void disp(ArrayList<Integer> color, ArrayList<Integer> print) {
		if (print.size() == m) {
			System.out.println(String.format("A=%d,B=%d,C=%d", print.get(0), print.get(1), print.get(2)));
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