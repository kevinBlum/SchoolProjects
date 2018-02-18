//Written by Kevin Blum
public class GasPedalCommand implements Command {

	Pedal pedal;
	 
	public GasPedalCommand(Pedal pedal) {
		this.pedal = pedal;
	}
 
	public void execute() {
		pedal.faster();
	}
	
}
