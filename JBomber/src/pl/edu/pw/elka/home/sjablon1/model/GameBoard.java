package pl.edu.pw.elka.home.sjablon1.model;


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/**
 * Class represents the biggest part of GameSpace, GameBoard the arena on
 * which the game/fight took place. Information of GameBoard structure is required 
 * for construction a Graph. 
 * @author Szymon Jablonski
 * @version 1.0
 */

public class GameBoard
{
	/**Array contains gameBoard logical structure*/
	private Tile[][] boardStructure;
	/**Number represents GameBoard Model x dimension*/
	private int dimensionX;
	/**Number represents GameBoard Model x dimension*/
	private int dimensionY;
	/**Number of backgroundTiles in GameBoard*/
	private int backgroundTileNumber;
	/**Number of brickTiles in GameBoard*/
	private int brickTileNumber;
	/**Number of wallTiles in GameBoard*/
	private int wallTileNumber;
	
	/**
	 * Constructor of GameBoard class build by information from configuration file.
	 * 
	 * @param boardStructureFileName Name of configFileName witch has all information about GameSpace
	 * parameters
	 * @throws IOException when file input error occurred.
	 */
	public GameBoard(final String boardStructureFileName)
	{
		this.setBackgroundTileNumber(0);
		this.setBrickTileNumber(0);
		this.setWallTileNumber(0);

		try
		{			
			BufferedReader inputStream = new BufferedReader(new FileReader(boardStructureFileName));
			String boardStructureInfo;
			
			boardStructureInfo = inputStream.readLine();
			dimensionX = Integer.parseInt(boardStructureInfo);
			boardStructureInfo = inputStream.readLine();
			dimensionY = Integer.parseInt(boardStructureInfo);	
			
			boardStructure = new Tile[dimensionX][dimensionY];
			                                      
			for(int j=0; j<dimensionY; j++)
			{
				boardStructureInfo = inputStream.readLine();
				for(int i=0; i<dimensionX;i++)
				{
					if(boardStructureInfo.charAt(i) == '#')
					{
						boardStructure[i][j] = new WallTile();;
						wallTileNumber++;
					}
					else if(boardStructureInfo.charAt(i) == '?')
					{
						boardStructure[i][j] = new BrickTile();
						brickTileNumber++;
					}
					else if(boardStructureInfo.charAt(i) == '*')
					{
						boardStructure[i][j] = new BackgroundTile();
						backgroundTileNumber++;
					}
				}
			}
			inputStream.close(); 
		} 
		catch (IOException e)
		{
			System.err.println("File input error");
		}

	}
	
	/**
	 * @param boardStructure the boardStructure to set
	 */
	public void setBoardStructure(final Tile[][] boardStructure)
	{
		this.boardStructure = boardStructure;
	}
	
	/**
	 * @return the boardStructure
	 */
	public Tile[][] getBoardStructure()
	{
		return boardStructure;
	}
	
	/**
	 * @param dimensionX the dimensionX to set
	 */
	public void setDimensionX(final int dimensionX)
	{
		this.dimensionX = dimensionX;
	}
	
	/**
	 * @return the dimensionX
	 */
	public int getDimensionX()
	{
		return dimensionX;
	}
	
	/**
	 * @param dimensionY the dimensionY to set
	 */
	public void setDimensionY(final int dimensionY)
	{
		this.dimensionY = dimensionY;
	}
	
	/**
	 * @return the dimensionY
	 */
	public int getDimensionY()
	{
		return dimensionY;
	}
	
	/**
	 * @param backgroundTileNumber the backgroundTileNumber to set
	 */
	public void setBackgroundTileNumber(final int backgroundTileNumber)
	{
		this.backgroundTileNumber = backgroundTileNumber;
	}
	
	/**
	 * @return the backgroundTileNumber
	 */
	public int getBackgroundTileNumber()
	{
		return backgroundTileNumber;
	}
	
	/**
	 * @param brickTileNumber the brickTileNumber to set
	 */
	public void setBrickTileNumber(final int brickTileNumber)
	{
		this.brickTileNumber = brickTileNumber;
	}
	
	/**
	 * @return the brickTileNumber
	 */
	public int getBrickTileNumber()
	{
		return brickTileNumber;
	}
	
	/**
	 * @param wallTileNumber the wallTileNumber to set
	 */
	public void setWallTileNumber(final int wallTileNumber)
	{
		this.wallTileNumber = wallTileNumber;
	}
	
	/**
	 * @return the wallTileNumber
	 */
	public int getWallTileNumber()
	{
		return wallTileNumber;
	}

}
