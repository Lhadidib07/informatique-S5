import java.awt.*;

import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.plaf.PanelUI;

import java.awt.*; 

public class App extends JFrame {   
    public App(){ 
   /*  JFrame f = new JFrame(); 
     f.setTitle("salam");
     f.setSize(400,150);
     f.setLocationRelativeTo(null);
     f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
     f.setLayout(new BorderLayout());  
     f.add(new JButton("1"),BorderLayout.NORTH);
     f.add(new JButton("2"),BorderLayout.CENTER);
     f.add(new JButton("3"),BorderLayout.WEST);
     f.add(new JButton("4"),BorderLayout.EAST);
     f.add(new JButton("5"),BorderLayout.SOUTH);
     f.setVisible(true); */ 
    

    /*
     JFrame f = new JFrame(); 
     f.setTitle("salam");
     f.setSize(400,150);
     f.setLocationRelativeTo(null);
     f.setLayout(new FlowLayout());  
     f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
     Panel pgauch = new Panel(); 
     Panel pmilieux = new Panel(); 
     Panel pdroit = new Panel();
     // creation d'un tableaux sur le panel droit  
     pgauch.setLayout(new GridLayout(2,1));
     pgauch.add(new JCheckBox("Aligner le grille "));
     pgauch.add(new JCheckBox("montrer le grille "));
     // creation d'un tableaux sur le panel millieux  
     pmilieux.setLayout(new GridLayout(2,2));
     pmilieux.add(new JLabel(" X :"));
     pmilieux.add(new JTextField());   
     pmilieux.add(new JLabel(" Y :"));
     pmilieux.add(new JTextField());   
     // creation d'un tableaux sur le panel gauche
     pdroit.setLayout(new GridLayout(3,1));
     pdroit.add(new JButton(" OK")); 
     pdroit.add(new JButton("Annuler")); 
     pdroit.add(new JButton("Aide")); 
     f.add(pgauch);
     f.add(pmilieux);
     f.add(pdroit);

     f.pack();
     f.setVisible(true); 
    */

    JFrame f = new JFrame(); 
    f.setTitle("salam");
    f.setSize(400,200);
    f.setLocationRelativeTo(null);
    f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    f.setLayout(new BorderLayout());  
    Panel phaut = new Panel(); 
    Panel pbas = new Panel();
    // creation d'un tableaux sur le panel haut
    phaut.setLayout(new GridLayout(3,2));
    phaut.add(new JButton("(A)"));
    phaut.add(new JButton("(B)"));
    phaut.add(new JButton("(C)"));
    phaut.add(new JButton("(D)"));
    phaut.add(new JButton("(E)")); 
    phaut.add(new JLabel(""));
    f.add(new JSeparator(),BorderLayout.CENTER);
    f.add(phaut,BorderLayout.NORTH); 
    // jsparateur 
    pbas.setLayout(new GridLayout(2,3));
    pbas.add(new JLabel("Combo 1 (vide horizontal):"));
    pbas.add(new JLabel("Combo 2 ( vertical): "));
    pbas.add(new JLabel(""));
    f.add(new JSeparator(),BorderLayout.CENTER);
    pbas.add(new JComboBox<>());
    pbas.add(new JComboBox<>());
    pbas.add(new JButton("Appliquer vide ")); 
    f.add(pbas,BorderLayout.SOUTH); 
    f.setVisible(true); 
}
   
 
      
    public static void main(String[] args) throws Exception {
       new App(); 
    }
}
