//Written by Kevin Blum
public class TestSorter {

	public static void main(String[] args) {
		//Main Test method for sorting factories of Insertion and Selection Sort
		String[] elements = { "beta", "chi", "alpha", "zeta", "nu", "mu" };
		SortFactory factory = new NonRecursive();
		factory.setFactory("Selection");

		SortingAlgorithm algorithm = factory.getAlgorithm();

		algorithm.sort(elements);

		for (int i = 0; i < elements.length; i++)
			System.out.println(elements[i]);
		
		System.out.println("\n\n");
		
		String[] elements2 = { "beta", "chi", "alpha", "zeta", "nu", "mu" };
		SortFactory factory2 = new NonRecursive();
		factory2.setFactory("Insertion");

		SortingAlgorithm algorithm2 = factory2.getAlgorithm();

		algorithm2.sort(elements2);

		for (int i = 0; i < elements2.length; i++)
			System.out.println(elements2[i]);
	}
}
