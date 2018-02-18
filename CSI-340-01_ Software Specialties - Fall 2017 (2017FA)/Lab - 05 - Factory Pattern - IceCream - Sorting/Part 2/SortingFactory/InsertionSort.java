//Written by Kevin Blum

public class InsertionSort implements SortingAlgorithm {

	public void sort(Object[] items) {
		int j;
		for (int p = 1; p < items.length; p++) {

			Object temp = items[p];

			for (j = p; j > 0 && ((Comparable) items[j - 1]).compareTo(temp) > 0; j--)
				items[j] = items[j - 1];

			items[j] = temp;
		}
	}

}
