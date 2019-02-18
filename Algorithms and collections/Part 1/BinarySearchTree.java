import java.util.*;

/** Part A - intended and actual changes within.
 * 
 * The input class is used merely as a form of user controllability allowing the user to apply
 * their own tests or events, this is from a previous module.
 * 
 * Changes Intended:
 *  - The first part of the course work is to amend the BinarySearchTree<E> class discussed
 *    in the lecture so that it represents an extended binary search tree. Whenever a new value
 *    is inserted into the tree the result is that an external node is replaced by an internal 
 *    node containing that value and two external nodes (where the external nodes are the left
 *    and right children of the new internal node).
 *    
 *  - Add isExternal method
 *  - Add makeExternal method
 *  - Add makeInternal method
 *  - Edit functions to use new methods
 *  - Constructor for creation or external/internal
 *  - Method to display height of tree (including externals)
 *  - Breadth first traversal display
 *  
 * Changes Performed, creations:
 * 
 *  - Created a method in Entry<E> class for checking if external or not by comparing if element right child
 *    and left child are all null. Returns true if external and false if not.
 *  		Public boolean isExternal()
 *  
 *  - Created a method in Entry<E> class for making external by setting element left child and right child to null.
 *  		public E makeExternal()
 *  
 *  - Created a method in Entry<E> class for making internal by making element element and making children external nodes.
 *  		public void makeInternal (E element)
 *  
 *  - Created constructor method in Entry<E> class to make either internal or external by choice.
 *  		public Entry(E element, Entry<E> parent, boolean makeInternal)
 *  
 *  - Created method to check is tree is empty or not, if it is returns 0, if it is not it is passed to the find height
 *    method which will find the height including externals.
 *    		public int height()
 *    
 *  - Created method to find the height of the tree if it not empty which includes the externals. Returns 0 if external node
 *    and returns 1 + longest tree length
 *  		public int findHeight(Entry<E> entry)
 *  
 *  - Created breadth first traversal display method to show tree in a easily recognized way.
 *  		public void displayBreadth()
 *  
 *	  Breadth traversal created using example from page 392 of William J Collins book
 *	  chapter 9 (Data structures and the java collection framework.
 *  
 *			if (t is not empty) 
 *			{
 *				queue.enqueue (t);
 *				while (queue is not empty)
 *				 {
 *					tree = queue.dequeue();
 *					process tree���s root;
 *					if (leftTree (tree) is not empty)
 *						queue.enqueue (leftTree (tree));
 *					if (rightTree (tree) is not empty)
 *						queue.enqueue (rightTree (tree));
 *				 } // while
 *				} // if t not empty
 *			} // breadthFirst traversal
 *
 *  Changes Performed, editing to use new methods moving down the class:
 *  
 *	- Added to the add method so that it would now use the new methods created earlier, changes include
 *	  checking if a child is external using isExternal method and then if so changing it to a internal node
 *	  using makeInternal instead of checking for null.
 *                	// Handle left
 *                    if (temp.left.isExternal()){ // if external
 *                   	temp.left.makeInternal (element); // make internal
 *                   	size++;
 *                   	return true;
 *                   }
 *                   else 
 *                       temp = temp.left;
 *               
 *               	// Handle right
 *                   else if (temp.right.isExternal()) { // if external
 *                       temp.right.makeInternal(element); // make internal
 *                       size++;       
 *                       return true;
 *                   }
 *                   else 
 *                       temp = temp.right;
 *  
 *  - Added to getEntry() to check e with isExternal instead of checking for null.
 *  		while (!e.isExternal())
 *  
 *  - Added to deleteEntry() to check against isExternal instead of checking for null.
 * 		    if (p.left.isExternal() && p.right.isExternal()) 
 *  
 *  - Added to the successor method the use of isExternal to return null when e is external
 *    also instead of checking if the child is not null it now checks that the child's
 *    element is not null.
 *    		if (e == null || e.isExternal())
 *    
 *    		else if (e.right.element != null) 
 *    
 *    	    while (p.left.element != null)
 *    
 *  - Added to the TreeIterator so now the while loops continues until node is classed
 *    as external by isExternal instead of just being null.
 *    		while (next.left.isExternal()) 
 *  
 **/

