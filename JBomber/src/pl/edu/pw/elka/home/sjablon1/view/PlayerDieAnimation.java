package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Toolkit;

/**
 * Class represents die animation of main animating object in Game, the Player Animation. Player die
 * when had collision with Explosion made by Bomb.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PlayerDieAnimation extends Animation
{
	/**
	 * Default constructor of PlayerDieAnimation object.
	 * 
	 * @param playerSpriteScheetFileName name of file contains animation SpriteSheet
	 */
	public PlayerDieAnimation(final String playerSpriteScheetFileName)
	{	
        this.setBackground(Color.WHITE);
        this.setDoubleBuffered(true);
        this.setSize(680, 520);
        this.setOpaque(false);
        
		this.setAnimatingSprite(new Sprite(playerSpriteScheetFileName));
		this.getAnimatingSprite().setSpritePositionX(0);
		this.getAnimatingSprite().setSpritePositionY(160);
	}
	

	@Override
	/**
	 * Method defines what parameters change in each animationCycle. 
	 */
	public void animationCycle()
	{
		int newFrameX = this.getAnimatingSprite().getSpritePositionX();
		int newFrameY = this.getAnimatingSprite().getSpritePositionY();
		
		if(newFrameX == 0)
			newFrameX += 40;
		else if(newFrameX == 40)
			newFrameX +=40;
		else
			newFrameX = 0;
		
		this.getAnimatingSprite().setSpritePositionX(newFrameX);
		this.getAnimatingSprite().setSpritePositionY(newFrameY);
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
	 * Method that runs animation.
	 * @throws InterruptedException 
	 */
	public synchronized void runAnimation()
	{
	    while(this.isAnimationRolling())
	    {
	    	animationCycle();
	        repaint();
	    }
	}
}
