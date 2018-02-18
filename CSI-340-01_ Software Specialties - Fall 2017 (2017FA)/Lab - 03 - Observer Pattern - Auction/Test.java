
/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Observer Design pattern
 * We sat together and wrote out all of the code together
 */
import java.util.Vector;

public class Test {

	public static void main(String[] args) {

		Bidder bidder1 = new Bidder();
		Bidder bidder2 = new Bidder();
		Bidder bidder3 = new Bidder();
		bidder1.name = "bidder 1";
		bidder2.name = "bidder 2";
		bidder3.name = "bidder 3";
		Observer observer = new Observer();
		Auctioneer auctioneer = new Auctioneer();

		auctioneer.curPrice = auctioneer.auctionItem.price;
		auctioneer.addBidders(bidder1);
		auctioneer.addBidders(bidder2);
		auctioneer.addBidders(bidder3);

		auctioneer.notifyBidders();
		bidder1.setBiddingStrat(new LowBid());
		bidder2.setBiddingStrat(new PlusTenBid());
		bidder3.setBiddingStrat(new OtherBid());
		
		//Actual auction. just has the 5 bidders bid in order.
		Vector<Bidder> bidOrder = new Vector<Bidder>();
		bidOrder.addElement(bidder1);
		bidOrder.addElement(bidder2);
		bidOrder.addElement(bidder3);
		bidOrder.addElement(bidder1);
		bidOrder.addElement(bidder2);

		// System.out.println("hit");
		for (int i = 0; i < bidOrder.size(); i++) {
			int newPrice = bidOrder.get(i).bid();

			if (newPrice > auctioneer.curPrice && bidOrder.get(i) != auctioneer.highestBidder) {

				auctioneer.curPrice = newPrice;
				auctioneer.highestBidder = bidOrder.get(i);
				System.out.println(auctioneer.highestBidder.name + " is the highest bidder with a bid of " + newPrice);
				auctioneer.notifyBidders();
			} else {
				System.out.println("Bid not counted!");
			}
		}

		System.out.println(auctioneer.highestBidder.name + " has won the auction with a bid of " + auctioneer.curPrice);

	}

}
