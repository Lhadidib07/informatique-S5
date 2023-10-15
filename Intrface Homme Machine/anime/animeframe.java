import javax.swing.*;
import java.awt.*;
public class animeframe extends JFrame implements Runnable {
    private int x=150, y=150, r=5, d=1, dt=100 ;
    private final int MAX_DIM=40;
    private Thread anim;
    public animeframe() {
        super("Drawing Demo dans un Frame");
        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        anim = new Thread(this);
        anim.start();
    }
    public void paint (Graphics g) {
        super.paint(g);
        g.fillOval (x, y, 2*r, 2*r) ;
    }
    public void run () { // corps du thread d'animation
        for (int i=0; i < 10000; i++) {
            if (r>MAX_DIM || r<1) { d *= -1; }
            r += d;
            try { Thread.sleep (dt);}
            catch (InterruptedException e) {}
            repaint () ; 
        }
    }
    public static void main(String[] args) {
        new animeframe().setVisible(true);
    };
}
