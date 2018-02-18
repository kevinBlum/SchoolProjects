/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Observer Design pattern
 * We sat together and wrote out all of the code together
 */
public class Bidder extends Observer {
	
	String name;
	int currentPrice;
	BiddingStrat bidStrategy;
	
	public int bid(){
		
		currentPrice = bidStrategy.bid(currentPrice);
		return currentPrice;
	}
	
	public void setBiddingStrat(BiddingStrat newBidStrat){
		bidStrategy = newBidStrat;
	}
}
