
public class FamilyTreeTest {

	public static void main(String[] args) {
		
		String name=Input.getString("input the ancestor's name: ");

		
		FamilyTree tree=new FamilyTree(name);
		int option;
		boolean uniquechild;
		
		tree.addPartner(Input.getString("input partner's name: "));
		
		do{
			System.out.println("0: quit");
			System.out.println("1: add child");
			System.out.println("2: display family tree");
			option=Input.getInteger("input option: ");
			
			switch(option){
			
				case 1:	name=Input.getString("input the child's name: ");
						uniquechild=tree.findFamMember(name);
						if(!uniquechild)
							tree.addChild(name);
						else
							System.out.println("Child name already exists");
						break;
						
				case 2:	tree.displayFamily();
						break;
						
			}
		}while(option!=0);
	}
}
