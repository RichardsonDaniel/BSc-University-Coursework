public class SortedLinkedList implements SortedADT{
	protected class ListNode{
		protected Comparable object;
		protected ListNode next;
	}
	protected ListNode head;

	public boolean insert(Comparable object){
		/* algorithm		
		create a new node //will create component object reference
		if list empty then
			add to head of list
		else
			set previous node to head of list
			set current node to head of list
			while checking entries loop
				if current object matches object to be added then
					// attempt to add duplicate object
					checking complete
					insertion fails
				else
					if insertion point found then
						link the new node to the current node
						checking complete
						insertion successful					
						if current node is the head then
						   // add to the front of the list
							link the head to the current node
						else
							link the previous node to the current node
						end if
					else
						if current node is the last in the list
							// add at end
							link the current node to the new node
						   checking complete
						   insertion successful					
						else
							//	move to the next node
							set the previous node as the current node
							set the current node to the next node
						end if
					end if
				end if
			end loop
		end if				
		*/
		boolean inserted=true;
		ListNode newNode=new ListNode();
		newNode.object=object;
		if (this.head==null)
			this.head=newNode;
		else{
			ListNode currentNode=this.head;
			ListNode previousNode=this.head;
			boolean entriesToBeChecked=true;
			while (entriesToBeChecked)
				if (object.compareTo(currentNode.object)==0){
					entriesToBeChecked=false;
					System.out.println(currentNode.object+"already exists");
					inserted=false;
				}
				else
					if (object.compareTo(currentNode.object)<0){
						entriesToBeChecked = false;
						newNode.next=currentNode;
						if (currentNode==this.head)
							this.head=newNode;
						else
							previousNode.next=newNode;
					}
					else
						if (currentNode.next == null){
							entriesToBeChecked = false;
							currentNode.next=newNode;
						}
						else{
							previousNode=currentNode;
							currentNode=currentNode.next;
						}
		}
		return inserted;
	}

	public Comparable remove(Comparable object)	{
		/* algorithm
		previous node to head of list
		set current node to head of list
		while entries to be checked loop
			if object to be removed matches current node object then
				object found
				if current node is the head then
					link the head to the following node
				else
					link the previous node to the following node
				end if
				save the removed object
			else
				if object to be removed is less than the current node object then
					object is not in the list
				else
					if no more objects to compare with then
						object is not in the list
					else
						//	move to the next node
						set the previous node to the current node
						set the current node to the next node
					end if
				end if
			end if
		end loop
		
		*/
		Comparable removedObject=null;
		boolean entriesToBeChecked=this.head!=null;
		ListNode currentNode=this.head;
		ListNode previousNode=this.head;
		while (entriesToBeChecked)
			if (object.compareTo(currentNode.object)==0){
				entriesToBeChecked=false;
				if (currentNode==this.head)
					this.head=currentNode.next;
				else
					previousNode.next=currentNode.next;
				removedObject=currentNode.object;
				currentNode.object=null;
				currentNode.next=null;
			}
			else
				if (object.compareTo(currentNode.object)<0)
					entriesToBeChecked=false;
				else
					if (currentNode.next==null)
						entriesToBeChecked=false;
					else{
						previousNode=currentNode;
						currentNode=currentNode.next;
					}
		return removedObject;
	}

	public Comparable find(Comparable object){
		/* algorithm
  		note head of list as current node
  		while entries to be checked loop
    		if searched for object matches current node object then
      		object found
    		else
      		if searched for object is less than current object then
       			object is not in the list
      		else
        			if no more objects to compare with then
          			object is not in the list
        			else
          			// move to the next node
          			set the current node to the next node
        			end if
     			end if
    		end if
  		end loop
		*/

		ListNode currentNode=this.head;
		boolean entriesToBeChecked=currentNode!=null;
		Comparable foundObject=null;
		while (entriesToBeChecked)
			if (currentNode.object.compareTo(object)==0){
				entriesToBeChecked=false;
				foundObject=currentNode.object;
			}
			else
				if (object.compareTo(currentNode.object)<0)
					entriesToBeChecked=false;
				else{
					currentNode=currentNode.next;
					if (currentNode==null)
						entriesToBeChecked=false;
				}
		return foundObject;
	}

	public void display(){
		/* algorithm
		set current node to first node in list
		if empty list then
			output message
		else
			while nodes remain loop
				display details of object at current node
				move to next node
			end loop
		end if
		*/
		ListNode currentNode=this.head;
		if(currentNode==null)
			System.out.println("list is empty");
		else
			while (currentNode!=null)			{
				System.out.println(currentNode.object);
				currentNode=currentNode.next;
			}
	}
}


