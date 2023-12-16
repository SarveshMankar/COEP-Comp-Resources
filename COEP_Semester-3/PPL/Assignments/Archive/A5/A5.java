package A5;

interface Animal {
    public void eat();

    public void sleep();

    public void makeNoise();

    public void run();

}

class Dog implements Animal {
    private int legs = 4;
    private int eyes = 2;
    private int ears = 2;
    String color;

    Dog(String color) {
        this.color = color;
    }

    // Implementing functions
    public void makeNoise() {
        System.out.println("Dog is barking");
    }

    public void run() {
        System.out.println("Dog is running");
    }

    public void eat() {
        System.out.println("Dog is eating");
    }

    public void sleep() {
        System.out.println("Dog is sleeping");
    }

    // New function
    public void wagTail() {
        System.out.println("Dog is wagging tail");
    }

    public String getColor() {
        return color;
    }

    public int getEars() {
        return ears;
    }

    public int getEyes() {
        return eyes;
    }

    public int getLegs() {
        return legs;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void setEars(int ears) {
        this.ears = ears;
    }

    public void setEyes(int eyes) {
        this.eyes = eyes;
    }

    public void setLegs(int legs) {
        this.legs = legs;
    }

    public void printInfo() {
        System.out.println("Dog has " + legs + " legs, " + eyes + " eyes, " + ears + " ears and is " + color);
    }

}

class Cat implements Animal {

    public int legs = 4;
    public int eyes = 2;
    public int ears = 2;
    String color;

    Cat(String color) {
        this.color = color;
    }

    // Implementing functions
    public void makeNoise() {
        System.out.println("Cat is meowing");
    }

    public void run() {
        System.out.println("Cat is running");
    }

    public void eat() {
        System.out.println("Cat is eating");
    }

    public void sleep() {
        System.out.println("Cat is sleeping");
    }

    // New function
    public void wagTail() {
        System.out.println("Cat is wagging tail");
    }

    public void printInfo() {
        System.out.println("Cat has " + legs + " legs, " + eyes + " eyes, " + ears + " ears and is " + color);
    }

}

class Elephant implements Animal {

    public int legs = 4;
    public int eyes = 2;
    public int ears = 2;
    String color;

    Elephant(String color) {
        this.color = color;
    }

    // Implementing functions
    public void makeNoise() {
        System.out.println("Elephant is trumpeting");
    }

    public void run() {
        System.out.println("Elephant is running");
    }

    public void eat() {
        System.out.println("Elephant is eating");
    }

    public void sleep() {
        System.out.println("Elephant is sleeping");
    }

    // New function
    public void wagTail() {
        System.out.println("Elephant is wagging tail");
    }

    public void printInfo() {
        System.out.println("Elephant has " + legs + " legs, " + eyes + " eyes, " + ears + " ears and is " + color);
    }

}

public class A5 {
    public static void main(String[] args) {
        Dog tom = new Dog("Brown");
        Cat jerry = new Cat("White");
        Elephant dumbo = new Elephant("Gray");

        tom.printInfo();
        jerry.printInfo();
        dumbo.printInfo();
    }
}
