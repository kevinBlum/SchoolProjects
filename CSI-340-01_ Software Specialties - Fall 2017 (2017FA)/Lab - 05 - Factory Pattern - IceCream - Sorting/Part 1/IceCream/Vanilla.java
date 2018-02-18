// a concrete instance of an ice cream
public class Vanilla extends IceCream {
	public static final double COST = 1.15;

	public Vanilla() {
		description = "Yummy Vanilla";
	}

	public double cost() {
		return COST;
	}

}
