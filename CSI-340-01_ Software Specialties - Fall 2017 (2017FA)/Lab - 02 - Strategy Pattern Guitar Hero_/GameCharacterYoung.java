/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Lab Strategy Design pattern
 * We sat together and wrote out all of the code together
 */
public class GameCharacterYoung extends GameCharacter {

	public GameCharacterYoung() {
		guitar = new FenderTelecaster();
		solo = new GuitarOnFire();
	}
	
	public void display() {
		System.out.println("You are Angus Young!");

	}

}
