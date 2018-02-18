/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Airline Reservation lab
 * We sat together and wrote out all of the code together
 */
public class BallsBlue extends Decoration {
	Tree tree;

	public BallsBlue(Tree tree) {
		this.tree = tree;
	}

	public String getDescription() {

		return tree.getDescription() + " Blue Balls";
	}

	public double cost() {

		return 2 + tree.cost();
	}
}
