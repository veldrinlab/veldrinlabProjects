package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.Color;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.concurrent.ArrayBlockingQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.BackToMenuEvent;


/**
 * Class represents CreditsView object where user can read information about makers of Game.
 * @author Szymon Jablonski
 * @version 1.0
 */

public class CreditsView extends JFrame implements ActionListener
{
	/**Object of button witch generate Event witch user is returned to Menu View*/
	private BackToMenuButton backToMenuButton;
	/**Blocking queue used to add occurred Events to communicate with Controller Unit */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;
	
	/**
	 * Default constructor of CreditsView object.
	 * 
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 */
	public CreditsView(ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		super("JBomber::Credits");
		JPanel buttonPanel = new JPanel();
		this.backToMenuButton = new BackToMenuButton();
		backToMenuButton.addActionListener(this);
		
		buttonPanel.add(backToMenuButton);
		buttonPanel.setBackground(Color.white);
		this.getContentPane().add(buttonPanel);
		
		this.setSize(680, 520);
		this.getContentPane().setBackground(Color.white);
		this.setArrayBlockingEventQueue(blockingEventQueue);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setResizable(false);
		setVisible(true);
		Insets insets = getInsets();
		setSize(680+insets.left+insets.right, 520+insets.top+insets.bottom);
	}

	@Override
	/**
	 * Method that serving occurred ActionEvent of BackToMenuButton. It fires BackToMenuEven
	 * and put it in BlockingQueuee to communicate with Controller unit. 
	 * 
	 * @param event is caught event by ActionListener added to BackToMenuButton.
	 */
	public void actionPerformed(final ActionEvent event)
	{
		backToMenuButton.fireBackToMenuEvent(new BackToMenuEvent(this), blockingEventQueue);
	}
	
	
	/**
	 * @param backToMenuButton the backToMenuButton to set
	 */
	public void setBackToMenuButton(final BackToMenuButton backToMenuButton)
	{
		this.backToMenuButton = backToMenuButton;
	}

	/**
	 * @return the backToMenuButton
	 */
	public BackToMenuButton getBackToMenuButton()
	{
		return backToMenuButton;
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
