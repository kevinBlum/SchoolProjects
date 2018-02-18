package simpleblackjack;

public class GameFunctions {

	public void printStatus(Deck playerCards, Deck dealerCards) {
		
		System.out.println("\nPlayer's total is " + calculateScore(playerCards) + ":");
		for(int i = 0; i<playerCards.deck.size(); i++){
			System.out.print(playerCards.deck.get(i) + "\n");
		}
		
		System.out.println("\nDealer's total is " + calculateScore(dealerCards) + ":");
		for(int i = 0; i<dealerCards.deck.size(); i++){
			System.out.print(dealerCards.deck.get(i) + "\n");
		}
		
	}
	
	public int calculateScore(Deck cards){
		
		int score = 0;
		boolean hasAce = false;
		
		for (int i=0; i<cards.deck.size(); i++){
			try {
				int cardValue = Integer.parseInt(cards.deck.get(i));
				score += cardValue;
			} catch (Exception e){
				if (cards.deck.get(i) == "A"){
					hasAce = true;
				} else {
					score += 10;
				}
			}
		}
		
		if (hasAce) {
			if ((score + 11) > 21) {
				score += 1;
			} else {
				score += 11;
			}
		}
		
		return score;
	}
	
}
