/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Airline Reservation lab
 * We sat together and wrote out all of the code together
 */
public class BallsRed extends Decoration {
	Tree tree;

	public BallsRed(Tree tree) {
		this.tree = tree;
	}

	@Override
	public String getDescription() {

		return tree.getDescription() + " Red Balls";
	}

	@Override
	public double cost() {

		return 1;
	}

}
