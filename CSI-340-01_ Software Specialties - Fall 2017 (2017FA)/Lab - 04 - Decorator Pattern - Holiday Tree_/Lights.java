/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Airline Reservation lab
 * We sat together and wrote out all of the code together
 */
public class Lights extends Decoration {
	Tree tree;

	public Lights(Tree tree) {
		this.tree = tree;
	}

	public String getDescription() {

		return tree.description + " Lights";
	}

	public double cost() {

		return 5 + tree.cost();
	}
}
