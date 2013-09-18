package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.MediaTracker;
import java.awt.Toolkit;
import java.io.IOException;

/**
 * Class represents part of GameBoardView graphics the BackgroundTileView graphics.
 * It defines what graphics type of image BackgroundTile is and paint it. 
 * @author Szymon Jablonski
 * @version 1.0
 */
public class BackgroundTileView extends TileView
{
	
	/**
	 * Default constructor of BackgroundTileView object.
	 * 
	 * @throws IOException when occurred error while loading image from File. 
	 */
	public BackgroundTileView()
	{
		this.setTileHeight(40);
		this.setTileWidth(40);
        this.setDoubleBuffered(true);
        this.setSize(680, 520);
        this.setOpaque(false);
        
		MediaTracker mediaTracker = new MediaTracker(this);
		this.setTileImage(Toolkit.getDefaultToolkit().getImage("backgroundTile.png"));	
		mediaTracker.addImage(this.getTileImage(), 0);
		
	    try
	    {
	      mediaTracker.waitForID(0);
	    }
	    catch (InterruptedException e) 
	    {
	      System.out.println(e);
	    }
	}

	/**
	 * Constructor of BrickTileView object. Each Tile have 40 pixel height and width.
	 * The image of Tile is read from File
	 * 
	 * @param backgroundTileName is the name of backgroundTile image file
	 * @throws IOException when occurred error while loading image from File.
	 */
	public BackgroundTileView(final String backgroundTileName)
	{
		this.setTileHeight(40);
		this.setTileWidth(40);
		
		MediaTracker mediaTracker = new MediaTracker(this);
		this.setTileImage(Toolkit.getDefaultToolkit().getImage(backgroundTileName));	
		mediaTracker.addImage(this.getTileImage(), 0);
		
	    try
	    {
	      mediaTracker.waitForID(0);
	    }
	    catch (InterruptedException e) 
	    {
	      System.out.println(e);
	    }	
	}

}