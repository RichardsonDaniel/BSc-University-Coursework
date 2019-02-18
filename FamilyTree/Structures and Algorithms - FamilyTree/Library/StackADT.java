public abstract interface StackADT{
	public abstract boolean push(Object object);
	public abstract Object pop();
	public abstract boolean isEmpty();
	public abstract boolean isFull();
	// the object type stored in the stack should override toString
	public abstract void display();
}
