import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.border.Border;

public class Evenement extends JFrame implements ActionListener {
    int op1; 
    int op2; 
    int op3; 
    int cp=0;
    String operateur; 
    String text2; 


 JButton buttonC = new JButton("C");
 JButton buttonegal = new JButton("=");
 JButton button0 = new JButton("0");
 JButton button1 = new JButton("1");
 JButton button2 = new JButton("2");
 JButton button3 = new JButton("3");
 JButton button4 = new JButton("4");
 JButton button5 = new JButton("5");
 JButton button6 = new JButton("6");
 JButton button7 = new JButton("7");
 JButton button8 = new JButton("8");
 JButton button9 = new JButton("9");
 JButton button01 = new JButton("*");
 JButton button02 = new JButton("/");
 JButton button03 = new JButton("+");
 JButton button04 = new JButton("-");
 JPanel panelbas0 = new JPanel();
 JPanel panelhaut = new JPanel();
 JPanel panelDroit = new JPanel(); 
 JTextField text = new JTextField(20);
 public Evenement() { 
    initUI(); 
 }
 public final void initUI() {
   panelhaut.add(text);

   panelbas0.setLayout(new GridLayout(4,3));
   panelbas0.add(button1);
   panelbas0.add(button2);
   panelbas0.add(button3);
   panelbas0.add(button4);
   panelbas0.add(button5);
   panelbas0.add(button6);
   panelbas0.add(button7);
   panelbas0.add(button8);
   panelbas0.add(button9);
   panelbas0.add(button0); 
   panelbas0.add(buttonegal); 
   panelbas0.add(buttonC); 

   panelDroit.setLayout(new GridLayout(4,1));
   panelDroit.add(button01);
   panelDroit.add(button02);
   panelDroit.add(button03);
   panelDroit.add(button04);



    
    add(panelhaut,BorderLayout.NORTH);
    add(panelbas0,BorderLayout.CENTER);
    add(panelDroit,BorderLayout.EAST);
    buttonC.addActionListener(this);
    button0.addActionListener(this);
    button1.addActionListener(this);
    button2.addActionListener(this);
    button3.addActionListener(this);
    button4.addActionListener(this);
    button5.addActionListener(this);
    button6.addActionListener(this);
    button7.addActionListener(this);
    button8.addActionListener(this);
    button9.addActionListener(this);
    button01.addActionListener(this);
    button02.addActionListener(this);
    button03.addActionListener(this);
    button04.addActionListener(this);
    buttonegal.addActionListener(this);
    setSize(300, 200);
    setLocationRelativeTo(null);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
 }
 
 public void actionPerformed(ActionEvent e) {

    if (e.getSource() == button1 )
    { 
        System.out.println("But 1!");
        String text0=text.getText();
        text.setText(text0+"1");
        if(cp!=0){
            text2+="1";
            System.out.println("text2 : "+text2);
            op2=Integer.parseInt(text2);
        }
        
       // panelbas0.setText("Clic: " + e.getActionCommand());
    }
    else if (e.getSource() == button2 )
    //(e.getActionCommand().equals("Button2"))
    { 
        System.out.println("But 2!");
       // panelbas0.setText("Clic: " + e.getActionCommand());
       String text0=text.getText();
        text.setText(text0+"2");
    } 
    else if (e.getSource() == button3 )
    { 
        System.out.println("But 3!");
        String text0=text.getText();
        text.setText(text0+"3");
    } 
    else if (e.getSource() == button4 )
    { 
        System.out.println("But 4!");
        String text0=text.getText();
        text.setText(text0+"4");
    } 
    else if (e.getSource() == button5 )
    { 
        System.out.println("But 5!");
        String text0=text.getText();
        text.setText(text0+"5");
    } 
    else if (e.getSource() == button6 )
    { 
        System.out.println("But 6!");
        String text0=text.getText();
        text.setText(text0+"6");
    } 
    else if (e.getSource() == button7 )
    { 
        System.out.println("But 7!");
        String text0=text.getText();
        text.setText(text0+"7");
    } 
    else if (e.getSource() == button8 )
    { 
        System.out.println("But 8!");
        String text0=text.getText();
        text.setText(text0+"8");
    } 
    else if (e.getSource() == button9 )
    { 
        System.out.println("But 9!");
        String text0=text.getText();
        text.setText(text0+"9");
    } 
    else if (e.getSource() == button0 )
    { 
        System.out.println("But 0!");
        String text0=text.getText();
        text.setText(text0+"0");
    }
    else if (e.getSource() == button01 )
    { 
        System.out.println("But *");
        String text0=text.getText();
        op1=Integer.parseInt(text0);
        text.setText(text0+" * ");
        System.out.println(op1);
        operateur="*"; 
        cp++;
       // panelbas0.setText("Clic: " + e.getActionCommand());
    }
    else if (e.getSource() == button02 )
    //(e.getActionCommand().equals("Button2"))
    { 
       
        System.out.println("But /");
       // panelbas0.setText("Clic: " + e.getActionCommand());
       String text0=text.getText();
       op1=Integer.parseInt(text0);
       text.setText(text0+" / ");
       System.out.println(op1);
       operateur="/";
       cp++;
    } 
    else if (e.getSource() == button03 )
    {   
        System.out.println("But +!");
        String text0=text.getText();
        
        op1=Integer.parseInt(text0);
        System.out.println(op1);
        text.setText(text0+" + ");
        operateur="+"; 
        cp++;
    } 
    else if (e.getSource() == button04 )
    { 
        System.out.println("But -");
        String text0=text.getText();
        op1=Integer.parseInt(text0);
        text.setText(text0+" - ");
        System.out.println(op1);
        operateur="-";
        cp++;
    } 
    else if (e.getSource()==buttonegal)
    { 
        System.out.println("But =");
        op2=Integer.parseInt(text2);
       // op2=Integer.parseInt(text2);
        System.out.println(" opérand 1 = "+op1);
        System.out.println(" opérand 2 = "+op2);

        System.out.println("operateur 2 = "+operateur);



    }
    else if (e.getSource() == buttonC )
    {   
        op1=0; 
        operateur=null; 
        System.out.println("But C !");
        String text0=text.getText();
        text0=null;
        text.setText(text0);
    }
 }
 public static void main(String[] args) {
    Evenement evt = new Evenement();
    evt.setVisible(true);
 } 
}
