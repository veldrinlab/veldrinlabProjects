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
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyChangeStateEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyChangeStateListener;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyKeyListener;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyMoveDownEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyMoveLeftEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyMoveRightEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyMoveUpEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyPlantBombEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyStopEvent;



/**
 * Class represents main animating object in Game, the Enemy Animation. Enemy can move on 
 * GameBoard, plant Bombs, take PowerUps and die after collision with explosion. With each of this
 * action Enemy object generate own Events. User can control Enemy with keyboard.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class EnemyMoveAnimation extends Animation
{	
	
	/** List of objects listeners*/
	private EventListenerList listenerList;
	/** Blocking queue used to add occurred Events to communicate with Controller Unit */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;
	/** Defines if Enemy is moving Up, Down, Left or Right */
	private int moveHorizontalValue;
	/** Defines if Enemy is moving Up, Down, Left or Right */
	private int moveVerticalValue;
	
	/**
	 * Default constructor of EnemyMoveAnimation object.
	 * 
	 * @param enemySpriteScheetFileName name of file contains animation SpriteSheet
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 */
	public EnemyMoveAnimation(final String enemySpriteScheetFileName,ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
        this.setBackground(Color.WHITE);
        this.setDoubleBuffered(true);
        this.setSize(680, 520);
        this.setOpaque(false);
        
		this.setAnimatingSprite(new Sprite(enemySpriteScheetFileName));
		this.getAnimatingSprite().setSpritePositionX(40);
		this.getAnimatingSprite().setSpritePositionY(0);
		this.setxPosition(600);
		this.setyPosition(440);
		
		this.setBlockingEventQueue(blockingEventQueue);
		this.setListenerList(new EventListenerList());
		this.addEnemyKeyListener(new EnemyKeyListener());
		this.addEnemyChangeStateListener(new EnemyChangeStateListener());
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
    
	@Override
	/**
	 * Method defines what parameters change in each animationCycle. 
	 */
	public void animationCycle()
	{		
		/** Change of animationCycle is defined by occurred events */
		this.fireEnemyChangeStateEvent(new EnemyChangeStateEvent(this), blockingEventQueue);
		
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

	/**
	 * Method that animate Sprite.
	 */
	public void runAnimation()
	{
		animationCycle();
		repaint();	    
	}
	
	/**
	 * Method that allows classes to register for EnemyKeyListener
	 * 
	 * @param listener is object of listener that will added to ListenerList
	 */
	public void addEnemyKeyListener(final EnemyKeyListener listener)
	{ 
		listenerList.add(EnemyKeyListener.class, listener); 
	}
	
	/**
	 * Method that allows classes to unregister for EnemyKeyListener
	 * 
	 * @param listener is object of listener that will be removed from ListenerList
	 */
	public void removeEnemyKeyListener(final EnemyKeyListener listener) 
	{ 
		listenerList.remove(EnemyKeyListener.class, listener); 
	}
	
	/**
	 * Method that allows classes to register for EnemyKeyListener
	 * 
	 * @param listener is object of listener that will added to ListenerList
	 */
	public void addEnemyChangeStateListener(final EnemyChangeStateListener listener)
	{ 
		listenerList.add(EnemyChangeStateListener.class, listener); 
	}
	
	/**
	 * Method that allows classes to unregister for EnemyKeyListener
	 * 
	 * @param listener is object of listener that will be removed from ListenerList
	 */
	public void removeEnemyChangeStateListener(final EnemyChangeStateListener listener) 
	{ 
		listenerList.remove(EnemyChangeStateListener.class, listener); 
	}	
	
	/**
	 * Method that fire defined EnemyMoveUpEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void fireEnemyMoveUpEvent(final EnemyMoveUpEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==EnemyKeyListener.class) 
			{ 
				((EnemyKeyListener)listeners[i+1]).enemyMoveUpEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
	
	/**
	 * Method that fire defined EnemyMoveDownEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void fireEnemyMoveDownEvent(EnemyMoveDownEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==EnemyKeyListener.class) 
			{ 
				((EnemyKeyListener)listeners[i+1]).enemyMoveDownEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
		
	/**
	 * Method that fire defined EnemyMoveLeftEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void fireEnemyMoveLeftEvent(EnemyMoveLeftEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==EnemyKeyListener.class) 
			{ 
				((EnemyKeyListener)listeners[i+1]).enemyMoveLeftEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
	
	/**
	 * Method that fire defined EnemyMoveDownEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void fireEnemyMoveRightEvent(EnemyMoveRightEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==EnemyKeyListener.class) 
			{ 
				((EnemyKeyListener)listeners[i+1]).enemyMoveRightEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
	
	
	/**
	 * Method that fire defined EnemyStopEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void fireEnemyChangeStateEvent(EnemyChangeStateEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 	
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==EnemyChangeStateListener.class) 
			{ 
				((EnemyChangeStateListener)listeners[i+1]).enemyChangeStateEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
	
	/**
	 * Method that fire defined EnemyStopEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void fireEnemyStopEvent(EnemyStopEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==EnemyKeyListener.class) 
			{ 
				((EnemyKeyListener)listeners[i+1]).enemyStopEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
	
	/**
	 * Method that fire defined EnemyPlantBombEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void fireEnemyPlantBombEvent(EnemyPlantBombEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==EnemyKeyListener.class) 
			{ 
				((EnemyKeyListener)listeners[i+1]).enemyPlantBombEventOccurred(event,blockingEventQueue); 
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
	public void setListenerList(EventListenerList listenerList)
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
	public void setMoveHorizontalValue(int moveHorizontalValue)
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
	public void setMoveVerticalValue(int moveVerticalValue)
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