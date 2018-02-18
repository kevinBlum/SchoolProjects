/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Lab Strategy Design pattern
 * We sat together and wrote out all of the code together
 */
public class GameCharacterSlash extends GameCharacter {
	public GameCharacterSlash() {
		guitar = new GibsonSG();
		solo = new SmashGuitar();
	}
	
	public void display() {
		System.out.println("You are Slash!");

	}

}
