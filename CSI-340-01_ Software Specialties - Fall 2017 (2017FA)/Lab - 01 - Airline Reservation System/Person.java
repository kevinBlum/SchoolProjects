import java.util.ArrayList;

public class Person {

	String firstName;
	String lastName;
	public ArrayList<Flight> flightsBooked = new ArrayList<>();
	
	
	public String getFirstName() {
		return firstName;
	}
	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}
	public String getLastName() {
		return lastName;
	}
	public void setLastName(String lastName) {
		this.lastName = lastName;
	}

	public void printItinerary()
	{
		for (int i = 0; i < this.flightsBooked.size(); i++ ) {
		System.out.println("Name: " + this.getFirstName() + " " + this.getLastName() + "\n" + "From: " + this.flightsBooked.get(i).getDepartureLocation() 
				+ "\n" + "To: " + this.flightsBooked.get(i).getDestination() + "\n" + "Date: " + this.flightsBooked.get(i).getDate() + "\n" +
				"Seat Number: " + this.flightsBooked.get(i).getSeatNumber() + "\n" + "Carrier: " 
				+ this.flightsBooked.get(i).getAssignedPlane().getCompanyInfo().getName());
		
		}
		
		}
	
	public static void main(String args[]) {
		
		Plane plane1 = new Plane();
		Company delta = new Company();
		delta.setName("Delta");
		delta.planesOwned.add(plane1);
		plane1.setCompanyInfo(delta);
		Flight flight1 = new Flight();
		flight1.setAssignedPlane(plane1);
		flight1.setDestination("NYC");
		flight1.setDepartureLocation("Burlington");
		flight1.setDepartureTime("6:00 AM");
		flight1.setDurationInMinutes(90);
		flight1.setDate("September 12, 2017");
		flight1.setFlightNumber("12436563");
		flight1.setSeatNumber("10A");
		
		
		
		
		Flight flight2 = new Flight();
		flight2.setAssignedPlane(plane1);
		flight2.setDestination("Atlanta");
		flight2.setDepartureLocation("NYC");
		flight2.setDepartureTime("12:00 PM");
		flight2.setDurationInMinutes(180);
		flight2.setDate("September 12, 2017");
		flight2.setFlightNumber("23423412");
		flight2.setSeatNumber("12A");
		
		Person kevin = new Person();
		kevin.setFirstName("Kevin");
		kevin.setLastName("Blum");
		kevin.flightsBooked.add(flight1);
		kevin.flightsBooked.add(flight2);
		
		kevin.printItinerary();
		
		
		
	}
	
	
	
}

