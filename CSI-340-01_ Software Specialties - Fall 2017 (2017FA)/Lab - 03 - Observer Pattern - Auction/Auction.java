/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Observer Design pattern
 * We sat together and wrote out all of the code together
 */
import java.util.Vector;

public interface Auction {
	Observer observer = new Observer();
	 
	public void notifyBidders();
}
