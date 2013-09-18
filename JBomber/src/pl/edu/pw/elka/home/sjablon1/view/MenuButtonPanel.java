package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.concurrent.ArrayBlockingQueue;
import javax.swing.BoxLayout;
import javax.swing.JPanel;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.CreditsEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.ExitGameEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.NewGameEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.OptionsEvent;



/**
 * Class represents panel with four control buttons that generate Events:
 * NewGameButton, OptionsButton, CreditsButton and ExitGameButton.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class MenuButtonPanel extends JPanel implements ActionListener
{
	
	/**Object of NewGameButton from MenuButtonPanel*/
	private NewGameButton newGameButton;
	/**Object of ExitGameeButton from MenuButtonPanel*/
	private ExitGameButton exitGameButton;
	/**Object of OptionsButton from MenuButtonPanel*/
	private OptionsButton optionsButton;
	/**Object of CreditsButton from MenuButtonPanel*/
	private CreditsButton creditsButton;
	/**Blocking queue used to add occurred Events to communicate with Controller Unit */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;
	
	/**
	 * Default constructor of MenuButtonPanel object.
	 * 
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 */
	public MenuButtonPanel(ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		super();
		BoxLayout menuPanelLayout = new BoxLayout(this,BoxLayout.Y_AXIS);
		this.setLayout(menuPanelLayout);
		this.setBounds(280, 250, 0, 0);

		this.newGameButton = new NewGameButton();	
		this.exitGameButton = new ExitGameButton();
		this.optionsButton	= new OptionsButton();
		this.creditsButton = new CreditsButton();
		this.add(newGameButton);
		this.add(exitGameButton);
		this.add(creditsButton);
		this.add(optionsButton);
		this.setArrayBlockingEventQueue(blockingEventQueue);
		
		newGameButton.addActionListener(this);
		exitGameButton.addActionListener(this);
	}
	
	@Override
	/**
	 * Method that serving occurred ActionEvents of MenuButtons. It fires another Event like
	 * NewGameEvent and put it in BlockingQueuee to communicate with Controller unit. 
	 * 
	 * @param event is caught event by ActionListener added to MenuButtons.
	 */
	public void actionPerformed(final ActionEvent event)
	{
		if(event.getSource() instanceof NewGameButton)
		{
			newGameButton.fireNewGameEvent(new NewGameEvent(this),blockingEventQueue);
		}

		else if(event.getSource() instanceof CreditsButton)
		{
			creditsButton.fireCreditsEvent(new CreditsEvent(this),blockingEventQueue);
		}
		
		else if(event.getSource() instanceof OptionsButton)
		{
			optionsButton.fireOptionsEvent(new OptionsEvent(this),blockingEventQueue);
		}
		
		else if(event.getSource() instanceof ExitGameButton)
		{
			exitGameButton.fireExitGameEvent(new ExitGameEvent(this),blockingEventQueue);
		}
	}

	
	/**
	 * @return the newGameButton
	 */
	public NewGameButton getNewGameButton()
	{
		return newGameButton;
	}

	/**
	 * @param newGameButton the newGameButton to set
	 */
	public void setNewGameButton(final NewGameButton newGameButton)
	{
		this.newGameButton = newGameButton;
	}

	/**
	 * @return the exitGameButton
	 */
	public ExitGameButton getExitGameButton()
	{
		return exitGameButton;
	}

	/**
	 * @param exitGameButton the exitGameButton to set
	 */
	public void setExitGameButton(final ExitGameButton exitGameButton)
	{
		this.exitGameButton = exitGameButton;
	}

	/**
	 * @return the optionsButton
	 */
	public OptionsButton getOptionsButton()
	{
		return optionsButton;
	}

	/**
	 * @param optionsButton the optionsButton to set
	 */
	public void setOptionsButton(final OptionsButton optionsButton)
	{
		this.optionsButton = optionsButton;
	}

	/**
	 * @return the creditsButton
	 */
	public CreditsButton getCreditsButton()
	{
		return creditsButton;
	}

	/**
	 * @param creditsButton the creditsButton to set
	 */
	public void setCreditsButton(final CreditsButton creditsButton)
	{
		this.creditsButton = creditsButton;
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
	public void setArrayBlockingEventQueue(ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.blockingEventQueue = blockingEventQueue;
	}
	
}
