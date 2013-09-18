package pl.edu.pw.elka.home.sjablon1.view.event.menu;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;

/**
 * Class represents one of basic Event in Game - BackToMenuEvent which enter BackToMenuView
 * object. Every Events in JBomber extends GameEvent class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class BackToMenuEvent extends GameEvent
{
	/**
	 * Default constructor of BacktToMenuEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public BackToMenuEvent(Object source)
	{
		super(source);
    }

}