package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.Toolkit;

/**
 * Class represents View of Game Logo from Game Menu.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class LogoView extends TileView
{
	/**
	 * Constructor of LogoView object. The image of Game Logo is read from File
	 * 
	 * @param logoImageFileName is the name of Logo image file
	 * @param positionX is x position where MenuBomberView object will be painted 
	 * @param positionY is y position where MenuBomberView object will be painted
	 */
	public LogoView(final String logoImageFileName, final int positionX,final int positionY)
	{
		this.setTilePositionX(positionX);
		this.setTilePositionY(positionY);
		this.setTileImage(Toolkit.getDefaultToolkit().getImage(logoImageFileName));	
	}

}