public class BinarySearchTree<E> extends AbstractSet<E> 
{

	protected Entry<E> root;

    protected int size;

    /**
     *  Initializes this BinarySearchTree object to be empty, to contain only elements
     *  of type E, to be ordered by the Comparable interface, and to contain no 
     *  duplicate elements.
     */ 
    public BinarySearchTree() 
    {
        root = null;
        size = 0; 
    } // default constructor

    /**
     *  Checks to see if tree is empty or not, if so return that tree has 0 nodes
     *  if not pass to findHeight method to find the height then return the result.
     */
    public int height() {
    	int Height;
    	if (root==null)
    		Height = 0;
    	else
    		Height = findHeight(root);
    	System.out.println("Tree Height (including externals): " + Height);
    	return Height;
    }
    
    /**
     *  Finds the height of a tree passed in by the Height method, returns 0 if the
     *  node is external and returns 1 + longest tree length
     */
    public int findHeight(Entry<E> entry) {
    	if (entry.isExternal())
    		return 0;
    	else
    		return 1 + Math.max(findHeight(entry.left),findHeight(entry.right));
    }
    
    /**
     *  Breadth first traversal display method to show tree in a easily recognized
     *  way using example algorithm from book.
     */
    /** Example algorithm from book. Open to view. 
     * 
     *  Breadth traversal created using example from page 392 of William J Collins book
     *  chapter 9 (Data structures and the java collection framework.
     *  
     *		if (t is not empty) 
     *		{
	 *			queue.enqueue (t);
	 *			while (queue is not empty)
	 *			 {
	 *				tree = queue.dequeue();
	 *				process tree���s root;
	 *				if (leftTree (tree) is not empty)
	 *					queue.enqueue (leftTree (tree));
	 *				if (rightTree (tree) is not empty)
	 *					queue.enqueue (rightTree (tree));
	 *			 } // while
	 *			} // if t not empty
	 *		} // breadthFirst traversal
	 *
     */
    public void displayBreadth() {
		Entry entry = root;
		int nullSize = 2*size + 1; // Size of tree including nodes
		String[] Elements = new String[size]; 
		String[] ElementsNull = new String[nullSize];
		Queue<Entry> queue = new LinkedList<Entry>();
		
		if (entry != null) { 												//if (t is not empty)			
			queue.add(entry); 												// queue.enqueue (t);
			int a = 0;
			int b = 0;
			while (!queue.isEmpty()) { 											// while (queue is not empty)
				Entry temp = queue.remove();								// tree = queue.dequeue();
				if (temp.element == null)									// process tree roots
					ElementsNull[a] = "null";
				else {
					ElementsNull[a] = temp.element.toString();
					Elements[b] =  temp.element.toString();
					b++;
				}
				a++;
				if (temp.left != null)										// if (leftTree (tree is not empty)
					queue.add(temp.left);									// queue.enqueue (leftTree (tree));
				if (temp.right != null)										// if (rightTree (tree is not empty)
					queue.add(temp.right);									// queue.enqueue (rightTree (tree));
			}
			System.out.println("");											//display
			System.out.println("Breadth-first Traversal with null nodes:: "); 
			for (int c = 0; c < nullSize; c++)
				System.out.print(ElementsNull[c] + "   ");
			System.out.println("");
			System.out.println("Breadth-first Traversal:: ");
			for (int d = 0; d < size; d++)
				System.out.print(Elements[d] + "   ");
			System.out.println("");
			System.out.println("");
		} 
		else 
			System.out.println("Tree has no nodes.");
	}
    
