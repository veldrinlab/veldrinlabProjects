package pl.edu.pw.elka.home.sjablon1.view.event.player;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents one of Player Event in Game - PlayerMoveRight Event, witch is fired
 * when user controls Player Bomberman to move Right. Every Events in JBomber extends GameEvent 
 * class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PlayerMoveRightEvent extends GameEvent
{
	/**
	 * Default constructor of PlayerMoveRightEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public PlayerMoveRightEvent(Object source)
	{
		super(source);
    }
}
