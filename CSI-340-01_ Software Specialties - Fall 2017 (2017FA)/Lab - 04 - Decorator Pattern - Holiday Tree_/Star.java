/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Airline Reservation lab
 * We sat together and wrote out all of the code together
 */
public class Star extends Decoration {
	Tree tree;

	public Star(Tree tree) {

		this.tree = tree;
	}

	@Override
	public String getDescription() {
		if (tree.getDescription().contains("Star")) {
			return "Tree Already has a star \n" + tree.getDescription();
		} else
			return tree.getDescription() + " Star";
	}

	@Override
	public double cost() {
		if (tree.getDescription().contains("Star")) {
			return tree.cost();
		} else
			return 4 + tree.cost();
	}

}
