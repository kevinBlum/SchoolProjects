/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Lab Strategy Design pattern
 * We sat together and wrote out all of the code together
 */
public class GameCharacterHendrix extends GameCharacter {
	
	public GameCharacterHendrix() {
		guitar = new GibsonFlyingV();
		solo = new JumpOffStage();
	}
	
	public void display() {
		System.out.println("You are Jimi Hendrix!");

	}

}
