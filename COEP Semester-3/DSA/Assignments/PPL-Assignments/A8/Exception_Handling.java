class NegativeNumber extends Exception{
    public NegativeNumber(){
    }
}

class Exception_Handling{
    public static void main(String args[]){
        int a=10;
        int b=-8;

        try{
            int c=a/b;
            System.out.println("The value of c is: "+c);
            if (c<0){
                throw new NegativeNumber();
            }
        }
        catch(NegativeNumber ne){
            System.out.println("The value of c is negative");
        }
        catch(Exception e){
            System.out.println(e);
        }
        finally{
            System.out.println("This is the finally block");
        }
    }
}