//
//  main.cpp
//  PRG-4-15-Shipping-Calculator
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  The Fast Freight Shipping Company charges the following rates:
//
//  Weight of Package(in Kilograms)             Rate per 500 Miles Shipped
//  ----------------------------------------------------------------------
//  2 kg or less                                $1.10
//  Over 2 kg but not more than 6 kg            $2.20
//  Over 6 kg but not more than 10 kg           $3.70
//  Over 10 kg but not more than 20 kg          $4.80
//
//  Write a program that asks for the weight of the package and the distance it is to be
//  shipped, then displays the chrages.
//
//  Input Validation: Do not accept values of 0 or less for the weight of the package. Do
//  not accept weights of more than 20 kg (this is the maximum weight the company will
//  ship). Do not accept distances of less than 10 miles or more than 3,000 miles. These
//  are the company's minimum and maximum shipping distances.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int intPackageDistance,
    intPackageWeight;
    
    int const INT_SHIPPING_DIVISOR = 500;
    
    float fltShippingCost;
    
    float const FLT_SHIPPING_WEIGHT_00 = 1.10f, //$1.10 per 500 miles
                FLT_SHIPPING_WEIGHT_01 = 2.20f, //$2.20 per 500 miles
                FLT_SHIPPING_WEIGHT_02 = 3.70f, //$3.70 per 500 miles
                FLT_SHIPPING_WEIGHT_03 = 4.80f; //$4.80 per 500 miles
    
    //Request package weight
    cout << "Please enter your package's weight:\n";
    cin >> intPackageWeight;
    //Catch invalid weights (min & max)
    while(!cin || intPackageWeight <= 0 || intPackageWeight > 20)
    {
        cout << "Please enter a package weight between 0 kg and 20 kg:\n";
        cin.clear();
        cin.ignore();
        cin >> intPackageWeight;
    }
    
    //Request distance to ship package
    cout << "Please enter the distance\n"
         << "you are shipping your package:\n";
    cin >> intPackageDistance;
    //Catch invalid package distances (min & max)
    while(!cin || intPackageDistance < 10 || intPackageDistance > 3000)
    {
        cout << "Please enter a distance between 10 miles and 3,000 miles:\n";
        cin.clear();
        cin.ignore();
        cin >> intPackageDistance;
    }
    
    //Calculate shipping costs based on package weight
    if(intPackageWeight <= 2)
    {
        //Math to calculate distance multiplier
        fltShippingCost = (((intPackageDistance - 1)/INT_SHIPPING_DIVISOR) + 1)
                            * FLT_SHIPPING_WEIGHT_00;
        cout << "Your shipping cost for a package of "
             << intPackageWeight << "kg\n"
             << "and a distance of " << intPackageDistance << "miles is:\n"
             << fltShippingCost;
    }
    else if(intPackageWeight >= 2 && intPackageWeight < 6)
    {
        fltShippingCost = (((intPackageDistance - 1)/INT_SHIPPING_DIVISOR) + 1)
                            * FLT_SHIPPING_WEIGHT_01;
        cout << "Your shipping cost for a package of "
             << intPackageWeight << "kg\n"
             << "and a distance of " << intPackageDistance << " miles is:\n"
             << fltShippingCost;
    }
    else if(intPackageWeight >= 6 && intPackageWeight < 10)
    {
        fltShippingCost = (((intPackageDistance - 1)/INT_SHIPPING_DIVISOR) + 1)
                            * FLT_SHIPPING_WEIGHT_02;
        cout << "Your shipping cost for a package of "
             << intPackageWeight << "kg\n"
             << "and a distance of " << intPackageDistance << "miles is:\n"
             << fltShippingCost;
    }
    else if(intPackageWeight >= 10 && intPackageWeight < 20)
    {
        fltShippingCost = (((intPackageDistance - 1)/INT_SHIPPING_DIVISOR) + 1)
                            * FLT_SHIPPING_WEIGHT_03;
        cout << "Your shipping cost for a package of "
             << intPackageWeight << "kg\n"
             << "and a distance of " << intPackageDistance << "miles is:\n"
             << "$" << setprecision(2) << fixed << fltShippingCost;
    }
    else
    {
        cout << "ERROR CALCULATING COSTS\n";
    }
    
    return 0;
}


