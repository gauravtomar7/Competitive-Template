int gcd(int a, int b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}

12)18                    //a = 12
    6)12                 //b = 12
      0)6
