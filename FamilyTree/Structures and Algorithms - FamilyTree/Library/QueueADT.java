public abstract interface QueueADT{
	public abstract boolean add(Object object);
	public abstract Object remove();
	public abstract boolean isEmpty();
	public abstract boolean isFull();
	// the object type stored in the queue should override toString
	public abstract void display();
}
