public class ArrayUtility{
	public static void display(Comparable[] values){
		/* can be used to output array contents where the component object has a toString method
		 * will output every slot in the array including empty slots which will be output as null
		 */
		for (Comparable value:values)
			System.out.print(value+"  ");
		System.out.println();
	}
	 
	public static int getNumberOfElements(Object[] objects){
		int index=0;
		while (index<objects.length && objects[index]!=null)
			index++;
		return index;
	}
}

