//Written by Kevin Blum

public class LetsEat {

	public static void main(String[] args) {
		
		IceCreamShop DQueen = new DairyQueen();
		IceCream cone;
		
		cone = DQueen.orderCone("Chocolate");
		System.out.println("Enoying some " + cone.getDescription()
							+ " which costs " + cone.cost());
		
		IceCream cone2;
		cone2 = DQueen.orderCone("Strawberry");
		System.out.println("Enoying some " + cone2.getDescription()
							+ " which costs " + cone2.cost());

	}

}