    /**
     * Initializes this BinarySearchTree object to contain a shallow copy of
     * a specified BinarySearchTree object.
     * The worstTime(n) is O(n), where n is the number of elements in the
     * specified BinarySearchTree object.
     *
     * @param otherTree - the specified BinarySearchTree object that this
     *                BinarySearchTree object will be assigned a shallow copy of.
     *
     */
    public BinarySearchTree (BinarySearchTree<? extends E> otherTree)
    {
         root = copy (otherTree.root, null);
         size = otherTree.size;  
    } // copy constructor


    protected Entry<E> copy (Entry<? extends E> p, Entry<E> parent)
    {
        if (p != null)
        {
            Entry<E> q = new Entry<E> (p.element, parent);
            q.left = copy (p.left, q);
            q.right = copy (p.right, q);
            return q;
        } // if
        return null;
    } // method copy
        
    public boolean equals (Object obj)
    {
        if (!(obj instanceof BinarySearchTree))
            return false;
        return equals (root, ((BinarySearchTree<? extends E>)obj).root);
    } // method 1-parameter equals
    
    public boolean equals (Entry<E> p, Entry<? extends E> q)
    {
       if (p == null || q == null)
           return p == q;
       if (!p.element.equals (q.element))
           return false;
       if (equals (p.left, q.left) && equals (p.right, q.right) )
           return true;            
       return false;     
    } // method 2-parameter equals
    
    /**
     *  Returns the size of this BinarySearchTree object.
     *
     * @return the size of this BinarySearchTree object.
     *
     */
    public int size( )
    {
        System.out.println("Tree size: " + size);
		return 0;
    } // method size()
  

    /**
     *  Returns an iterator positioned at the smallest element in this 
     *  BinarySearchTree object.
     *
     *  @return an iterator positioned at the smallest element in this
     *                BinarySearchTree object.
     *
     */
    public Iterator<E> iterator()
    {
         return new TreeIterator();
    } // method iterator

    /**
     *  Determines if there is at least one element in this BinarySearchTree object that
     *  equals a specified element.
     *  The worstTime(n) is O(n) and averageTime(n) is O(log n).  
     *
     *  @param obj - the element sought in this BinarySearchTree object.
     *
     *  @return true - if there is an element in this BinarySearchTree object that
     *                equals obj; otherwise, return false.
     *
     *  @throws ClassCastException - if obj cannot be compared to the 
     *           elements in this BinarySearchTree object. 
     *  @throws NullPointerException - if obj is null.
     *  
     */ 
    public boolean contains (Object obj) 
    {
        return getEntry (obj) != null;
    } // method contains

 

    /**
     *  Ensures that this BinarySearchTree object contains a specified element.
     *  The worstTime(n) is O(n) and averageTime(n) is O(log n).
     *
     *  @param element - the element whose presence is ensured in this 
     *                 BinarySearchTree object.
     *
     *  @return true - if this BinarySearchTree object changed as a result of this
     *                method call (that is, if element was actually inserted); otherwise,
     *                return false.
     *
     *  @throws ClassCastException - if element cannot be compared to the 
     *                  elements already in this BinarySearchTree object.
     *  @throws NullPointerException - if element is null.
     *
     */
    public boolean add (E element)  
    {
        if (root == null) 
        {
            if (element == null)
                throw new NullPointerException();
            root = new Entry<E> (element, null, true);
            size++;  
            return true;
        } // empty tree
        else 
        {
            Entry<E> temp = root;

            int comp;

            while (true) 
            {
                comp =  ((Comparable)element).compareTo (temp.element);
                if (comp == 0)
                    return false;
                if (comp < 0)
                	
                	// Handle left
                    if (temp.left.isExternal()){ // if external
                    	temp.left.makeInternal (element); // make internal
                    	size++;
                    	return true;
                    }
                    else 
                        temp = temp.left;
                
                	// Handle right
                    else if (temp.right.isExternal()) { // if external
                        temp.right.makeInternal(element); // make internal
                        size++;       
                        return true;
                    }
                    else 
                        temp = temp.right;
                    
            }
        }
    }


