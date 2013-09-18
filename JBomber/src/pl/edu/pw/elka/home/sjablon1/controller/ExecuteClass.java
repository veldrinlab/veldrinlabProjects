package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.concurrent.ArrayBlockingQueue;

import pl.edu.pw.elka.home.sjablon1.model.Model;
import pl.edu.pw.elka.home.sjablon1.view.View;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents abstract defines parent class of all Execute Classes.
 * @author Szymon Jablonski
 * @version 1.0
 */
abstract public class ExecuteClass implements Visitable
{

	@Override
	/**
	 * This is the entry point which enables an object to be visited the visitor object. 
	 */
	public void accept(Visitor visitor, Model model, View view,
			ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		
	}

}
