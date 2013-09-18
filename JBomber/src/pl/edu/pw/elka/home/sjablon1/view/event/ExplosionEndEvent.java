package pl.edu.pw.elka.home.sjablon1.view.event;

/**
 * Class represents one of Explosion Event in Game - Explosion Event, which is fired
 * when Explosion change state to End. Every Events in JBomber extends GameEvent 
 * class and known is's name for identification.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExplosionEndEvent extends GameEvent
{
	/**
	 * Default constructor of ExplosionEndEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public ExplosionEndEvent(Object source)
	{
		super(source);
    }

}