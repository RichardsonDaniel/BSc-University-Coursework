
public class ElectricBill {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
	// Question 3	
		String username;
		String password;
		
		TextIO.putln("Please Enter Username:");
		username = TextIO.getln();
		
		
		TextIO.putln("Password:");
		password = TextIO.getln();
		
		if(username.equals("brian") && password.equals("spam"))
			TextIO.putln("Welcome Brian");
		else TextIO.putln("incorrect please try again.");
		
		

	}

}
