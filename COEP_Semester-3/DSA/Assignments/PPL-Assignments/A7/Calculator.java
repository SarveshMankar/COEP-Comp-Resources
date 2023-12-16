import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculator implements ActionListener {


    double first, second, result;
    String operator;
    Frame frame;
    Button one, two, three, four, five, six, seven, eight, nine, zero, AC, add, sub, multiply, divide,
            equal, on, off, dot, sin, cos, tan, sqrt, cbrt, square, cube, pow, pie, log, exp;
    TextField screen;

    Calculator() {

        // Memory Initialisation using new Keyword
        frame = new Frame("Scientific Calculator");
        AC = new Button("AC");
        on = new Button("ON");
        off = new Button(("OFF"));
        zero = new Button("0");
        one = new Button("1");
        two = new Button("2");
        three = new Button("3");
        four = new Button("4");
        five = new Button("5");
        six = new Button("6");
        seven = new Button("7");
        eight = new Button("8");
        nine = new Button("9");
        add = new Button("+");
        sub = new Button("-");
        multiply = new Button("X");
        divide = new Button("÷");
        equal = new Button("=");
        dot = new Button(".");
        sin = new Button("Sin ");
        cos = new Button("Cos ");
        tan = new Button("Tan ");
        cbrt = new Button("³√x");
        sqrt = new Button("²√x");
        log = new Button("Log");
        exp = new Button("eˣ");
        square = new Button("x²");
        cube = new Button("x³");
        pow = new Button("xʸ");
        pie = new Button("π");
        screen = new TextField();


        // Font to button and textfield
        Font font1 = new Font("SansSerif", Font.PLAIN, 20);
        screen.setFont(font1);
        log.setFont(font1);
        AC.setFont(font1);
        one.setFont(font1);
        two.setFont(font1);
        three.setFont(font1);
        four.setFont(font1);
        five.setFont(font1);
        six.setFont(font1);
        seven.setFont(font1);
        eight.setFont(font1);
        nine.setFont(font1);
        zero.setFont(font1);
        add.setFont(font1);
        sub.setFont(font1);
        multiply.setFont(font1);
        divide.setFont(font1);
        equal.setFont(font1);
        on.setFont(font1);
        off.setFont(font1);
        dot.setFont(font1);
        sin.setFont(font1);
        cos.setFont(font1);
        tan.setFont(font1);
        sqrt.setFont(font1);
        cbrt.setFont(font1);
        square.setFont(font1);
        cube.setFont(font1);
        pow.setFont(font1);
        pie.setFont(font1);
        exp.setFont(font1);

        // Setting frame layout to Null
        frame.setLayout(null);

        // Set Bounds method fix the position of components on the frame
        // By default components are in the middle of the screen overlapping each other
        screen.setBounds(30, 40, 340, 80);
        on.setBounds(100, 130, 60, 60);
        off.setBounds(170, 130, 60, 60);
        AC.setBounds(30, 130, 60, 60);
        zero.setBounds(100, 410, 60, 60);
        one.setBounds(30, 340, 60, 60);
        two.setBounds(100, 340, 60, 60);
        three.setBounds(170, 340, 60, 60);
        four.setBounds(30, 270, 60, 60);
        five.setBounds(100, 270, 60, 60);
        six.setBounds(170, 270, 60, 60);
        seven.setBounds(30, 200, 60, 60);
        eight.setBounds(100, 200, 60, 60);
        nine.setBounds(170, 200, 60, 60);
        add.setBounds(240, 340, 60, 60);
        sub.setBounds(240, 270, 60, 60);
        multiply.setBounds(240, 200, 60, 60);
        divide.setBounds(240, 130, 60, 60);
        equal.setBounds(310, 480, 60, 60);
        dot.setBounds(170, 410, 60, 60);
        sin.setBounds(100, 480, 60, 60);
        cos.setBounds(170, 480, 60, 60);
        tan.setBounds(240, 480, 60, 60);
        sqrt.setBounds(30, 410, 60, 60);
        cbrt.setBounds(30, 480, 60, 60);
        log.setBounds(240, 410, 60, 60);
        exp.setBounds(310, 200, 60, 60);
        square.setBounds(310, 270, 60, 60);
        cube.setBounds(310, 340, 60, 60);
        pow.setBounds(310, 410, 60, 60);
        pie.setBounds(310, 130, 60, 60);

        // Adding Component on Frame
        frame.add(screen);
        frame.add(AC);
        frame.add(on);
        frame.add(off);
        frame.add(zero);
        frame.add(one);
        frame.add(two);
        frame.add(three);
        frame.add(four);
        frame.add(five);
        frame.add(six);
        frame.add(seven);
        frame.add(eight);
        frame.add(nine);
        frame.add(add);
        frame.add(sub);
        frame.add(multiply);
        frame.add(divide);
        frame.add(equal);
        frame.add(dot);
        frame.add(sin);
        frame.add(cos);
        frame.add(tan);
        frame.add(sqrt);
        frame.add(cbrt);
        frame.add(log);
        frame.add(exp);
        frame.add(pie);
        frame.add(square);
        frame.add(cube);
        frame.add(pow);

        // Adding on click ActionListener so that it will perform its function
        on.addActionListener(this);
        off.addActionListener(this);
        AC.addActionListener(this);
        zero.addActionListener(this);
        one.addActionListener(this);
        two.addActionListener(this);
        three.addActionListener(this);
        four.addActionListener(this);
        five.addActionListener(this);
        six.addActionListener(this);
        seven.addActionListener(this);
        eight.addActionListener(this);
        nine.addActionListener(this);
        add.addActionListener(this);
        sub.addActionListener(this);
        multiply.addActionListener(this);
        divide.addActionListener(this);
        equal.addActionListener(this);
        dot.addActionListener(this);
        sin.addActionListener(this);
        cos.addActionListener(this);
        tan.addActionListener(this);
        sqrt.addActionListener(this);
        cbrt.addActionListener(this);
        log.addActionListener(this);
        pow.addActionListener(this);
        exp.addActionListener(this);
        square.addActionListener(this);
        cube.addActionListener(this);
        pie.addActionListener(this);


        off.setEnabled(false);
        state(false);

        //By Default it is false
        frame.setVisible(true);
        
        //size of frame
        frame.setSize(400, 600);
    }

    public static void main(String[] args) {
        Calculator myClass = new Calculator();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String value = e.getActionCommand();
        switch (value) {
            case "ON":
                on.setEnabled(false);
                state(true);
                off.setEnabled(true);
                break;
            case "OFF":
                state(false);
                off.setEnabled(false);
                on.setEnabled(true);
                break;
            case "AC":
                screen.setText("");
                break;
            case "Sin ":
                operator = "sin";
                screen.setText("Sin ");
                break;
            case "Cos ":
                operator = "cos";
                screen.setText("Cos ");
                break;
            case "Tan ":
                operator = "tan";
                screen.setText("Tan ");
                break;
            case "³√x":
                operator = "cube root";
                screen.setText("Cube Root of(");
                break;
            case "²√x":
                operator = "square root";
                screen.setText("Square Root of(");
                break;
            case "+":
                first = Double.parseDouble(screen.getText());
                screen.setText("");
                operator = "+";
                break;
            case "-":
                first = Double.parseDouble(screen.getText());
                screen.setText("");
                operator = "-";
                break;
            case "X":
                first = Double.parseDouble(screen.getText());
                screen.setText("");
                operator = "*";
                break;
            case "÷":
                first = Double.parseDouble(screen.getText());
                screen.setText("");
                operator = "/";
                break;
            case "Log":
                screen.setText("Log(");
                operator = "log";
                break;
            case "eˣ":
                screen.setText("e^");
                operator = "exp";
                break;
            case "x²":
                first = Double.parseDouble(screen.getText());
                result = Math.pow(first, 2);
                screen.setText(Double.toString(result));

                break;
            case "x³":
                first = Double.parseDouble(screen.getText());
                result = Math.pow(first, 3);
                screen.setText(Double.toString(result));
                break;
            case "xʸ":
                first = Double.parseDouble(screen.getText());
                screen.setText("");
                operator = "pow";
                break;
            case "π":
                screen.setText("3.14");
                // operator = "pie";
                break;
            case "=":
                switch (operator) {
                    case "+":
                        second = Double.parseDouble(screen.getText());
                        result = first + second;
                        break;
                    case "-":
                        second = Double.parseDouble(screen.getText());
                        result = first - second;
                        break;
                    case "*":
                        second = Double.parseDouble(screen.getText());
                        result = first * second;
                        break;
                    case "/":
                        second = Double.parseDouble(screen.getText());
                        result = first / second;
                        break;
                    case "sin": {
                        second = Double.parseDouble(screen.getText().substring(4));
                        System.out.println(second);
                        double b = Math.toRadians(second);
                        result = Math.sin(b);
                        break;
                    }
                    case "cos": {
                        second = Double.parseDouble(screen.getText().substring(4));
                        double b = Math.toRadians(second);
                        result = Math.cos(b);
                        break;
                    }
                    case "tan": {
                        second = Double.parseDouble(screen.getText().substring(4));
                        double b = Math.toRadians(second);
                        result = Math.tan(b);
                        break;
                    }
                    case "cube root":
                        second = Double.parseDouble(screen.getText().substring(13));
                        result = Math.cbrt(second);
                        break;
                    case "square root":
                        second = Double.parseDouble(screen.getText().substring(15));
                        result = Math.sqrt(second);
                        break;
                    case "log":
                        second = Double.parseDouble(screen.getText().substring(4));
                        result = Math.log(second);
                        break;
                    case "exp":
                        second = Double.parseDouble(screen.getText().substring(2));
                        result = Math.pow(2.718, second);
                        break;
                    case "pow":
                        second = Double.parseDouble(screen.getText());
                        result = Math.pow(first, second);
                        break;
                }
                screen.setText(Double.toString(result));
                break;
            default:
                screen.setText(screen.getText() + value);
                break;
        }
    }

    public void state(boolean val) {
        screen.setText("");
        AC.setEnabled(val);
        multiply.setEnabled(val);
        zero.setEnabled(val);
        one.setEnabled(val);
        two.setEnabled(val);
        three.setEnabled(val);
        four.setEnabled(val);
        five.setEnabled(val);
        six.setEnabled(val);
        seven.setEnabled(val);
        eight.setEnabled(val);
        nine.setEnabled(val);
        add.setEnabled(val);
        sub.setEnabled(val);
        divide.setEnabled(val);
        equal.setEnabled(val);
        dot.setEnabled(val);
        sin.setEnabled(val);
        cos.setEnabled(val);
        tan.setEnabled(val);
        sqrt.setEnabled(val);
        cbrt.setEnabled(val);
        log.setEnabled(val);
        cube.setEnabled(val);
        square.setEnabled(val);
        pie.setEnabled(val);
        pow.setEnabled(val);
        exp.setEnabled(val);
    }

}