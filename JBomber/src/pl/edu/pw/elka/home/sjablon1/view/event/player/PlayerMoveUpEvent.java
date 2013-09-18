package pl.edu.pw.elka.home.sjablon1.view.event.player;

import pl.edu.pw.elka.home.sjablon1.view.event.*;


/**
 * Class represents one of Player Event in Game - PlayerMoveUp Event, witch is fired
 * when user controls Player Bomberman to move Up. Every Events in JBomber extends GameEvent
 * class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PlayerMoveUpEvent extends GameEvent
{
	/**
	 * Default constructor of PlayerMoveUpEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public PlayerMoveUpEvent(Object source)
	{
		super(source);
    }

}

