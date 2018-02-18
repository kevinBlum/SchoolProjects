/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Observer Design pattern
 * We sat together and wrote out all of the code together
 */
public class OtherBid implements BiddingStrat {
	int counter = 0;

	@Override
	public int bid(int curBid) {
		counter++;
		if (counter % 2 == 0) {
			curBid += 5;
		}
		return curBid;
	}

}
