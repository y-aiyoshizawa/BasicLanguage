import java.math.*;

class Kaijou{
	public static void main(String[] args) {
		BigInteger bi = new BigInteger("1");
		for(int i = 1; i <= 52; i++){
			bi = bi.multiply(new BigInteger(String.valueOf(i)));
			System.out.println("!"+i+" "+bi.toString());
		}
	}
}