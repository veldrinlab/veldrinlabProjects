package pl.edu.pw.elka.home.sjablon1.view.event;

/**
 * Class represents one of Bomb Event in Game - BombChangeState Event, which is fired
 * when Bomb change state. Every Events in JBomber extends GameEvent 
 * class and known is's name for identification.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class BombChangeStateEvent extends GameEvent
{
	/**
	 * Default constructor of BombChangeStateEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public BombChangeStateEvent(Object source)
	{
		super(source);
    }

}
