package pl.edu.pw.elka.home.sjablon1.view.event.player;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents one of Player Event in Game - PlayerMoveLeft Event, witch is fired
 * when user controls Player Bomberman to move Left. Every Events in JBomber extends GameEvent 
 * class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PlayerMoveLeftEvent extends GameEvent
{
	/**
	 * Default constructor of PlayerMoveLeftEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public PlayerMoveLeftEvent(Object source)
	{
		super(source);
    }

}
