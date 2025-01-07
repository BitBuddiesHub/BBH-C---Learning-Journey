#include <iostream>
using namespace std;
double func(double x)
{
    double tax = 0;
    x -= 1000;
    if (x > 0)
    {
        tax = x * 0.05;
        x -= 500;
        if (x > 0)
        {
            tax += x * 0.1;
            x -= 1500;
            if (x > 0)
            {
                tax += x * 0.15;
                x -= 3000;
                if (x > 0)
                {
                    tax += x * 0.2;
                    x -= 15000;
                    if (x > 0)
                    {
                        tax += x * 0.25;
                        x -= 20000;
                        if (x > 0)
                        {
                            tax += x * 0.3;
                            x -= 20000;
                            if (x > 0)
                            {
                                tax += x * 0.35;
                                x -= 20000;
                                if (x > 0)
                                {
                                    tax += x * 0.4;
                                    x -= 20000;
                                    if (x > 0)
                                    {
                                        tax += x * 0.45;
                                        return tax;
                                    }
                                }
                                else
                                {
                                    return tax;
                                }
                            }
                            else
                            {
                                return tax;
                            }
                        }
                        else
                        {
                            return tax;
                        }
                    }
                    else
                    {
                        return tax;
                    }
                }
                else
                {
                    return tax;
                }
            }
            else
            {
                return tax;
            }
        }
        else
        {
            return tax;
        }
    }
    else
    {
        return tax;
    }
}