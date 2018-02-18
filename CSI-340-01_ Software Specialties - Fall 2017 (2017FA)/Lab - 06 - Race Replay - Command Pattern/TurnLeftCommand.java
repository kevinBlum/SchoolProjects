//Written by Kevin Blum
public class TurnLeftCommand implements Command {

	SteeringWheel wheel;
	 
	public TurnLeftCommand(SteeringWheel wheel) {
		this.wheel = wheel;
	}
 
	public void execute() {
		wheel.left();
	}
}
