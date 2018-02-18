//Written by Kevin Blum

public class DairyQueen extends IceCreamShop {

	@Override
	public IceCream getIceCream(String type) {
		if (type.equals("Chocolate"))
			return new Chocolate();
		else if (type.equals("Strawberry"))
			return new Strawberry();
		else if (type.equals("Vanilla"))
			return new Vanilla();
		else
			return null;
	}
	
	

}
