package pl.edu.pw.elka.home.sjablon1.view.event.menu;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;

/**
 * Class represents one of basic Event in Game - OptionsEvent which enter OptionsView
 * object. Every Events in JBomber extends GameEvent class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class OptionsEvent extends GameEvent
{
	/**
	 * Default constructor of OptionsEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public OptionsEvent(Object source)
	{
		super(source);
    }
	
}