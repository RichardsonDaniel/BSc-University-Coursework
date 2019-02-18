
public class codechanging {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int N = 0;
		
		if(N==0) {
			TextIO.putln("No leaves");
		} else if (N==1) {
			TextIO.putln("One leaf");
		} else if (N==2) {
			TextIO.putln("a couple of leaves");
		} else if (N==3 || N==4 || N==5) {
			TextIO.putln("A handfull of leaves");
		} else if (N>=5) {
			TextIO.putln("More than a handfull of leaves");
		}
	}
}