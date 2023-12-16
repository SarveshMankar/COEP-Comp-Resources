BEGIN{ 
    print "Enter a Number: " 
    getline n < "-"
}
{
    fact=1
    i=1
    while (i<=n) { 
        fact*=i
        i+=1
    }

    print "Factorial of "n" is = " fact
    
    exit 0
}