package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.concurrent.ArrayBlockingQueue;

import pl.edu.pw.elka.home.sjablon1.model.Model;
import pl.edu.pw.elka.home.sjablon1.view.View;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents Exit event execute visitable class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExecuteExitGame extends ExecuteClass
{
	/**
	 * This is the entry point which enables an object to be visited the visitor object. 
	 */
	public void accept(Visitor v,Model model, View view, ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		v.visit( this );
	}
	
	/**
	 * Method used to execute exit game event.
	 */
	public void executeExit()
	{
		System.out.println("Thank you for playing:D!");
		System.exit(0);
	}

}
