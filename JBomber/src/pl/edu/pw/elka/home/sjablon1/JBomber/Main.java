package pl.edu.pw.elka.home.sjablon1.JBomber;

import java.util.concurrent.ArrayBlockingQueue;

import javax.swing.JFrame;

import pl.edu.pw.elka.home.sjablon1.controller.*;
import pl.edu.pw.elka.home.sjablon1.model.*;
import pl.edu.pw.elka.home.sjablon1.view.*;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;

/**
 * Main class of JBomber Game. Initialize Model, View and Controller Unit.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class Main extends JFrame
{	
	/**
	 * Static method that starts application.
	 * 
	 * @param args is arguments of program launch - no use.
	 */
	public static void main(String[] args)
	{	
		ArrayBlockingQueue<GameEvent> blockingEventQueue= new ArrayBlockingQueue<GameEvent>(50);		
		Model model = new Model();
		CollisionDetector collisionDetector = new CollisionDetector(model);
		model.setCollisionDetector(collisionDetector);
		View view = new View(blockingEventQueue);
		Controller controller = new Controller(model,view,blockingEventQueue);
		controller.run();
	}
	
}
