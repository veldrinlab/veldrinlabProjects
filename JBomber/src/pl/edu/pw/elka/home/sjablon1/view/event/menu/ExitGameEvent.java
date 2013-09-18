package pl.edu.pw.elka.home.sjablon1.view.event.menu;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;

/**
 * Class represents one of basic Event in Game - ExitGameEvent which exit application.
 * Every Events in JBomber extends GameEvent class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExitGameEvent extends GameEvent
{
	/**
	 * Default constructor of ExitGameEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public ExitGameEvent(Object source)
	{
		super(source);
    }
	
}
