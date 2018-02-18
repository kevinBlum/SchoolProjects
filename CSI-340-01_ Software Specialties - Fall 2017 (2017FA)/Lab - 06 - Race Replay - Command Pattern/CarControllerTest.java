//Written by Kevin Blum
public class CarControllerTest {

	public static void main(String[] args) {

		CarController car = new CarController();
		
		SteeringWheel wheel = new SteeringWheel();
		TurnRightCommand turnRight = new TurnRightCommand(wheel);
		TurnLeftCommand turnLeft = new TurnLeftCommand(wheel);
		
		Pedal pedal = new Pedal();
		GasPedalCommand goFaster = new GasPedalCommand(pedal);
		BrakePedalCommand goSlower = new BrakePedalCommand(pedal);

		car.executeCommand(turnRight);
		car.executeCommand(turnLeft);
		car.executeCommand(goFaster);
		car.executeCommand(goSlower);
		
		System.out.println("\n");
		
		car.replayGame();
	}

}
