//Written by Kevin Blum
public class BrakePedalCommand implements Command {

	Pedal pedal;
	 
	public BrakePedalCommand(Pedal pedal) {
		this.pedal = pedal;
	}
 
	public void execute() {
		pedal.slower();
	}
	
}
