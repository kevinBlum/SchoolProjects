
/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Observer Design pattern
 * We sat together and wrote out all of the code together
 */
import java.util.Vector;

public class Observer {
	public Vector<Bidder> bidders = new Vector<Bidder>();

	public void update(int curPrice) {
		for (int i = 0; i < bidders.size(); i++) {
			bidders.get(i).currentPrice = curPrice;
		}

	}
}
