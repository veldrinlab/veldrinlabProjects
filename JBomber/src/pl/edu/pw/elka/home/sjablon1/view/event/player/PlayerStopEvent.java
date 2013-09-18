package pl.edu.pw.elka.home.sjablon1.view.event.player;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents one of Player Event in Game - PlayerMoveStop Event, witch is fired
 * when user controls Player Bomberman is stopped. Every Events in JBomber extends GameEvent 
 * class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PlayerStopEvent extends GameEvent
{
	/**
	 * Default constructor of PlayerMoveStopEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public PlayerStopEvent(Object source)
	{
		super(source);
    }

}