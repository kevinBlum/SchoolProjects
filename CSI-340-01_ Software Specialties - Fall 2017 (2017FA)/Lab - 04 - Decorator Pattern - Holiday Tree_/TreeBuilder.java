/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Airline Reservation lab
 * We sat together and wrote out all of the code together
 */
public class TreeBuilder {
	public static void main(String args[]) {
		Tree myTree = new DouglasFir();
		System.out.println(myTree.getDescription() + " $ " + myTree.cost());

		Tree tree2 = new FraserFir();
		tree2 = new Ribbon(tree2);
		tree2 = new Star(tree2);
		tree2 = new Star(tree2);
		tree2 = new LEDs(tree2);
		System.out.println(tree2.getDescription() + " $ " + tree2.cost());
	}
}
