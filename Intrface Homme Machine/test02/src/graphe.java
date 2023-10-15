
import javax.swing.*;
import java.awt.*;

public class graphe extends JFrame {
 public graphe() { super ("Exemple de dessin dans un JFrame");
  setSize(800, 800);
setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
setLocationRelativeTo (null); }
 public void dessin(Graphics g) {
    int i;
    for( i=0;i<=200;i=i+2){
        g.drawRect(100, 250, i, i);  
    }  
}
 public void paint(Graphics g) {
 super.paint(g); // paint existe dans JFrame
 dessin (g); }
 public static void main (String[] args) {
 new graphe().setVisible(true); }; }
