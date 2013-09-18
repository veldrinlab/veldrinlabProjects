package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Toolkit;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import javax.swing.event.EventListenerList;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerChangeStateEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerChangeStateListener;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerKeyListener;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerMoveDownEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerMoveLeftEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerMoveRightEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerMoveUpEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerPlantBombEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerStopEvent;



/**
 * Class represents main animating object in Game, the Player Animation. Player can move on 
 * GameBoard, plant Bombs, take PowerUps and die after collision with explosion. With each of this
 * action player object generate own Events. User can control Player with keyboard.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PlayerMoveAnimation extends Animation
{	
	/** List of objects listeners*/
	private EventListenerList listenerList;
	/** Blocking queue used to add occurred Events to communicate with Controller Unit */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;
	/** Defines if Player is moving Up, Down, Left or Right */
	private int moveHorizontalValue;
	/** Defines if Player is moving Up, Down, Left or Right */
	private int moveVerticalValue;
	
	/**
	 * Default constructor of PlayerMoveAnimation object.
	 * 
	 * @param playerSpriteScheetFileName name of file contains animation SpriteSheet
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 */
	public PlayerMoveAnimation(final String playerSpriteScheetFileName,ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
        this.setBackground(Color.WHITE);
        this.setDoubleBuffered(true);
        this.setSize(680, 520);
        this.setOpaque(false);
        
		this.setAnimatingSprite(new Sprite(playerSpriteScheetFileName));
		this.getAnimatingSprite().setSpritePositionX(40);
		this.getAnimatingSprite().setSpritePositionY(0);
		this.setxPosition(40);
		this.setyPosition(40);
		
		this.setBlockingEventQueue(blockingEventQueue);
		this.setListenerList(new EventListenerList());
		this.addPlayerKeyListener(new PlayerKeyListener());
		this.addPlayerChangeStateListener(new PlayerChangeStateListener());
		this.setAnimationRolling(false);

	}
	
	@Override
	/**
	 * Method used to start animation.
	 */
	public void startAnimation()
	{
		this.setAnimationRolling(true);
		this.runAnimation();
		
	}

	@Override
	/**
	 * Method used to stop animation.
	 */
	public void stopAnimation()
	{
		this.setAnimationRolling(false);
		
	}
	
	//@Override
	/**
	 * Method defines what parameters change in each animationCycle. 
	 */
	public void animationCycle()
	{		
		/** Change of animationCycle is defined by occurred events */
		this.firePlayerChangeStateEvent(new PlayerChangeStateEvent(this), blockingEventQueue);
		
		this.setyPosition(this.getyPosition()+ this.getMoveVerticalValue());
		this.setxPosition(this.getxPosition()+ this.getMoveHorizontalValue());
		
		if(this.getMoveVerticalValue()== 8 && this.getMoveHorizontalValue()== 0)
			this.getAnimatingSprite().setSpritePositionY(0);
		else if(this.getMoveVerticalValue()== -8 && this.getMoveHorizontalValue()== 0)
			this.getAnimatingSprite().setSpritePositionY(120);
		else if(this.getMoveVerticalValue()== 0 && this.getMoveHorizontalValue()== 8)
			this.getAnimatingSprite().setSpritePositionY(80);
		else if(this.getMoveVerticalValue()== 0 && this.getMoveHorizontalValue()== -8)
			this.getAnimatingSprite().setSpritePositionY(40);
		
		if(this.getAnimatingSprite().getSpritePositionX() == 40)
			this.getAnimatingSprite().setSpritePositionX(80);
		else if(this.getAnimatingSprite().getSpritePositionX() == 80)
			this.getAnimatingSprite().setSpritePositionX(0);
		else if(this.getAnimatingSprite().getSpritePositionX() == 0)
			this.getAnimatingSprite().setSpritePositionX(40);

		
	}
	
	@Override
	/**
	 * Override method that paints Animation Frame.
	 * 
	 * @param g is Graphics context. 
	 */
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D)g;
        
        Image drawSource = this.getAnimatingSprite().getSpriteSheet();
        int destX1 = this.getxPosition();
        int destY1 = this.getyPosition();
        int destX2 = destX1 + this.getAnimatingSprite().getSpriteWidth();
        int destY2 = destY1 + this.getAnimatingSprite().getSpriteHeight();
        int srcX1 = this.getAnimatingSprite().getSpritePositionX();
        int srcY1 = this.getAnimatingSprite().getSpritePositionY();
        int srcX2 = srcX1 + this.getAnimatingSprite().getSpriteWidth();
        int srcY2 = srcY1 + this.getAnimatingSprite().getSpriteHeight();
        
        g2d.drawImage(drawSource,destX1,destY1,destX2,destY2,srcX1,srcY1,srcX2,srcY2,this);
        Toolkit.getDefaultToolkit().sync();
        g.dispose();
    }
	
	public void runAnimation()
	{
		animationCycle();
		repaint();    
	}
	
	/**
	 * Method that allows classes to register for PlayerKeyListener
	 * 
	 * @param listener is object of listener that will added to ListenerList
	 */
	public void addPlayerKeyListener(final PlayerKeyListener listener)
	{ 
		listenerList.add(PlayerKeyListener.class, listener); 
	}
	
	/**
	 * Method that allows classes to unregister for PlayerKeyListener
	 * 
	 * @param listener is object of listener that will be removed from ListenerList
	 */
	public void removePlayerKeyListener(final PlayerKeyListener listener) 
	{ 
		listenerList.remove(PlayerKeyListener.class, listener); 
	}
	
	/**
	 * Method that allows classes to register for PlayerKeyListener
	 * 
	 * @param listener is object of listener that will added to ListenerList
	 */
	public void addPlayerChangeStateListener(final PlayerChangeStateListener listener)
	{ 
		listenerList.add(PlayerChangeStateListener.class, listener); 
	}
	
	/**
	 * Method that allows classes to unregister for PlayerKeyListener
	 * 
	 * @param listener is object of listener that will be removed from ListenerList
	 */
	public void removePlayerChangeStateListener(final PlayerChangeStateListener listener) 
	{ 
		listenerList.remove(PlayerChangeStateListener.class, listener); 
	}	
	
	/**
	 * Method that fire defined PlayerMoveUpEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void firePlayerMoveUpEvent(final PlayerMoveUpEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==PlayerKeyListener.class) 
			{ 
				((PlayerKeyListener)listeners[i+1]).playerMoveUpEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
	
	/**
	 * Method that fire defined PlayerMoveDownEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void firePlayerMoveDownEvent(final PlayerMoveDownEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==PlayerKeyListener.class) 
			{ 
				((PlayerKeyListener)listeners[i+1]).playerMoveDownEventOccurred(event,blockingEventQueue);
			} 
		} 
	}
		
	/**
	 * Method that fire defined PlayerMoveLeftEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void firePlayerMoveLeftEvent(final PlayerMoveLeftEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==PlayerKeyListener.class) 
			{ 
				((PlayerKeyListener)listeners[i+1]).playerMoveLeftEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
	
	/**
	 * Method that fire defined PlayerMoveDownEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void firePlayerMoveRightEvent(final PlayerMoveRightEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==PlayerKeyListener.class) 
			{ 
				((PlayerKeyListener)listeners[i+1]).playerMoveRightEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
	
	
	/**
	 * Method that fire defined PlayerStopEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void firePlayerChangeStateEvent(final PlayerChangeStateEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 	
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==PlayerChangeStateListener.class) 
			{ 
				((PlayerChangeStateListener)listeners[i+1]).playerChangeStateEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
	
	/**
	 * Method that fire defined PlayerStopEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void firePlayerStopEvent(final PlayerStopEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==PlayerKeyListener.class) 
			{ 
				((PlayerKeyListener)listeners[i+1]).playerStopEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
	
	/**
	 * Method that fire defined PlayerPlantBombEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void firePlayerPlantBombEvent(final PlayerPlantBombEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==PlayerKeyListener.class) 
			{ 
				((PlayerKeyListener)listeners[i+1]).playerPlantBombEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
	
	/**
	 * @return the listenerList
	 */
	public EventListenerList getListenerList()
	{
		return listenerList;
	}

	/**
	 * @param listenerList the listenerList to set
	 */
	public void setListenerList(final EventListenerList listenerList)
	{
		this.listenerList = listenerList;
	}
	
	/**
	 * @return the blockingEventQueue
	 */
	public ArrayBlockingQueue<GameEvent> getBlockingEventQueue()
	{
		return blockingEventQueue;
	}

	/**
	 * @param blockingEventQueue the blockingEventQueue to set
	 */
	public void setBlockingEventQueue(
			ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.blockingEventQueue = blockingEventQueue;
	}
	
	/**
	 * @param moveHorizontalValue the moveHorizontalValue to set
	 */
	public void setMoveHorizontalValue(final int moveHorizontalValue)
	{
		this.moveHorizontalValue = moveHorizontalValue;
	}

	/**
	 * @return the moveHorizontalValue
	 */
	public int getMoveHorizontalValue()
	{
		return moveHorizontalValue;
	}

	/**
	 * @param moveVerticalValue the moveVerticalValue to set
	 */
	public void setMoveVerticalValue(final int moveVerticalValue)
	{
		this.moveVerticalValue = moveVerticalValue;
	}

	/**
	 * @return the moveVerticalValue
	 */
	public int getMoveVerticalValue()
	{
		return moveVerticalValue;
	}
}