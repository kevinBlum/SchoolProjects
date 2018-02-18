
public class Flight {
	private String flightNumber;
	private String departureLocation;
	private String destination;
	private String date;
	private String departureTime;
	private int durationInMinutes;
	private Plane assignedPlane;
	private String seatNumber;
	
	public String getSeatNumber() {
		return seatNumber;
	}




	public void setSeatNumber(String seatNumber) {
		this.seatNumber = seatNumber;
	}




	public String getFlightNumber() {
		return flightNumber;
	}




	public void setFlightNumber(String flightNumber) {
		this.flightNumber = flightNumber;
	}
	
	public String getDepartureLocation() {
		return departureLocation;
	}




	public void setDepartureLocation(String departureLocation) {
		this.departureLocation = departureLocation;
	}




	public String getDestination() {
		return destination;
	}




	public void setDestination(String destination) {
		this.destination = destination;
	}




	public String getDate() {
		return date;
	}




	public void setDate(String date) {
		this.date = date;
	}




	public String getDepartureTime() {
		return departureTime;
	}




	public void setDepartureTime(String departureTime) {
		this.departureTime = departureTime;
	}




	public int getDurationInMinutes() {
		return durationInMinutes;
	}




	public void setDurationInMinutes(int durationInMinutes) {
		this.durationInMinutes = durationInMinutes;
	}




	public Plane getAssignedPlane() {
		return assignedPlane;
	}




	public void setAssignedPlane(Plane assignedPlane) {
		this.assignedPlane = assignedPlane;
	}




	public int getCapacity(Plane assignedPlane) {
		
		return assignedPlane.getNumberOfRegularSeats() + assignedPlane.getNumberOfVipSeats();
	}
	
}
