import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;


public class BinarySearchTreeTest {
	
	public static void main(String[] args) {
	 

		BinarySearchTree <Integer> tree = new BinarySearchTree(true); // Insert at root tree.
		System.out.println("Root tree created, please insert 5 number sinto tree:");
		System.out.println("");
		int one; one=Input.getInteger("Input first number: ");
		tree.add(one);
		int two; two=Input.getInteger("Input second number: ");
		tree.add(two);
		int three; three=Input.getInteger("Input third number: ");
		tree.add(three);
		int four; four=Input.getInteger("Input fourth number: ");
		tree.add(four);
		int five; five=Input.getInteger("Input fifth number: ");
		tree.add(five);
		System.out.println("");
		System.out.println("**Tree Output: Before**");
		tree.displayBreadth();
		
		
		// From use data class
		try {
			FileOutputStream fos = new FileOutputStream ("data.ser");
			ObjectOutputStream oos = new ObjectOutputStream (fos);
			oos.writeObject(tree);
			System.out.println("Tree Serialized");
			oos.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}

		try {
			FileInputStream fos = new FileInputStream ("data.ser");
			ObjectInputStream ois = new ObjectInputStream(fos);
			BinarySearchTree tree2 = (BinarySearchTree) ois.readObject();
			System.out.println("Tree Deserialized");
			ois.close();
			
			System.out.println("");
			System.out.println("**Tree Output: Deserialized**");
			tree2.displayBreadth();
		}
		catch (Exception e) {
			e.printStackTrace();
		}

	}
}
