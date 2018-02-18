package simpleblackjack;

import java.util.Collections;
import java.util.Scanner;


public class BlackJack {
	

	public static void main(String[] args) {
		
		Scanner myScanner = new Scanner(System.in);  
		boolean loopBool = true;
		
		Deck playDeck = new Deck();
		playDeck.makePlayDeck(playDeck);
		
		Deck playerCards = new Deck();
		Deck dealerCards = new Deck();
		
		GameFunctions game = new GameFunctions();
		
		Collections.shuffle(playDeck.deck);
		
		
		System.out.println("Dealer Draws first card.");
		dealerCards.addToPlayer(playDeck, dealerCards);
		
		System.out.println("Player receives two cards.");
		playerCards.addToPlayer(playDeck, playerCards);
		playerCards.addToPlayer(playDeck, playerCards);
		
		game.printStatus(playerCards, dealerCards);
		
		while (loopBool) {
			System.out.println("Do you want to (H)it, (S)tay, or (Q)uit\n");
			String selection;
			
			selection = myScanner.next();
			selection = selection.toUpperCase();
			
			switch (selection) {
			  case "H":
				  	playerCards.deck.add(playDeck.deck.get((playDeck.deck.size()-1)));
					playDeck.deck.remove((playDeck.deck.size()-1));
					game.printStatus(playerCards, dealerCards);
					
					if (game.calculateScore(playerCards) > 21) {
						System.out.println("You busted! You lose!\n");
						myScanner.close();
						System.exit(0);
						}
			        break;
			        
			  case "S":
				  	loopBool = false;
			        break;
			  
			  case "Q":
				  	System.exit(0);
			        break;
			        
			  default:
				   	break;
			
			}
			
		}
		
		
		System.out.println("Dealer draws rest of cards.\n");
		
		while (game.calculateScore(dealerCards) < 17) {
			dealerCards.deck.add(playDeck.deck.get((playDeck.deck.size()-1)));
			playDeck.deck.remove((playDeck.deck.size()-1));
		}
		game.printStatus(playerCards, dealerCards);
		
		if (game.calculateScore(dealerCards) > 21) {
			System.out.println("Dealer busts! You win!\n");
		} else if (game.calculateScore(dealerCards) > game.calculateScore(playerCards)) {
			System.out.println("Dealer wins!\n");
		} else if (game.calculateScore(dealerCards) < game.calculateScore(playerCards)) {
			System.out.println("You win!\n");
		} else {
			System.out.println("It's a tie!\n");
		}

		
		
	}

}
