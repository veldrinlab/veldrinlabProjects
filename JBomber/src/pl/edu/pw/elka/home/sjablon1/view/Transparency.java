package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.Color;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.image.FilteredImageSource;
import java.awt.image.ImageFilter;
import java.awt.image.ImageProducer;
import java.awt.image.RGBImageFilter;

/**
 * Class represents static method with witch we can set loaded Image color Transparency
 * to for example not paint background color of image.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class Transparency
{
	/**
	 * Static method that set transparency on loaded image.
	 * 
	 * @param image on which we set transparency.
	 * @param color that we want to be transparent color.
	 * @return image with transparency effect.
	 */
	public static Image makeColorTransparent(Image image, final Color color)
	{
	    ImageFilter filter = new RGBImageFilter()
	    {
	      public int markerRGB = color.getRGB() | 0xFF000000;

	      public final int filterRGB(int x, int y, int rgb) 
	      {
	        if ( ( rgb | 0xFF000000 ) == markerRGB )
	        	return 0x00FFFFFF & rgb;
	        else
	        	return rgb;
	      }
	    }; 

	    ImageProducer ip = new FilteredImageSource(image.getSource(), filter);
	    return Toolkit.getDefaultToolkit().createImage(ip);
	}
}