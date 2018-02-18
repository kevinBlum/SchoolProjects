//Written by Kevin Blum

import java.util.ArrayList;

public class CarController {

	Command car;
	ArrayList<Command> replayCommands = new ArrayList<Command>();
	 
	public CarController() {}
 
	public void executeCommand(Command command) {
		car = command;
		car.execute();
		replayCommands.add(command);
	}
	
	public void replayGame() {
		for(int i = 0; i < replayCommands.size(); i++) {
			car = replayCommands.get(i);
			car.execute();
		}
	}
 
}
