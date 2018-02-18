//Written by Kevin Blum
public class TurnRightCommand implements Command {
	
	SteeringWheel wheel;
	 
	public TurnRightCommand(SteeringWheel wheel) {
		this.wheel = wheel;
	}
 
	public void execute() {
		wheel.right();
	}
}
