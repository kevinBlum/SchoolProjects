/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Airline Reservation lab
 * We sat together and wrote out all of the code together
 */
public class BallsSilver extends Decoration {
	Tree tree;

	public BallsSilver(Tree tree) {
		this.tree = tree;
	}

	public String getDescription() {

		return tree.getDescription() + " Silver Balls";
	}

	public double cost() {

		return 3 + tree.cost();
	}
}
