/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Airline Reservation lab
 * We sat together and wrote out all of the code together
 */
public class LEDs extends Decoration {
	Tree tree;

	public LEDs(Tree tree) {
		this.tree = tree;
	}

	public String getDescription() {

		return tree.getDescription() + " LEDs";
	}

	public double cost() {

		return 10 + tree.cost();
	}
}
