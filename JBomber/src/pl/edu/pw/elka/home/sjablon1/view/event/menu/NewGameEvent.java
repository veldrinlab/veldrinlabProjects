package pl.edu.pw.elka.home.sjablon1.view.event.menu;


import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;

/**
 * Class represents one of basic Event in Game - NewGameEvent which execute creation
 * of new game instance. Every Events in JBomber extends GameEvent class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class NewGameEvent extends GameEvent
{
	/**
	 * Default constructor of NewGameEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public NewGameEvent(Object source)
	{
		super(source);
    }
}
