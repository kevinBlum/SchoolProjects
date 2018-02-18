package simpleblackjack;

import java.util.ArrayList;

public class Deck {
	
	ArrayList<String> deck = new ArrayList<String>();
	
	public void makePlayDeck(Deck playDeck){
		playDeck.deck.add("2");
		playDeck.deck.add("2");
		playDeck.deck.add("3");
		playDeck.deck.add("4");
		playDeck.deck.add("5");
		playDeck.deck.add("6");
		playDeck.deck.add("7");
		playDeck.deck.add("8");
		playDeck.deck.add("9");
		playDeck.deck.add("10");
		playDeck.deck.add("J");
		playDeck.deck.add("Q");
		playDeck.deck.add("K");
		playDeck.deck.add("A");
		
		//return playDeck;
		
	}
	
	public void addToPlayer(Deck playDeck, Deck gameDeck){
		
		gameDeck.deck.add(playDeck.deck.get((playDeck.deck.size()-1)));
		playDeck.deck.remove((playDeck.deck.size()-1));
		
	}
	

}
