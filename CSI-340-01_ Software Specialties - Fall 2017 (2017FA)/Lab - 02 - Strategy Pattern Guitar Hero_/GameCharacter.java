/*
 * Written by AJ Sebastian and Kevin Blum
 * albert.sebastian@mymail.champlain.edu & kevin.blum@mymail.champlain.edu
 * Lab Strategy Design pattern
 * We sat together and wrote out all of the code together
 */
public abstract class GameCharacter {
	Solo solo;
	Guitar guitar;

	public GameCharacter() {

	}

	public void setGuitar(Guitar newGuitar) {
		guitar = newGuitar;
	}
	
	public void setSolo(Solo newSolo) {
		solo = newSolo;
	}
	
	abstract void display();
	
	public void playGuitar() {
		guitar.playGuitar();
	}
	
	public void playSolo() {
		solo.playSolo();
	}

}

