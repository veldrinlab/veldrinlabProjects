package pl.edu.pw.elka.home.sjablon1.view.event.menu;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;

/**
 * Class represents one of basic Event in Game - CreditsEventt witch enter CreditsView
 * object. Every Events in JBomber extends GameEvent class and known is's name for 
 * identification.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class CreditsEvent extends GameEvent
{
	/**
	 * Default constructor of CreditsEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public CreditsEvent(Object source)
	{
		super(source);
    }
}