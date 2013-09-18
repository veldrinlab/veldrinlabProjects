package pl.edu.pw.elka.home.sjablon1.view.event;

/**
 * Class represents one of Bomb Event in Game - BombBlowUp Event, which is fired
 * when Bomb change state to Blow. Every Events in JBomber extends GameEvent 
 * class and known is's name for identification.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class BombBlowUpEvent extends GameEvent
{
	/**
	 * Default constructor of BombBlowUpEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public BombBlowUpEvent(Object source)
	{
		super(source);
    }

}