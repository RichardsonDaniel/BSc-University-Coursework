
public class BinarySearchTreeTest {

	public static void main(String[] args) {
	
		int inputAdd;
		int inputDel;
		int option;	
		BinarySearchTree tree=new BinarySearchTree();
		System.out.println("0: quit");
		System.out.println("1: Add 45");
		System.out.println("2: Check for number 45");
		System.out.println("3: Add numbers: 32,25,47,42,50");
		System.out.println("4: Add own number.");
		System.out.println("5: Remove own number.");
		System.out.println("6: See size and height of tree");
		System.out.println("7: Display tree in breadthfirst");
		System.out.println("");
		System.out.println("8: Run predefined test. (5 numbers, Creates its own tree)");
		System.out.println("9: Run predefined test. (10 numbers, Creates its own tree)");
		
		do{

			option=Input.getInteger("Input option: ");
			
			switch(option){
			
				case 1:	tree.add(45);
						System.out.println("Number 45 added");
						break;
						
				case 2:	System.out.println(tree.contains(45));
						break;
						
				case 3:	tree.add(31); tree.add(25); tree.add(47); tree.add(42); tree.add(50);
						System.out.println("Numbers 32, 25, 47, 42 and 50 added");
						break;
	
				case 4: inputAdd=Input.getInteger("Input a number to add: ");
						tree.add(inputAdd);
						break;
						
				case 5:	inputDel=Input.getInteger("Input a number to delete: ");
						tree.remove(inputDel);
						break;
						
				case 6: tree.size();
						tree.height();
						break;
					
				case 7: tree.displayBreadth();
						break;
						
				case 8: BinarySearchTree tree1=new BinarySearchTree();
						System.out.println("");
						System.out.println("# Display tree: #");
						System.out.println("");
						System.out.print(" - "); tree1.displayBreadth();
						System.out.print(" - "); tree1.size();
						System.out.print(" - "); tree1.height();
						System.out.println("");
						tree1.add(37);
						tree1.add(40);
						tree1.add(32);
						tree1.add(23);
						tree1.add(6);						
						System.out.println("# Add: 37, 40, 32, 23 and 6 then display #");
						tree1.displayBreadth();
						System.out.print(" - "); tree1.size();
						System.out.print(" - "); tree1.height();
						System.out.println("");
						System.out.println("# Does tree contain 32? #");
						System.out.print(" - "); System.out.println(tree1.contains(32));
						System.out.println("");
						System.out.println("# Does tree contain 20? #");
						System.out.print(" - "); System.out.println(tree1.contains(20));
						System.out.println("");
						tree1.remove(37);
						tree1.remove(6);
						System.out.println("# Remove 37 and 6 then display.#  ");
						tree1.displayBreadth();
						System.out.print(" - "); tree1.size();
						System.out.print(" - "); tree1.height();
						System.out.println("");
						break;
				
						
				case 9: BinarySearchTree tree2=new BinarySearchTree();
						tree2.add(31);
						tree2.add(25);
						tree2.add(47);
						tree2.add(42);
						tree2.add(50);
						System.out.println("");
						System.out.println("# Display tree: #");
						System.out.println("");
						System.out.print(" - "); tree2.displayBreadth();
						System.out.print(" - "); tree2.size();
						System.out.print(" - "); tree2.height();
						System.out.println("");
						tree2.add(37);
						tree2.add(40);
						tree2.add(32);
						tree2.add(23);
						tree2.add(6);						
						System.out.println("# Add: 37, 40, 32, 23 and 6 then display #");
						tree2.displayBreadth();
						System.out.print(" - "); tree2.size();
						System.out.print(" - "); tree2.height();
						System.out.println("");
						System.out.println("# Does tree contain 25? #");
						System.out.print(" - "); System.out.println(tree2.contains(25));
						System.out.println("");
						System.out.println("# Does tree contain 43? #");
						System.out.print(" - "); System.out.println(tree2.contains(43));
						System.out.println("");
						tree2.remove(37);
						tree2.remove(6);
						System.out.println("# Remove 37 and 6 then display. #");
						tree2.displayBreadth();
						System.out.print(" - "); tree2.size();
						System.out.print(" - "); tree2.height();
						System.out.println("");
						break;
						
			}
		}
		while(option!=0);
	}
}
