
/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Observer Design pattern
 * We sat together and wrote out all of the code together
 */
import java.util.Vector;

public class Auctioneer implements Auction {
	Item auctionItem = new Item();
	Bidder highestBidder;
	int curPrice;

	public void notifyBidders() {
		observer.update(curPrice);
		System.out.println("Notifying all bidders of Price increase to: " + curPrice);
	}

	public void addBidders(Bidder newBidder) {
		observer.bidders.addElement(newBidder);
	}

}
