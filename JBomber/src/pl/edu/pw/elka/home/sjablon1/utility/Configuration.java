package pl.edu.pw.elka.home.sjablon1.utility;
/**
 * Class represents configuration of New Game, it contains all informations about player/enemy
 * number, GameBoard type, number of upgrades, audio options etc. It uses Singleton pattern,
 * the configuration is accessible from everywhere and there is only one instance of Configuration
 * object.  
 * @author Szymon Jablonski
 * @version 1.0
 */
public class Configuration
{
	/**Number of players in game.*/
	private int playerNumber;
	/**Number of enemies in game.*/
	private int enemyNumber;
	/**Name of image file that contains BackgroundTile image.*/
	private String backgroundTileFileName;
	/**Name of image file that contains BrickTile image.*/
	private String brickTileFileName;
	/**Name of image file that contains WallTile image.*/
	private String wallTileFileName;
	/**Name of file that contains GameBoard logic structure.*/
	private String boardStructureFileName;
	
	/**
	 * Default constructor of Configuration object.
	 */
	private Configuration()
	{
		this.setPlayerNumber(1);
		this.setEnemyNumber(1);
		this.setBackgroundTileFileName("backgroundTile.png");
		this.setBrickTileFileName("brickTile.png");
		this.setWallTileFileName("wallTile.png");
		this.setBoardStructureFileName("boardStructure.txt");
	}
	
	/**
	 * Static method that create Configuration object if there no one else. Use this
	 * method to access Configuration non-static methods.
	 * 
	 * @return reference to Configuration object.
	 */
	public static synchronized Configuration getInstance()
	{
		if (config == null)
			config = new Configuration();

		return config;
	}
	
	/**
	 * Methods of Configuration: set and get informations.
	 */
	public void doSomething()
	{
		System.out.println("singleton");
	}
	
	/**Static Configuration object instance used to allow to create only one instance of
	 * Configuration class.*/
	private static Configuration config;
	
	/**Parameters of Game Configuration. All information about: image file names, number of player/enemy
	 * possible upgrades etc. All information can be changed in Game Options*/
	
	/**
	 * @return the playerNumber
	 */
	public int getPlayerNumber()
	{
		return playerNumber;
	}

	/**
	 * @param playerNumber the playerNumber to set
	 */
	public void setPlayerNumber(final int playerNumber)
	{
		this.playerNumber = playerNumber;
	}

	/**
	 * @return the enemyNumber
	 */
	public int getEnemyNumber()
	{
		return enemyNumber;
	}

	/**
	 * @param enemyNumber the enemyNumber to set
	 */
	public void setEnemyNumber(final int enemyNumber)
	{
		this.enemyNumber = enemyNumber;
	}

	/**
	 * @return the backgroundTileFileName
	 */
	public String getBackgroundTileFileName()
	{
		return backgroundTileFileName;
	}

	/**
	 * @param backgroundTileFileName the backgroundTileFileName to set
	 */
	public void setBackgroundTileFileName(final String backgroundTileFileName)
	{
		this.backgroundTileFileName = backgroundTileFileName;
	}

	/**
	 * @return the brickTileFileName
	 */
	public String getBrickTileFileName()
	{
		return brickTileFileName;
	}

	/**
	 * @param brickTileFileName the brickTileFileName to set
	 */
	public void setBrickTileFileName(final String brickTileFileName)
	{
		this.brickTileFileName = brickTileFileName;
	}

	/**
	 * @return the wallTileFileName
	 */
	public String getWallTileFileName()
	{
		return wallTileFileName;
	}

	/**
	 * @param wallTileFileName the wallTileFileName to set
	 */
	public void setWallTileFileName(final String wallTileFileName)
	{
		this.wallTileFileName = wallTileFileName;
	}

	/**
	 * @return the boardStructureFileName
	 */
	public String getBoardStructureFileName()
	{
		return boardStructureFileName;
	}

	/**
	 * @param boardStructureFileName the boardStructureFileName to set
	 */
	public void setBoardStructureFileName(final String boardStructureFileName)
	{
		this.boardStructureFileName = boardStructureFileName;
	}
	
}
