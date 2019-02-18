public class ArrayStack implements StackADT{
	private Object[] objects;
	private int top;

	public ArrayStack(){
		int size;
		size=Input.getInteger("input array size: ");
		this.objects=new Object[size];
		this.top=size;
	}
	public boolean push(Object object){
		/* algorithm
		if stack is not full
			note push is successful
			move top to the next available slot
			copy object to the top slot
		else
			note push was unsuccessful
		end if
		*/
		boolean canPush=!this.isFull();
		if (canPush){
			this.top--;
			this.objects[this.top]=object;
		}
		return canPush;
	}
	public Object pop(){
		/* algorithm
		if stack is not empty then
			save the object at the top slot
			delete the object at the top slot
			move top to the next slot
		else
			note that no object is available
		end if
		*/
		Object poppedObject=null;
		if(!this.isEmpty()){
			poppedObject=this.objects[this.top];
			this.objects[this.top]=null;
			this.top++;
		}
		return poppedObject;
	}
	public boolean isEmpty(){
		return this.top==this.objects.length;
	}
	
	public boolean isFull(){
		return this.top==0;
	}
	public void display(){
		/* algorithm
		if stack is not empty then
			for each slot from the top to the end of the array loop
				print out the slot object
			end loop
		else
			print empty stack message
		end if
		*/
		if(!this.isEmpty()){
			for (int index=this.top;index<this.objects.length;index++)
				System.out.print(this.objects[index]+"  ");
			System.out.println();
		}
		else
			System.out.println("stack is empty");
	}
}
