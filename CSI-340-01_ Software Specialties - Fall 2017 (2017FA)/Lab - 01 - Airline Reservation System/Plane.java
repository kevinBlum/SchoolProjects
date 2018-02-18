
public class Plane {
	private int numberOfVipSeats = 30;
	private int numberOfRegularSeats = 100;
	private int vipPrice = 900;
	private int regularPrice = 100;
	private Company companyInfo;
	
	
	
	public Company getCompanyInfo() {
		return companyInfo;
	}
	public void setCompanyInfo(Company companyInfo) {
		this.companyInfo = companyInfo;
	}
	public int getNumberOfVipSeats() {
		return numberOfVipSeats;
	}
	public void setNumberOfVipSeats(int numberOfVipSeats) {
		this.numberOfVipSeats = numberOfVipSeats;
	}
	public int getNumberOfRegularSeats() {
		return numberOfRegularSeats;
	}
	public void setNumberOfRegularSeats(int numberOfRegularSeats) {
		this.numberOfRegularSeats = numberOfRegularSeats;
	}
	public int getVipPrice() {
		return vipPrice;
	}
	public void setVipPrice(int vipPrice) {
		this.vipPrice = vipPrice;
	}
	public int getRegularPrice() {
		return regularPrice;
	}
	public void setRegularPrice(int regularPrice) {
		this.regularPrice = regularPrice;
	}
	

	
}