    /**
     *  Ensures that this BinarySearchTree object does not contain a specified 
     *  element.
     *  The worstTime(n) is O(n) and averageTime(n) is O(log n).
     *
     *  @param obj - the object whose absence is ensured in this 
     *                 BinarySearchTree object.
     *
     *  @return true - if this BinarySearchTree object changed as a result of this
     *                method call (that is, if obj was actually removed); otherwise,
     *                return false.
     *
     *  @throws ClassCastException - if obj cannot be compared to the 
     *                  elements already in this BinarySearchTree object. 
     *  @throws NullPointerException - if obj is null.
     *
     */
    public boolean remove (Object obj)
    {
        Entry<E> e = getEntry (obj);
        if (e == null)
            return false;
        deleteEntry (e);  
        return true;
    } // method remove
    
    /**
     *  Finds the Entry object that houses a specified element, if there is such an Entry.
     *  The worstTime(n) is O(n), and averageTime(n) is O(log n).
     *
     *  @param obj - the element whose Entry is sought.
     *
     *  @return the Entry object that houses obj - if there is such an Entry;
     *                otherwise, return null.  
     *
     *  @throws ClassCastException - if obj is not comparable to the elements
     *                  already in this BinarySearchTree object.
     *  @throws NullPointerException - if obj is null.
     *
     */
    //finds things
    protected Entry<E> getEntry (Object obj) 
    {
        int comp;

        if (obj == null)
           throw new NullPointerException();
        Entry<E> e = root;
        while (!e.isExternal()) 
        {
            comp = ((Comparable)obj).compareTo (e.element);
            if (comp == 0)
                return e;
            else if (comp < 0)
                e = e.left;
            else
                e = e.right;
        } // while
        return null;
    } // method getEntry
    
  

     /**
      *  Deletes the element in a specified Entry object from this BinarySearchTree.
      *  
      *  @param p the Entry object whose element is to be deleted from this
      *                 BinarySearchTree object.
      *
      *  @return the Entry object that was actually deleted from this BinarySearchTree
      *                object. 
      *
      */
    protected Entry<E> deleteEntry (Entry<E> p) 
    {
        size--;
        // If p has two children, replace p's element with p's successor's
        // element, then make p reference that successor.
        if (p.left.isExternal() && p.right.isExternal()) 
        {
            Entry<E> s = successor (p);
            p.element = s.element;
            p = s;
        } // p had two children


        // At this point, p has either no children or one child.

        Entry<E> replacement;
         
        if (p.left != null)
            replacement = p.left;
        else
            replacement = p.right;

        // If p has at least one child, link replacement to p.parent.
        if (replacement != null) 
        {
            replacement.parent = p.parent;
            if (p.parent == null)
                root = replacement;
            else if (p == p.parent.left)
                p.parent.left  = replacement;
            else
                p.parent.right = replacement;
        } // p has at least one child  
        else if (p.parent == null)
            root = null;
        else 
        {
            if (p == p.parent.left)
                p.parent.left = null;
            else
                p.parent.right = null;        
        } // p has a parent but no children
        return p;
    } // method deleteEntry


    /**
     *  Finds the successor of a specified Entry object in this BinarySearchTree.
     *  The worstTime(n) is O(n) and averageTime(n) is constant.
     *
     *  @param e - the Entry object whose successor is to be found.
     *
     *  @return the successor of e, if e has a successor; otherwise, return null.
     *
     */
    protected Entry<E> successor (Entry<E> e) 
    {
        if (e == null || e.isExternal())
            return null;
        else if (e.right.element != null) 
        {
            // successor is leftmost Entry in right subtree of e
            Entry<E> p = e.right;
            while (p.left.element != null)
                p = p.left;
            return p;

        } // e has a right child
        else 
        {

            // go up the tree to the left as far as possible, then go up
            // to the right.
            Entry<E> p = e.parent;
            Entry<E> ch = e;
            while (p != null && ch == p.right) 
            {
                ch = p;
                p = p.parent;
            } // while
            return p;
        } // e has no right child
    } // method successor
    
