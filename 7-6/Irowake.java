import java.util.*;
import java.util.stream.*;

class Irowake{
	public static void main(String[] args) {
		Deque<Integer> iro = IntStream.range(1,5)
			.mapToObj(Integer::new)
			.collect(ArrayDeque::new,ArrayDeque::add,ArrayDeque::addAll);
		disp(iro,"");
	}
	static void disp(Deque<Integer> iro,String str){
		if(iro.size() <= 1){
			System.out.println(str);
			return;
		}
		str += String.valueOf(iro.poll());
		System.out.println(str);
		disp(iro,str);
	}
}