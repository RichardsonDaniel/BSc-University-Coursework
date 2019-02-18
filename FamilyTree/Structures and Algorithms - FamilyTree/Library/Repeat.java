public class Repeat{
	public static boolean repeat(){
	 	boolean result=false;
		char response;
		response=Input.getCharacter("continue(y/n)?  ");
		if (response=='y')
			result=true;
		return result;
	}
}

