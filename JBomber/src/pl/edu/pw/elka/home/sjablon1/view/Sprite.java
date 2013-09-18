package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.Color;
import java.awt.Image;
import java.awt.MediaTracker;
import java.awt.Toolkit;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import javax.swing.JFrame;

/**
 * Class represents Animation Sprite. It is used to load, create, set Transparency color and store
 * images for every animation frame in Game. Each animated object has one sprite object. All animation frame
 * is loaded with one SpriteSheet image to avoid problem witch image loading synchronization.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class Sprite
{
	
	/**SpriteSheet image object*/
	private Image spriteSheet;
	/**Number of SpriteSheet rows*/
	private int rowsNumber;
	/**Number of SpriteSheet columns*/
	private int columnsNumber;
	/**Sprite width*/
	private final int spriteWidth = 40;
	/**Sprite height*/
	private final int spriteHeight = 40;
	/**Position X of currents displayed Sprite in SpriteSheet*/
	private int spritePositionX;
	/**Position Y of currents displayed Sprite in SpriteSheet*/
	private int spritePositionY;
	
	/**
	 * Default constructor of Sprite object.
	 * 
	 * @throws IOException when occurred error while loading SpriteSheet from File. 
	 */
	public Sprite(final String spriteFileName)
	{
	    MediaTracker mediaTracker = new MediaTracker(new JFrame("Media tracker"));
	    
		this.setSpriteSheet(Toolkit.getDefaultToolkit().getImage(spriteFileName));
		mediaTracker.addImage(this.getSpriteSheet(), 0);

	    try
	    {
	      mediaTracker.waitForID(0);
	    }
	    catch (InterruptedException e) 
	    {
	      System.out.println(e);
	    }

		try
		{
			BufferedImage bufferedSprite = ImageIO.read(new File(spriteFileName));
			this.setColumnsNumber(bufferedSprite.getWidth()/this.getSpriteWidth());
			this.setRowsNumber(bufferedSprite.getHeight()/this.getSpriteHeight());
			bufferedSprite = null;
		}
		catch(IOException e)
		{
			System.out.println("");
		}
		
		this.setSpriteSheet(Transparency.makeColorTransparent(this.getSpriteSheet(),new Color(255,20,247)));
		
	}
	
	/**
	 * @return the spriteSheet
	 */
	public Image getSpriteSheet()
	{
		return spriteSheet;
	}
	/**
	 * @param spriteSheet the spriteSheet to set
	 */
	public void setSpriteSheet(final Image spriteSheet)
	{
		this.spriteSheet = spriteSheet;
	}
	/**
	 * @return the rowsNumber
	 */
	public int getRowsNumber()
	{
		return rowsNumber;
	}
	/**
	 * @param rowsNumber the rowsNumber to set
	 */
	public void setRowsNumber(final int rowsNumber)
	{
		this.rowsNumber = rowsNumber;
	}
	/**
	 * @return the columnsNumber
	 */
	public int getColumnsNumber()
	{
		return columnsNumber;
	}
	/**
	 * @param columnsNumber the columnsNumber to set
	 */
	public void setColumnsNumber(final int columnsNumber)
	{
		this.columnsNumber = columnsNumber;
	}
	/**
	 * @return the spritePositionX
	 */
	public int getSpritePositionX()
	{
		return spritePositionX;
	}
	/**
	 * @param spritePositionX the spritePositionX to set
	 */
	public void setSpritePositionX(final int spritePositionX)
	{
		this.spritePositionX = spritePositionX;
	}
	/**
	 * @return the spritePositionY
	 */
	public int getSpritePositionY()
	{
		return spritePositionY;
	}
	/**
	 * @param spritePositionY the spritePositionY to set
	 */
	public void setSpritePositionY(final int spritePositionY)
	{
		this.spritePositionY = spritePositionY;
	}
	/**
	 * @return the spriteWidth
	 */
	public int getSpriteWidth()
	{
		return spriteWidth;
	}
	/**
	 * @return the spriteHight
	 */
	public int getSpriteHeight()
	{
		return spriteHeight;
	}
		
}
