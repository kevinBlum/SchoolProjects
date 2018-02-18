/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Observer Design pattern
 * We sat together and wrote out all of the code together
 */
public class LowBid implements BiddingStrat {

	public int bid(int curBid) {
		if (curBid < 30)
			curBid++;
		return curBid;
	}
}
