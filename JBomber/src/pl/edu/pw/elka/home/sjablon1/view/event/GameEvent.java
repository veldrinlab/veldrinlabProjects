package pl.edu.pw.elka.home.sjablon1.view.event;

import java.util.EventObject;

/**
 * Class represents JBomber Game Event superclass. All events of Game must extends GameEvent
 * which extends EventObject class.
 * @author Szymon Jablosnki
 * @version 1.0
 */
public class GameEvent extends EventObject
{
	
	/**
	 * Default constructor of GameEvent
	 * 
	 * @param source is object witch has generated event.
	 */
	public GameEvent(Object source)
	{
		super(source);
    }
		
}
