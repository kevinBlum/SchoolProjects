/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Airline Reservation lab
 * We sat together and wrote out all of the code together
 */
public class Ruffles extends Decoration {
	Tree tree;

	public Ruffles(Tree tree) {
		this.tree = tree;
	}

	public String getDescription() {
		// TODO Auto-generated method stub
		return tree.getDescription() + " Ruffles";
	}

	public double cost() {
		// TODO Auto-generated method stub
		return 1 + tree.cost();
	}

}
