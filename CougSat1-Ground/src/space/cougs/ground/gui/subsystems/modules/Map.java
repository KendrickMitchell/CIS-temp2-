package space.cougs.ground.gui.subsystems.modules;

import java.awt.Dimension;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Insets;
import java.awt.RenderingHints;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.BorderFactory;
import javax.swing.JComponent;

import space.cougs.ground.gui.UIScaling;
import space.cougs.ground.gui.utils.CustomColors;
import space.cougs.ground.gui.utils.Fonts;

public class Map extends JComponent implements UIScaling {

	private static final long serialVersionUID = 1L;

	private BufferedImage map = null;
	private double longitude;
	private double latitude;
	private int diameter = 6;
	private final double aspectRatio;
	private String longitudeText = String.format("%11.6f\u00B0 E", 0.0);
	private String latitudeText = String.format("%10.6f\u00B0 N", 0.0);

	public Map(double lattitude, double longitude, Double aspectRatio) {

		super();
		this.latitude = lattitude;
		this.longitude = longitude;
		longitudeText = String.format("%11.6f\u00B0 E", this.longitude);
		latitudeText = String.format("%11.6f\u00B0 E", this.latitude);

		this.setForeground(CustomColors.TEXT1);
		this.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));

		try {
			map = ImageIO.read(new File("resources/images/map.jpg"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		if (aspectRatio == null) {
			this.aspectRatio = map.getWidth() / (double) map.getHeight();
		} else {
			this.aspectRatio = aspectRatio;
		}
	}

	@Override
	public Dimension getPreferredSize() {

		FontMetrics fontMetrics = this.getFontMetrics(this.getFont());

		Insets insets = this.getBorder().getBorderInsets(this);
		
		int width = fontMetrics.stringWidth(longitudeText) * 2 + insets.left + insets.right;
		int height = (width - fontMetrics.getHeight()) / 2 + insets.top + insets.bottom;

		return new Dimension(width, height);
	}

	@Override
	public Dimension getMinimumSize() {

		FontMetrics fontMetrics = this.getFontMetrics(this.getFont());
		Insets insets = this.getBorder().getBorderInsets(this);

		int width = fontMetrics.stringWidth(longitudeText) * 2 + insets.left + insets.right;
		int height = (width - fontMetrics.getHeight()) / 2 + insets.top + insets.bottom;

		return new Dimension(width, height);

	}

	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		Graphics2D g2d = (Graphics2D) g;

		FontMetrics fontMetrics = this.getFontMetrics(this.getFont());
		g2d.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, RenderingHints.VALUE_TEXT_ANTIALIAS_ON);
		Insets insets = this.getBorder().getBorderInsets(this);

		int x1 = insets.left;
		int x2 = this.getWidth() - insets.right;
		int y1 = insets.top;
		int y2 = this.getHeight() - insets.bottom - fontMetrics.getHeight();
		y2 = (int) Math.min(y2, (x2 - x1) / aspectRatio);
		int newWidth = (int) (y2 * aspectRatio);

		x1 = (this.getWidth() / 2) - (newWidth / 2);
		x2 = x1 + newWidth;

		if (map != null) {
			g2d.drawImage(map, x1, y1, x2, y2, 0, 0, map.getWidth(), map.getHeight(), null);
		} else {
			g2d.fillRect(0, 0, getWidth(), getHeight());
			String Error = "Error: Map Image Not Found";
			g2d.drawString(Error, getWidth() / 2 - fontMetrics.stringWidth(Error) / 2,
					getHeight() / 2 - fontMetrics.getAscent() / 2);
		}

		int x = insets.left;
		int y = y2 + fontMetrics.getAscent();

		g2d.drawString(latitudeText, x1 - insets.left, y);

		x = this.getWidth() / 2;

		g2d.drawString(longitudeText, x2 - fontMetrics.stringWidth(longitudeText), y);

		x = (int) ((longitude + 180.0) / 360.0 * (x2 - x1) + insets.left);
		y = (int) ((-latitude + 90.0) / 180 * (y2 - y1) + insets.top);

		g2d.fillOval(x1 + x - diameter / 2, y - diameter / 2, diameter, diameter);
	}

	public void setValue(double lattitude, double longitude) {

		this.longitude = longitude;
		this.latitude = lattitude;
	}

	@Override
	public void updateUIScaling(UIScale uiScale) {
		this.setFont(Fonts.BODY_16);

		switch (uiScale) {
		case SCALE_100:
			this.setFont(Fonts.BODY_16);
			this.diameter = 6;
			break;
		case SCALE_150:
			this.setFont(Fonts.BODY_24);
			this.diameter = 8;
			break;
		case SCALE_200:
			this.setFont(Fonts.BODY_32);
			this.diameter = 12;
			break;
		case SCALE_300:
			this.setFont(Fonts.BODY_48);
			this.diameter = 18;
			break;
		case SCALE_75:
			this.setFont(Fonts.BODY_12);
			this.diameter = 4;
			break;
		default:
			break;
		}
	}
}