package pl.edu.pw.elka.home.sjablon1.view.event.player;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents one of Player Event in Game - PlayerMoveDown Event, witch is fired
 * when user controls Player Bomberman to move Down. Every Events in JBomber extends GameEvent
 * class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PlayerMoveDownEvent extends GameEvent
{
	/**
	 * Default constructor of PlayerMoveDownEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public PlayerMoveDownEvent(Object source)
	{
		super(source);
    }

}
