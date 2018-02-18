/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Observer Design pattern
 * We sat together and wrote out all of the code together
 */
public class PlusTenBid implements BiddingStrat {

	@Override
	public int bid(int curBid) {
		curBid += 10;
		return curBid;
	}

}
