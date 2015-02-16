import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

/*
 * Author:justinzhang
 * Time: 2015-2-16 10:44:31
 * desc: [url] https://www.hackerrank.com/challenges/connecting-towns 
 * 
 * */

public class ConnectionTowns {
	public static void main(String args[]) {
		int T = 0;
		
		Scanner in = new Scanner(System.in);
		
		T = in.nextInt();
		int townNum = 0;
		for(int i = 0; i< T; i++) {
			ArrayList<BigInteger> distances = new ArrayList<BigInteger>();
			townNum = in.nextInt();
			for(int j=0; j < townNum-1; j++) {
				distances.add(in.nextBigInteger());
			}
			
			BigInteger multiply = BigInteger.valueOf(1L);
			for(int k=0; k < townNum-1; k++) {
				multiply = multiply.multiply(distances.get(k));
			}
			System.out.println(multiply.mod(BigInteger.valueOf(1234567L)));
		}
		
		
	}
}
