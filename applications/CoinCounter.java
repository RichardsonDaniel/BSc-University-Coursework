
public class CoinCounter {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int twoPounds, onePound, fiftyPence, twentyPence,
		tenPence, fivePence, twoPence, onePence; 
		int total = 0;
		
		TextIO.put("How many Two pound coins do you have?");
		twoPounds = TextIO.getlnInt();
		total = total + twoPounds*200;
		TextIO.put("How many one pound coins do you have?");
		onePound = TextIO.getlnInt();
		total = total + onePound*100;
		TextIO.put("How many Fifty pence coins do you have?");
		fiftyPence = TextIO.getlnInt();
		total = total + fiftyPence*50;
		TextIO.put("How many Twenty pence coins do you have?");
		twentyPence = TextIO.getlnInt();
		total = total + twentyPence*20;
		TextIO.put("How many Ten pence coins do you have?");
		tenPence = TextIO.getlnInt();
		total = total + tenPence*10;
		TextIO.put("How many Five pence coins do you have?");
		fivePence = TextIO.getlnInt();
		total = total + fivePence*5;
		TextIO.put("How many Two pence coins do you have?");
		twoPence = TextIO.getlnInt();
		total = total + twoPence*2;
		TextIO.put("How many One pence coins do you have?");
		onePence = TextIO.getlnInt();
		total = total + onePence;
		TextIO.put("You Have ");
		TextIO.put("£" + total/100);
		TextIO.putln("." + total % 100);
		
	}

}
