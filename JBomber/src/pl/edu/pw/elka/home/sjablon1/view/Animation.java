package pl.edu.pw.elka.home.sjablon1.view;

import javax.swing.JPanel;

/**
 * Abstract class represents Animation in Game. Each animated object must extend Animation class. Animation
 * is defined by animating Sprite object  and position to paint Sprite.
 * @author Szymon Jablonski
 * @version 1.0
 */
public abstract class Animation extends JPanel
{
	/** Animating Sprite object */
	protected Sprite animatingSprite;
	/** Animation X Position */
	protected int xPosition;
	/** Animation Y Position */
	protected int yPosition;
	/** Animation rolling or it is stopped */
	protected boolean animationRolling;
	
	/**
	 * Method used to start animation.
	 */
	abstract public void startAnimation();
	/**
	 * Method defines what parameters change in each animationCycle.
	 */
	abstract public void animationCycle();
	/**
	 * Method used to stop animation.
	 */
	abstract public void stopAnimation();
	
	/**
	 * @return the animatingSprite
	 */
	public Sprite getAnimatingSprite()
	{
		return animatingSprite;
	}
	/**
	 * @param animatingSprite the animatingSprite to set
	 */
	public void setAnimatingSprite(final Sprite animatingSprite)
	{
		this.animatingSprite = animatingSprite;
	}

	/**
	 * @return the xPosition
	 */
	public int getxPosition()
	{
		return xPosition;
	}
	/**
	 * @param xPosition the xPosition to set
	 */
	public void setxPosition(final int xPosition)
	{
		this.xPosition = xPosition;
	}
	/**
	 * @return the yPosition
	 */
	public int getyPosition()
	{
		return yPosition;
	}
	/**
	 * @param yPosition the yPosition to set
	 */
	public void setyPosition(final int yPosition)
	{
		this.yPosition = yPosition;
	}
	/**
	 * @return the animationRolling
	 */
	public boolean isAnimationRolling()
	{
		return animationRolling;
	}
	/**
	 * @param animationRolling the animationRolling to set
	 */
	public void setAnimationRolling(final boolean animationRolling)
	{
		this.animationRolling = animationRolling;
	}	
}
