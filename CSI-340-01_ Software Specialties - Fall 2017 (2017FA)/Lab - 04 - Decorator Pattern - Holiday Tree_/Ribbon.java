/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Airline Reservation lab
 * We sat together and wrote out all of the code together
 */
public class Ribbon extends Decoration {
	Tree tree;

	public Ribbon(Tree tree) {
		this.tree = tree;
	}

	public String getDescription() {

		return tree.getDescription() + " Ribbon";
	}

	public double cost() {

		return 2 + tree.cost();
	}
}
