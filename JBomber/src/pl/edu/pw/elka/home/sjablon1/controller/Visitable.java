package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.concurrent.ArrayBlockingQueue;

import pl.edu.pw.elka.home.sjablon1.model.Model;
import pl.edu.pw.elka.home.sjablon1.view.View;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents abstract interface which declares the accept operation. 
 * This is the entry point which enables an object to be "visited" by the visitor object. 
 * Each object from a collection should implement this abstraction in order to be able to be visited. 
 * @author Szymon Jablonski
 * @version 1.0
 */
public interface Visitable
{
	/**
	 * Method is used to visit class by Visitor.
	 * 
	 * @param visitor is Visitor object
	 * @param model is Game Model
	 * @param view is Game View
	 * @param blockingEventQueue is...
	 */
	public void accept(Visitor visitor,Model model, View view, ArrayBlockingQueue<GameEvent> blockingEventQueue);
	
}
