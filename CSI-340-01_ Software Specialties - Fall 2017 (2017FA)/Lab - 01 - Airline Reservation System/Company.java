import java.util.ArrayList;

public class Company {
	public String name;
	private int numberOfPlanes;
	ArrayList<Plane> planesOwned = new ArrayList<>();
	
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getNumberOfPlanes() {
		return numberOfPlanes;
	}
	public void setNumberOfPlanes(int numberOfPlanes) {
		this.numberOfPlanes = numberOfPlanes;
	}
	public ArrayList<Plane> getPlanesOwned() {
		return planesOwned;
	}
	public void setPlanesOwned(ArrayList<Plane> planesOwned) {
		this.planesOwned = planesOwned;
	}
	
	
}
