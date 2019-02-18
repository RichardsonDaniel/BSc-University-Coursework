
public class FamilyTree {
	
	private class FamilyTreeNode{
		private FamilyTreeNode treetop;
		
		private String name;
		private FamilyTreeNode partner;
		private FamilyTreeNode sibling;
		private FamilyTreeNode child;
	}
	
	private FamilyTreeNode ancestor;
	private FamilyTreeNode current;
	
	public FamilyTree(String ancestorName){
		this.ancestor=new FamilyTreeNode();
		this.ancestor.name=ancestorName;
		this.current=this.ancestor;
	}
	
	//
	// Addition to the tree structure
	//
	
	public void addChild(String name){
		FamilyTreeNode child=new FamilyTreeNode();
		child.name=name;
		child.treetop=current;
		if(current.partner!=null){
			if(current.child==null)
				current.child=child;
			else{
				FamilyTreeNode next=current.child;
				while(next.sibling!=null)
					next=next.sibling;
					next.sibling=child;
			}
		}
	}

		
	public void addPartner(String name){
		FamilyTreeNode partner=new FamilyTreeNode();
		partner.name=name;
		partner.treetop=current;
		if(partner!=null){
				if(current.partner==null){
					current.partner=partner;
				}
				else{
					FamilyTreeNode next=current.partner;
					System.out.println("this member already has a partner");
					while(next.partner!=null)
						next=next.partner;
						next.partner=partner;
				}
		}
	}
	
	//
	// Searching the tree for identifiers/names
	//
	
	public boolean findFamMember(String name){
		boolean found=false;
		FamilyTreeNode member=this.ancestor;
		if(name.equalsIgnoreCase(member.name))
			found=true;
		else{
			FamilyTreeNode saved=member;
			member=this.checkChild(saved,name);
			if(member!=null)
				found=true;
			else{
				member=this.checkSiblings(saved,name);
				if(member!=null)
					found=true;
				else{
					member=this.checkPartners(saved, name);
					if(member!=null)
						found=true;
				}
			}
			
		}
		if(found){
			this.current=member;
			this.displayFamilyMember();
		}
		return found;
	}
		
	private FamilyTreeNode checkChild(FamilyTreeNode check,String name){
		FamilyTreeNode Child=check.child;
		boolean searching=true;
		while(searching)
			if(Child==null)
				searching=false;
			else
				if(Child.name.equalsIgnoreCase(name))
					searching=false;
				else
					Child=Child.sibling;
		return Child;
	}
		
	private FamilyTreeNode checkSiblings(FamilyTreeNode check,String name){
		FamilyTreeNode sibling=check.sibling;
		boolean searching=true;
		while(searching)
			if(sibling==null)
				searching=false;
			else
				if(sibling.name.equalsIgnoreCase(name))
					searching=false;
				else{
					check=this.checkChild(sibling, name);
					if(check!=null){
						sibling=check;
						searching=false;
					}
					else
						sibling=sibling.sibling;
				}
		return sibling;
	}
	
	private FamilyTreeNode checkPartners(FamilyTreeNode check,String name){
		FamilyTreeNode partner=check.partner;
		boolean searching=true;
		while(searching)
			if(partner==null)
				searching=false;
			else
				if(partner.name.equalsIgnoreCase(name))
					searching=false;
				else{
					check=this.checkChild(partner, name);
					if(check!=null){
						partner=check;
						searching=false;
					}
					else
						partner=partner.partner;
				}
		return partner;
	}
	
	//	
	// Different Display options, full and more refined
	//
	
	//displays currently selected and immediate family of current, parents and children
	public void displayFamilyMember(){
		System.out.print(current.name);
		if(current.treetop!=null)
			System.out.println(" is a child of "+current.treetop.name+".");
		else
			System.out.println(" is the top of the tree");
		this.displayChild(current);
	}
	
	//displays full tree from the beginning
	public void displayFamily(){
		FamilyTreeNode partner=ancestor.partner;
		FamilyTreeNode member;
		member=ancestor.child;
		System.out.print(ancestor.name);
		if(partner!=null){
			System.out.println(" partner: "+partner.name);
			partner=partner.partner; 
			}
		else
			System.out.println(" has no partner");
		while(member!=null){
			System.out.print("  "+member.name);
			this.displayChild(member);
			member=member.sibling;
		}
	}
	
	//used to display family down the tree
	private void displayChild(FamilyTreeNode current){
		FamilyTreeNode child=current.child;
		FamilyTreeNode partner=current.partner;
		if(partner!=null){
			System.out.println(" partner: "+partner.name);
			partner=partner.partner; 
			}
		else
			System.out.println(" has no partner");
		while(child!=null){
			System.out.print("    "+child.name);
			child=child.sibling;
			System.out.println("    ");
		}
	}
}