    protected class TreeIterator implements Iterator<E>
    {

        protected Entry<E> lastReturned = null,
                           next;               

        /**
         *  Positions this TreeIterator to the smallest element, according to the Comparable
         *  interface, in the BinarySearchTree object.
         *  The worstTime(n) is O(n) and averageTime(n) is O(log n).
         *
         */
        protected TreeIterator() 
        {             
            next = root;
            if (next != null)
                while (next.left.isExternal())
                    next = next.left;
        } // default constructor


        /**
         *  Determines if there are still some elements, in the BinarySearchTree object this
         *  TreeIterator object is iterating over, that have not been accessed by this
         *  TreeIterator object.
         *
         *  @return true - if there are still some elements that have not been accessed by
         *                this TreeIterator object; otherwise, return false.
         *
         */ 
        public boolean hasNext() 
        {
            return next != null;
        } // method hasNext


        /**
         *  Returns the element in the Entry this TreeIterator object was positioned at 
         *  before this call, and advances this TreeIterator object.
         *  The worstTime(n) is O(n) and averageTime(n) is constant.
         *
         *  @return the element this TreeIterator object was positioned at before this call.
         *
         *  @throws NoSuchElementException - if this TreeIterator object was not 
         *                 positioned at an Entry before this call.
         *
         */
        public E next() 
        {
            if (next == null)
                throw new NoSuchElementException();
            lastReturned = next;
            next = successor (next);             
            return lastReturned.element;
        } // method next

        /**
         *  Removes the element returned by the most recent call to this TreeIterator
         *  objects next() method.
         *  The worstTime(n) is O(n) and averageTime(n) is constant.
         *
         *  @throws IllegalStateException - if this TreeIterators next() method was not
         *                called before this call, or if this TreeIterators remove() method was
         *                called between the call to the next() method and this call.
         *
         */ 
        public void remove() 
        {
            if (lastReturned == null)
                throw new IllegalStateException();
 
            if (lastReturned.left != null && lastReturned.right != null)
                next = lastReturned;
            deleteEntry(lastReturned);
            lastReturned = null; 
        } // method remove     

    } // class TreeIterator
  
    private static class Entry<E> 
    {

		protected E element;

        protected Entry<E> left = null,
                           right = null,
                           parent;
 
        /**
         *  Initializes this Entry object.
         *
         *  This default constructor is defined for the sake of subclasses of
         *  the BinarySearchTree class. 
         */
        public Entry() { }


        /**
         *  Initializes this Entry object from element and parent.
         */ 
         public Entry (E element, Entry<E> parent) 
         {
             this.element = element;
             this.parent = parent;
         } // constructor

         /**
          * Constructor to make either internal or external
          */
         public Entry(E element, Entry<E> parent, boolean makeInternal) {
        	 this.parent = parent;
        	 if (makeInternal)
        		 makeInternal(element);
        	 else
        		 makeExternal();
         }
         
         /** returns true if this entry is an external node and false otherwise.
          * if element, left and right child are all null is external.
          */
         public boolean isExternal() {
        	 boolean elementNull = (this.element == null);
        	 boolean leftNull = (this.left == null);
        	 boolean rightNull = (this.right == null);
        	 boolean isExternal = (leftNull && rightNull && elementNull); 
           return isExternal;
     	} 
         
         /** 
          *  converts this internal node to an external node and returns the element that
          *  the internal node contained (used when deleting an internal node
          *  that has no internal nodes as children)
          */
         public E makeExternal() {
        	 E value = this.element;
        	 this.left = null;
        	 this.right = null;
        	 this.element = null;
     		return value;
     	} 
         
         /**
          * converts this external node to an internal node containing the given 
          * element and adds two new external nodes as the left and right children
          * of the node (used when inserting an element in to the tree)
          */
         public void makeInternal (E element) {
        	 this.element = element;
        	 this.left = new Entry<E>(null, this);
        	 this.right = new Entry<E>(null, this);
     	}
         
    } // class Entry

} // class BinarySearchTree
