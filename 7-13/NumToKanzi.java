class NumToKanzi{
	private static String[] keta = {"万","億","兆"};
	private static String[] subKeta = {"千","百","十"};
	private static String[] num = {"零","一","二","三","四","五","六","七","八","九"};
	public static void main(String[] args) {
		System.out.println(a(4321));
	}
	private static String a(int n){
		String ret = "";
		for(int i = 0; i < 3; i++){
			ret += String.valueOf(n % 10) + subKeta[i];
			n /= 10;
		}
		return ret + String.valueOf(n);
	}
}