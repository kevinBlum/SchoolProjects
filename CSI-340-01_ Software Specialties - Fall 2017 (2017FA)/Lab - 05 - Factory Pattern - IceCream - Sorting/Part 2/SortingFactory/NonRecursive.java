//Written by Kevin Blum

public class NonRecursive extends SortFactory{

	@Override
	public SortingAlgorithm getAlgorithm() {
		if (this.algorithm.equals("Selection"))
			return new SelectionSort();
		else if (this.algorithm.equals("Insertion"))
			return new InsertionSort();
		else
			return null;
	}

}
