/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Lab Strategy Design pattern
 * We sat together and wrote out all of the code together
 */
public class GuitarHero {

	public static void main(String[] args) {
		GameCharacter player1 = new GameCharacterSlash();
		GameCharacter player2 = new GameCharacterHendrix();
		player1.display();
		player1.playGuitar();
		player1.playSolo();
		System.out.println("\n");
		player2.display();
		player2.playGuitar();
		player2.playSolo();
		System.out.println("\n");
		player1.display();
		player1.setGuitar(new FenderTelecaster());
		player1.setSolo(new JumpOffStage());
		player1.playGuitar();
		player1.playSolo();
	}

}
